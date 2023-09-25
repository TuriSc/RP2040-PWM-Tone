# RP2040-PWM Tone
Tone generation library for Raspberry Pi Pico. Plays melodies and chirping sounds via PWM through a buzzer or speaker.

### Usage
```c
#include "pwm-tone.h"   // Include the library

// Pin definitions
#define PIEZO_PIN       0 // The pin the buzzer or speaker is connected to.
                        // The other terminal of the buzzer is connected to ground.

// Create an instance of the tone generator
struct tonegenerator_t generator;

int main() {

    // Initialize the tone generator, assigning it the output pin
    tone_init(&generator, PIEZO_PIN);

    // Play a single tone for 200ms.
    tone(&generator, NOTE_A4, 200);
}
```

An example application is provided.

### Available functions
```c
void tone_init(struct tonegenerator_t* gen, uint8_t gpio);
void tone(struct tonegenerator_t* gen, int freq, uint16_t duration);
void melody(struct tonegenerator_t* gen, struct note_t *notes, int8_t repeat);

void set_tempo(uint16_t bpm);
void set_rest_duration(uint16_t duration);
void stop_tone(struct tonegenerator_t* gen);
void stop_melody(struct tonegenerator_t* gen);
```

### Melody structure
Each data point defines a pitch (float, in Hz) and a duration (expressed in subdivisions of a whole note). This means that a duration of 16 (a sixteenth of a whole note) is half a duration of 8. Negative values represent dotted notation, so that -8 = 8 + (8/2) = 12. This data structure is inspired by the work at https://github.com/robsoncouto/arduino-songs/

```c
    struct note_t HAPPY_BIRTHDAY[] = {
        {NOTE_C4, 4},
        {NOTE_C4, 8}, 
        {NOTE_D4, -4},
        {NOTE_C4, -4},
        {NOTE_F4, -4},
        {NOTE_E4, -2},
        {REST, 8},

        {MELODY_END, 0}, // Melody end code. Necessary to trigger repeats
    };
```

In addition to pitch definitions (G1 to F#9), a conversion array that maps midi note numbers to pitches is available:
```c
float pitch = midi_to_pitch[midi_note_number];
```

A small number of original sound effects are included:
- ALARM_1
- ALARM_2
- ALARM_3
- CONFIRM
- DANGER
- VICTORY
- DEFEAT
- ERROR
- REJECT
- COIN
- EXPLOSION
- FANFARE
- LASER
- POWERUP
- SWEEP
- POSITIVE
- NEGATIVE
- RINGTONE_1
- RINGTONE_2
- RINGTONE_3

The library also includes a sample melody:
- HAPPY_BIRTHDAY

### Version history
- 2023.09.25 - v1.0.0 - First release