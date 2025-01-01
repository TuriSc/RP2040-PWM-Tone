/**
 * @file pwm-tone.c
 * @brief PWM Tone generation library for Raspberry Pi Pico.
 * Plays melodies and chirping sounds via PWM through a buzzer or speaker.
 * @author Turi Scandurra
 * @see https://turiscandurra.com/circuits
 */

#include "pwm-tone.h"
#include "hardware/pwm.h"
#include "hardware/clocks.h"
#include <stdlib.h>

/**
 * @brief Alarm IDs for tone, melody, and rest.
 */
static alarm_id_t tone_a;
static alarm_id_t melody_a;
static alarm_id_t rest_a;

/**
 * @brief System clock frequency.
 */
static uint32_t clock;

/**
 * @brief Melody repeat counter.
 */
static uint16_t melody_repeat;

/**
 * @brief Current melody index.
 */
static uint16_t melody_index;

/**
 * @brief Default rest duration (10ms).
 */
static uint16_t rest_duration = 10;

/**
 * @brief Default tempo (120bpm).
 */
static uint16_t tempo = 120;

/**
 * @brief Initializes the tone generator.
 * @param gen Pointer to the tone generator structure.
 * @param gpio GPIO pin number for the tone generator.
 */
void tone_init(tonegenerator_t *gen, uint8_t gpio){
    gen->gpio = gpio;
    gen->slice = pwm_gpio_to_slice_num(gpio);
    gen->channel = pwm_gpio_to_channel(gpio);
    gpio_init(gpio);
    gpio_set_function(gpio, GPIO_FUNC_PWM);
    pwm_set_chan_level(gen->slice, gen->channel, 2048);
    clock = clock_get_hz(clk_sys);
}

/**
 * @brief Plays a single tone.
 * @param gen Pointer to the tone generator structure.
 * @param freq Frequency of the tone (in Hz).
 * @param duration Duration of the tone (in ms).
 */
void tone(tonegenerator_t *gen, int freq, uint16_t duration) {
    if(freq != REST){
        _tone_pwm_on(gen, freq);
        if (tone_a) cancel_alarm(tone_a);
        tone_a = add_alarm_in_ms(duration, _tone_complete, gen, true);
    }
}

/**
 * @brief Plays a melody.
 * @param gen Pointer to the tone generator structure.
 * @param notes Array of notes to play.
 * @param repeat Number of times to repeat the melody.
 */
void melody(tonegenerator_t *gen, note_t *notes, int8_t repeat){
    melody_repeat = repeat;
    melody_index = 0;
    melody_t mel;
    mel.notes = notes;
    gen->mel = mel;
    gen->playing = true;
    _melody_step(gen);
}

/**
 * @brief Sets the tempo (in bpm).
 * @param bpm Tempo value (in bpm).
 */
void set_tempo(uint16_t bpm){
    tempo = bpm;
}

/**
 * @brief Sets the rest duration (in ms).
 * @param duration Rest duration value (in ms).
 */
void set_rest_duration(uint16_t duration){
    rest_duration = duration;
}

/**
 * @brief Stops the current tone.
 * @param gen Pointer to the tone generator structure.
 */
void stop_tone(tonegenerator_t *gen){
    pwm_set_enabled(gen->slice, false);
    gen->playing = false;
}

/**
 * @brief Stops the current melody.
 * @param gen Pointer to the tone generator structure.
 */
void stop_melody(tonegenerator_t *gen){
    if (tone_a) cancel_alarm(tone_a);
    if (melody_a) cancel_alarm(melody_a);
    pwm_set_enabled(gen->slice, false);
}

/**
 * @brief Sets the PWM frequency.
 * @param gen Pointer to the tone generator structure.
 * @param freq Frequency value (in Hz).
 */
void _pwm_set_freq(tonegenerator_t *gen, float freq) {
    float divider = (float) clock / (freq * 10000.0);
    pwm_set_clkdiv(gen->slice, divider);
    pwm_set_wrap(gen->slice, 10000);
    pwm_set_gpio_level(gen->gpio, 5000);
}

/**
 * @brief Turns on the PWM tone.
 * @param gen Pointer to the tone generator structure.
 * @param freq Frequency value (in Hz).
 */
void _tone_pwm_on(tonegenerator_t *gen, int freq){
    if(freq < NOTE_G1) {freq = REST;}
    else if(freq > NOTE_FS9) {freq = REST;}
    pwm_set_enabled(gen->slice, false);
    _pwm_set_freq(gen, freq);
    pwm_set_enabled(gen->slice, true);
    gen->playing = true;
}

/**
 * @brief Steps through the melody.
 * @param gen Pointer to the tone generator structure.
 */
void _melody_step(tonegenerator_t *gen){
    melody_t mel = gen->mel;
    note_t note = mel.notes[melody_index];

    if (note.freq == MELODY_END){
        melody_index = 0;
        if(melody_repeat > 0){
            melody_repeat--;
        }
        if(melody_repeat != 0){
            _melody_step(gen);
        } else {
            gen->playing = false;
        }
        
    } else {
        int8_t measure = note.measure;
        int whole_note = (60000 * 4) / tempo;
        int duration = whole_note / abs(measure);
        if (measure < 0) { // Dotted note
            duration *= 1.5;
        }
        _melody_tone(gen, note.freq, duration);
        melody_index++;
    }
}

/**
 * @brief Plays a single note in the melody.
 * @param gen Pointer to the tone generator structure.
 * @param freq Frequency of the note (in Hz).
 * @param duration Duration of the note (in ms).
 */
void _melody_tone(tonegenerator_t *gen, int freq, uint16_t duration) {
    if(freq != REST){ _tone_pwm_on(gen, freq); }
    if (melody_a) cancel_alarm(melody_a);
    melody_a = add_alarm_in_ms(duration, _melody_note_complete, gen, true);
}

/**
 * @brief Callback for the tone playback.
 * @param id Alarm ID.
 * @param user_data Pointer to the tone generator structure.
 * @return 0 on success.
 */
static int64_t _tone_complete(alarm_id_t id, void *user_data) {
    tonegenerator_t *gen = (tonegenerator_t*) user_data;
    pwm_set_enabled(gen->slice, false);
    gen->playing = false;
    return 0;
}

/**
 * @brief Callback for the melody note playback.
 * @param id Alarm ID.
 * @param user_data Pointer to the tone generator structure.
 * @return 0 on success.
 */
static int64_t _melody_note_complete(alarm_id_t id, void *user_data) {
    tonegenerator_t *gen = (tonegenerator_t*) user_data;
    pwm_set_enabled(gen->slice, false);

    if(rest_duration > 0){
        if (rest_a) cancel_alarm(rest_a);
        rest_a = add_alarm_in_ms(rest_duration, _rest_complete, user_data, true);
    } else {
        _melody_step(user_data);
    }
    return 0;
}

/**
 * @brief Callback for the rest period.
 * @param id Alarm ID.
 * @param user_data Pointer to the tone generator structure.
 * @return 0 on success.
 */
static int64_t _rest_complete(alarm_id_t id, void *user_data) {
    _melody_step(user_data);
    return 0;
}

