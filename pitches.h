// Pitch of all chromatic notes between C-1 and G9.
// Turi Scandurra 2023

#ifndef TONE_PITCHES_H
#define TONE_PITCHES_H

#define NOTE_CM1    8.176
#define NOTE_CSM1   8.662
#define NOTE_DM1    9.177
#define NOTE_DSM1   9.723
#define NOTE_EM1    10.301
#define NOTE_FM1    10.913
#define NOTE_FSM1   11.562
#define NOTE_GM1    12.250
#define NOTE_GSM1   12.978
#define NOTE_AM1    13.750
#define NOTE_ASM1   14.568
#define NOTE_BM1    15.434
#define NOTE_C0     16.352
#define NOTE_CS0    17.324
#define NOTE_D0     18.354
#define NOTE_DS0    19.445
#define NOTE_E0     20.602
#define NOTE_F0     21.827
#define NOTE_FS0    23.125
#define NOTE_G0     24.500
#define NOTE_GS0    25.957
#define NOTE_A0     27.500
#define NOTE_AS0    29.135
#define NOTE_B0     30.868
#define NOTE_C1     32.703
#define NOTE_CS1    34.648
#define NOTE_D1     36.708
#define NOTE_DS1    38.891
#define NOTE_E1     41.203
#define NOTE_F1     43.654
#define NOTE_FS1    46.249 // Pitches lower than G1 can't be played by _pwm_set_freq()
#define NOTE_G1     49.000
#define NOTE_GS1    51.913
#define NOTE_A1     55.000
#define NOTE_AS1    58.271
#define NOTE_B1     61.735
#define NOTE_C2     65.406
#define NOTE_CS2    69.296
#define NOTE_D2     73.416
#define NOTE_DS2    77.782
#define NOTE_E2     82.407
#define NOTE_F2     87.307
#define NOTE_FS2    92.499
#define NOTE_G2     97.999
#define NOTE_GS2    103.826
#define NOTE_A2     110.000
#define NOTE_AS2    116.541
#define NOTE_B2     123.471
#define NOTE_C3     130.813
#define NOTE_CS3    138.591
#define NOTE_D3     146.832
#define NOTE_DS3    155.563
#define NOTE_E3     164.814
#define NOTE_F3     174.614
#define NOTE_FS3    184.997
#define NOTE_G3     195.998
#define NOTE_GS3    207.652
#define NOTE_A3     220.000
#define NOTE_AS3    233.082
#define NOTE_B3     246.942
#define NOTE_C4     261.626
#define NOTE_CS4    277.183
#define NOTE_D4     293.665
#define NOTE_DS4    311.127
#define NOTE_E4     329.628
#define NOTE_F4     349.228
#define NOTE_FS4    369.994
#define NOTE_G4     391.995
#define NOTE_GS4    415.305
#define NOTE_A4     440.000
#define NOTE_AS4    466.164
#define NOTE_B4     493.883
#define NOTE_C5     523.251
#define NOTE_CS5    554.365
#define NOTE_D5     587.330
#define NOTE_DS5    622.254
#define NOTE_E5     659.255
#define NOTE_F5     698.456
#define NOTE_FS5    739.989
#define NOTE_G5     783.991
#define NOTE_GS5    830.609
#define NOTE_A5     880.000
#define NOTE_AS5    932.328
#define NOTE_B5     987.767
#define NOTE_C6     1046.502
#define NOTE_CS6    1108.731
#define NOTE_D6     1174.659
#define NOTE_DS6    1244.508
#define NOTE_E6     1318.510
#define NOTE_F6     1396.913
#define NOTE_FS6    1479.978
#define NOTE_G6     1567.982
#define NOTE_GS6    1661.219
#define NOTE_A6     1760.000
#define NOTE_AS6    1864.655
#define NOTE_B6     1975.533
#define NOTE_C7     2093.005
#define NOTE_CS7    2217.461
#define NOTE_D7     2349.318
#define NOTE_DS7    2489.016
#define NOTE_E7     2637.020
#define NOTE_F7     2793.826
#define NOTE_FS7    2959.955
#define NOTE_G7     3135.963
#define NOTE_GS7    3322.438
#define NOTE_A7     3520.000
#define NOTE_AS7    3729.310
#define NOTE_B7     3951.066
#define NOTE_C8     4186.009
#define NOTE_CS8    4434.922
#define NOTE_D8     4698.636
#define NOTE_DS8    4978.032
#define NOTE_E8     5274.041
#define NOTE_F8     5587.652
#define NOTE_FS8    5919.911
#define NOTE_G8     6271.927
#define NOTE_GS8    6644.875
#define NOTE_A8     7040.000
#define NOTE_AS8    7458.620
#define NOTE_B8     7902.133
#define NOTE_C9     8372.018
#define NOTE_CS9    8869.844
#define NOTE_D9     9397.273
#define NOTE_DS9    9956.063
#define NOTE_E9     10548.082
#define NOTE_F9     11175.303
#define NOTE_FS9    11839.822
#define NOTE_G9     12543.854 // Pitches higher than FS9 can't be played by _pwm_set_freq()
#define REST        0.0
#define MELODY_END  -1.0

