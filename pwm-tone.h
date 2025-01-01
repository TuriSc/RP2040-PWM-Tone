/**
 * @file pwm-tone.h
 * @brief PWM Tone generation library for Raspberry Pi Pico.
 * Plays melodies and chirping sounds via PWM through a buzzer or speaker.
 * @author Turi Scandurra
 * @see https://turiscandurra.com/circuits
 */

#ifndef PWM_TONE_H
#define PWM_TONE_H

#include <pico/stdlib.h>
#include "pitches.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @struct note_t
 * @brief Represents a musical note.
 */
typedef struct note_t {
    float freq; /**< Frequency of the note (in Hz). */
    int8_t measure; /**< Measure of the note (in subdivisions of a whole note). */
} note_t;

/**
 * @struct melody_t
 * @brief Represents a musical melody.
 */
typedef struct melody_t {     
    bool playing; /**< Flag indicating whether the melody is playing. */
    note_t * notes; /**< Array of notes in the melody. */
} melody_t;

/**
 * @struct tonegenerator_t
 * @brief Represents a tone generator.
 */
typedef struct tonegenerator_t {
    bool playing; /**< Flag indicating whether the tone generator is playing. */
    uint8_t gpio; /**< GPIO pin number for the tone generator. */
    uint8_t slice; /**< PWM slice number for the tone generator. */
    uint8_t channel; /**< PWM channel number for the tone generator. */
    melody_t mel; /**< Melody being played by the tone generator. */
} tonegenerator_t;

/**
 * @brief Initializes the tone generator.
 * @param gen Pointer to the tone generator structure.
 * @param gpio GPIO pin number for the tone generator.
 */
void tone_init(tonegenerator_t *gen, uint8_t gpio);

/**
 * @brief Plays a single tone.
 * @param gen Pointer to the tone generator structure.
 * @param freq Frequency of the tone (in Hz).
 * @param duration Duration of the tone (in ms).
 */
void tone(tonegenerator_t *gen, int freq, uint16_t duration);

/**
 * @brief Plays a melody.
 * @param gen Pointer to the tone generator structure.
 * @param notes Array of notes to play.
 * @param repeat Number of times to repeat the melody.
 */
void melody(tonegenerator_t *gen, note_t *notes, int8_t repeat);

/**
 * @brief Sets the tempo (in bpm).
 * @param bpm Tempo value (in bpm).
 */
void set_tempo(uint16_t bpm);

/**
 * @brief Sets the rest duration (in ms).
 * @param duration Rest duration value (in ms).
 */
void set_rest_duration(uint16_t duration);

/**
 * @brief Stops the current tone.
 * @param gen Pointer to the tone generator structure.
 */
void stop_tone(tonegenerator_t *gen);

/**
 * @brief Stops the current melody.
 * @param gen Pointer to the tone generator structure.
 */
void stop_melody(tonegenerator_t *gen);

/**
 * @brief Sets the PWM frequency.
 * @param gen Pointer to the tone generator structure.
 * @param freq Frequency value (in Hz).
 */
void _pwm_set_freq(tonegenerator_t *gen, float freq);

/**
 * @brief Turns on the PWM tone.
 * @param gen Pointer to the tone generator structure.
 * @param freq Frequency value (in Hz).
 */
void _tone_pwm_on(tonegenerator_t *gen, int freq);

/**
 * @brief Steps through the melody.
 * @param gen Pointer to the tone generator structure.
 */
void _melody_step(tonegenerator_t *gen);

/**
 * @brief Plays a single note in the melody.
 * @param gen Pointer to the tone generator structure.
 * @param freq Frequency of the note (in Hz).
 * @param duration Duration of the note (in ms).
 */
void _melody_tone(tonegenerator_t *gen, int freq, uint16_t duration);

/**
 * @brief Callback for the the tone playback.
 * @param id Alarm ID.
 * @param user_data Pointer to the tone generator structure.
 * @return 0 on success.
 */
static int64_t _tone_complete(alarm_id_t id, void *user_data);

/**
 * @brief Callback for the melody note playback.
 * @param id Alarm ID.
 * @param user_data Pointer to the tone generator structure.
 * @return 0 on success.
 */
static int64_t _melody_note_complete(alarm_id_t id, void *user_data);

/**
 * @brief Callback for the rest period.
 * @param id Alarm ID.
 * @param user_data Pointer to the tone generator structure.
 * @return 0 on success.
 */
static int64_t _rest_complete(alarm_id_t id, void *user_data);

#ifdef __cplusplus
}
#endif

#endif // PWM_TONE_H

