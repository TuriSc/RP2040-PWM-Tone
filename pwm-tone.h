/*
 * RP2040 PWM Tone
 * Tone generation library for Raspberry Pi Pico. Plays melodies
 * and chirping sounds via PWM through a buzzer or speaker.
 * By Turi Scandurra – https://turiscandurra.com/circuits
*/

#ifndef PWM_TONE_H
#define PWM_TONE_H

#include <pico/stdlib.h>
#include "pitches.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct note_t {
    float freq;
    int8_t measure;
} note_t;

typedef struct melody_t {     
    bool playing;           
    struct note_t * notes;
} melody_t;

typedef struct tonegenerator_t {
    bool playing;
    uint8_t gpio;
    uint8_t slice;
    uint8_t channel;
    struct melody_t mel;
} tonegenerator_t;

void tone_init(tonegenerator_t *gen, uint8_t gpio);
void tone(tonegenerator_t *gen, int freq, uint16_t duration);
void melody(tonegenerator_t *gen, note_t *notes, int8_t repeat);

void set_tempo(uint16_t bpm);
void set_rest_duration(uint16_t duration);
void stop_tone(tonegenerator_t *gen);
void stop_melody(tonegenerator_t *gen);

void _pwm_set_freq(tonegenerator_t *gen, float freq);
void _tone_pwm_on(tonegenerator_t *gen, int freq);
void _melody_step(tonegenerator_t *gen);
void _melody_tone(tonegenerator_t *gen, int freq, uint16_t duration);

static int64_t _tone_complete(alarm_id_t id, void *user_data);
static int64_t _melody_note_complete(alarm_id_t id, void *user_data);
static int64_t _rest_complete(alarm_id_t id, void *user_data);

#ifdef __cplusplus
}
#endif

#endif // PWM_TONE_H