// Array matching midi notes to pitch values
static const int midi_to_pitch[128] = {
    NOTE_CM1, NOTE_CSM1, NOTE_DM1, NOTE_DSM1, NOTE_EM1, NOTE_FM1, NOTE_FSM1, NOTE_GM1, NOTE_GSM1, NOTE_AM1, NOTE_ASM1, NOTE_BM1,
    NOTE_C0, NOTE_CS0, NOTE_D0, NOTE_DS0, NOTE_E0, NOTE_F0, NOTE_FS0, NOTE_G0, NOTE_GS0, NOTE_A0, NOTE_AS0, NOTE_B0,
    NOTE_C1, NOTE_CS1, NOTE_D1, NOTE_DS1, NOTE_E1, NOTE_F1, NOTE_FS1, NOTE_G1, NOTE_GS1, NOTE_A1, NOTE_AS1, NOTE_B1,
    NOTE_C2, NOTE_CS2, NOTE_D2, NOTE_DS2, NOTE_E2, NOTE_F2, NOTE_FS2, NOTE_G2, NOTE_GS2, NOTE_A2, NOTE_AS2, NOTE_B2,
    NOTE_C3, NOTE_CS3, NOTE_D3, NOTE_DS3, NOTE_E3, NOTE_F3, NOTE_FS3, NOTE_G3, NOTE_GS3, NOTE_A3, NOTE_AS3, NOTE_B3,
    NOTE_C4, NOTE_CS4, NOTE_D4, NOTE_DS4, NOTE_E4, NOTE_F4, NOTE_FS4, NOTE_G4, NOTE_GS4, NOTE_A4, NOTE_AS4, NOTE_B4,
    NOTE_C5, NOTE_CS5, NOTE_D5, NOTE_DS5, NOTE_E5, NOTE_F5, NOTE_FS5, NOTE_G5, NOTE_GS5, NOTE_A5, NOTE_AS5, NOTE_B5,
    NOTE_C6, NOTE_CS6, NOTE_D6, NOTE_DS6, NOTE_E6, NOTE_F6, NOTE_FS6, NOTE_G6, NOTE_GS6, NOTE_A6, NOTE_AS6, NOTE_B6,
    NOTE_C7, NOTE_CS7, NOTE_D7, NOTE_DS7, NOTE_E7, NOTE_F7, NOTE_FS7, NOTE_G7, NOTE_GS7, NOTE_A7, NOTE_AS7, NOTE_B7,
    NOTE_C8, NOTE_CS8, NOTE_D8, NOTE_DS8, NOTE_E8, NOTE_F8, NOTE_FS8, NOTE_G8, NOTE_GS8, NOTE_A8, NOTE_AS8, NOTE_B8,
    NOTE_C9, NOTE_CS9, NOTE_D9, NOTE_DS9, NOTE_E9, NOTE_F9, NOTE_FS9, NOTE_G9
};

#endif // TONE_PITCHES_H