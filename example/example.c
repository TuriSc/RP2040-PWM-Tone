/*
 * RP2040 PWM Tone example
 *
 * By Turi Scandurra – https://turiscandurra.com/circuits
*/

#include <stdio.h>
#include <pico/stdlib.h>
#include "pwm-tone.h"   // Include the library
#include "melodies.h"   // Optional, but ideal location to store custom melodies

// Pin definitions
#define PIEZO_PIN       0 // The pin the buzzer or speaker is connected to.
                          // The other terminal of the buzzer is connected to ground.

// Create an instance of the tone generator
struct tonegenerator_t generator;

int main() {
    stdio_init_all();

    // Initialize the tone generator, assigning it the output pin
    tone_init(&generator, PIEZO_PIN);

    // Play a single tone for 200ms.
    // Notes are defined in the file pitches.h
    tone(&generator, NOTE_A4, 200);

    // Let's wait before calling the following functions,
    // because melody() and tone() are non-blocking.
    sleep_ms(700);

    // Play one of the preset melodies. The last parameter is the number
    // of repetitions. Set it to -1 to repeat the melody continuosly.
    melody(&generator, RINGTONE_1, 3);
    sleep_ms(3000);

    // Play a longer melody
    melody(&generator, HAPPY_BIRTHDAY, 0);

    // Let's delay further instuctions for longer while the melody plays.
    sleep_ms(20000); // 20 seconds

    // Change the duration of silence between notes. The default is 10ms.
    set_rest_duration(0);

    // Use this function to speed up or down your melodies.
    // Default tempo is 120bpm. Tempo does not affect tone().
    set_tempo(160);

    // This is an example sound effect. Each note defines a pitch (float, in Hz)
    // and a duration (expressed in subdivisions of a whole note). This means that
    // a duration of 16 is half a duration of 8. Negative values represent dotted notation,
    // so that -8 = 8 + (8/2) = 12. This data structure is inspired by the work at
    // https://github.com/robsoncouto/arduino-songs/
    struct note_t sfx[] = {
        {NOTE_C4, 16},
        {NOTE_C5, 32},
        {NOTE_C6, 64},
        {REST, 8}, // Pause at the end to space out repeats of the melody
        {MELODY_END, 0}, // Melody end code. Necessary to trigger repeats
    };

    // Let's play the sfx we just defined, repeating it twice
    melody(&generator, sfx, 2);

    while (true) {
        tight_loop_contents(); // Nothing to do here
    }
}
