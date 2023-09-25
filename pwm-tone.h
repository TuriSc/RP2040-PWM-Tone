/*
 * RP2040 PWM Tone
 * Tone generation library for Raspberry Pi Pico. Plays melodies
 * and chirping sounds via PWM through a buzzer or speaker.
 * By Turi Scandurra – https://turiscandurra.com/circuits
 * v1.0.0 - 2023.09.25
*/

#ifndef PWM_TONE_H
#define PWM_TONE_H

#include <pico/stdlib.h>
#include "pitches.h"

struct note_t {
    float freq;
    int8_t measure;
};

struct melody_t {                
    struct note_t * notes;
};

struct tonegenerator_t {
    uint8_t gpio;
    uint8_t slice;
    uint8_t channel;
    struct melody_t mel;
};

void tone_init(struct tonegenerator_t* gen, uint8_t gpio);
void tone(struct tonegenerator_t* gen, int freq, uint16_t duration);
void melody(struct tonegenerator_t* gen, struct note_t *notes, int8_t repeat);

void set_tempo(uint16_t bpm);
void set_rest_duration(uint16_t duration);
void stop_tone(struct tonegenerator_t* gen);
void stop_melody(struct tonegenerator_t* gen);

void _pwm_set_freq(struct tonegenerator_t* gen, float freq);
void _tone_pwm_on(struct tonegenerator_t* gen, int freq);
void _melody_step(struct tonegenerator_t* gen);
void _melody_tone(struct tonegenerator_t* gen, int freq, uint16_t duration);

static int64_t _tone_complete(alarm_id_t id, void *user_data);
static int64_t _melody_note_complete(alarm_id_t id, void *user_data);
static int64_t _rest_complete(alarm_id_t id, void *user_data);

#endif // PWM_TONE_H
