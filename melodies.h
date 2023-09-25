#ifndef TONE_MELODIES_H
#define TONE_MELODIES_H

struct note_t POSITIVE[] = {
    {NOTE_C4, 16},
    {NOTE_AS4, 16},
    {NOTE_C5, 16},        
    {REST, 8},
    {MELODY_END, 0},
};

struct note_t NEGATIVE[] = {
    {NOTE_C5, 16},
    {NOTE_AS4, 16},
    {NOTE_C4, 16},        
    {REST, 8},
    {MELODY_END, 0},
};

struct note_t ERROR[] = {
    {NOTE_C6, 32},
    {REST, 64},
    {NOTE_C6, 32},
    {REST, 64},
    {NOTE_C4, 32},
    {REST, 64},
    {NOTE_C4, 32},
    {REST, 64},
    {REST, 8},
    {MELODY_END, 0},
};

struct note_t CONFIRM[] = {
    {NOTE_C7, 128},
    {REST, 128},
    {NOTE_C7, 128},
    {REST, 128},
    {NOTE_C7, 128},
    {REST, 128},
    {NOTE_C7, 128},
    {REST, 128},
    {REST, 8},
    {MELODY_END, 0},
};

struct note_t REJECT[] = {
    {NOTE_CM1, 128},
    {REST, 128},
    {NOTE_CM1, 128},
    {REST, 128},
    {NOTE_CM1, 128},
    {REST, 128},
    {NOTE_CM1, 128},
    {REST, 128},
    {REST, 8},
    {MELODY_END, 0},
};

struct note_t SWEEP[] = {
    {NOTE_CM1, 128},
    {NOTE_C0, 128},
    {NOTE_C1, 128},
    {NOTE_C2, 128},
    {NOTE_C3, 128},
    {NOTE_C4, 128},
    {NOTE_C5, 128},
    {NOTE_C6, 128},
    {NOTE_C7, 128},
    {NOTE_C8, 128},
    {NOTE_C9, 128},
    {REST, 8},
    {MELODY_END, 0},
};

struct note_t COIN[] = {
    {NOTE_C6, 16},
    {NOTE_C7, 4},
    {REST, 8},
    {MELODY_END, 0},
};

struct note_t LASER[] = {
    {NOTE_C8, 128},
    {NOTE_C7, 128},
    {NOTE_C6, 128},
    {NOTE_C5, 128},
    {NOTE_C4, 128},
    {REST, 8},
    {MELODY_END, 0},
};

struct note_t POWERUP[] = {
    {NOTE_C5, 128},
    {NOTE_CS5, 128},
    {NOTE_D5, 128},
    {NOTE_DS5, 128},
    {NOTE_E5, 128},
    {NOTE_F5, 128},
    {NOTE_FS5, 128},
    {NOTE_G5, 128},
    {REST, 8},
    {MELODY_END, 0},
};

struct note_t VICTORY[] = {
    {NOTE_G4, 8},
    {NOTE_G4, 16},
    {NOTE_G4, 16},
    {NOTE_D5, 4},
    {REST, 8},
    {MELODY_END, 0},
};

struct note_t DEFEAT[] = {
    {NOTE_C4, 16},
    {NOTE_AS3, 16},
    {NOTE_G3, 16},
    {NOTE_E3, 16},
    {NOTE_C3, 16},
    {REST, 8},
    {MELODY_END, 0},
};

struct note_t FANFARE[] = {
    {NOTE_C4, -4},
    {NOTE_E4, 8},
    {NOTE_G4, 8},
    {NOTE_C5, 2},
    {REST, 8},
    {MELODY_END, 0},
};

struct note_t ALARM_1[] = {
    {NOTE_C7, 8},
    {NOTE_A6, 8},
    {REST, 4},
    {MELODY_END, 0},
};

struct note_t ALARM_2[] = {
    {NOTE_C8, 8},
    {REST, 32},
    {NOTE_C8, 8},
    {REST, 4},
    {MELODY_END, 0},
};

struct note_t ALARM_3[] = {
    {NOTE_C7, 32},
    {REST, -32},
    {NOTE_C7, 32},
    {REST, -32},
    {NOTE_C7, 32},
    {REST, -32},
    {NOTE_C7, 32},
    {REST, -32},
    {REST, 4},
    {MELODY_END, 0},
};

struct note_t RINGTONE_1[] = {
    {NOTE_A7, 64},
    {NOTE_A6, 64},
    {NOTE_A7, 64},
    {NOTE_A6, 64},
    {NOTE_A7, 64},
    {NOTE_A6, 64},
    {NOTE_A7, 64},
    {NOTE_A6, 64},
    {NOTE_A7, 64},
    {NOTE_A6, 64},
    {NOTE_A7, 64},
    {NOTE_A6, 64},
    {NOTE_A7, 64},
    {NOTE_A6, 64},
    {NOTE_A7, 64},
    {NOTE_A6, 64},
    {MELODY_END, 0},
};

struct note_t RINGTONE_2[] = {
    {NOTE_D7, 128},
    {NOTE_E6, 128},
    {NOTE_D7, 128},
    {NOTE_E6, 128},
    {NOTE_D7, 128},
    {NOTE_E6, 128},
    {NOTE_D7, 128},
    {NOTE_E6, 128},
    {NOTE_D7, 128},
    {NOTE_E6, 128},
    {NOTE_D7, 128},
    {NOTE_E6, 128},
    {NOTE_D7, 128},
    {NOTE_E6, 128},
    {NOTE_D7, 128},
    {NOTE_E6, 128},
    {MELODY_END, 0},
};

struct note_t RINGTONE_3[] = {
    {NOTE_E8, 128},
    {NOTE_C8, 128},
    {NOTE_E8, 128},
    {NOTE_C8, 128},
    {NOTE_E8, 128},
    {NOTE_C8, 128},
    {NOTE_E8, 128},
    {NOTE_C8, 128},
    {NOTE_E8, 128},
    {NOTE_C8, 128},
    {NOTE_E8, 128},
    {NOTE_C8, 128},
    {NOTE_E8, 128},
    {NOTE_C8, 128},
    {NOTE_E8, 128},
    {NOTE_C8, 128},
    {MELODY_END, 0},
};

struct note_t DANGER[] = {
    {NOTE_FS5, 8},
    {REST, -8},
    {NOTE_FS5, 8},
    {REST, -8},
    {NOTE_FS5, 8},
    {REST, -8},
    {NOTE_FS5, 8},
    {REST, -8},
    {MELODY_END, 0},
};


struct note_t EXPLOSION[] = {
    {NOTE_G9, 128},
    {NOTE_E9, 128},
    {NOTE_C9, 128},
    {NOTE_G8, 128},
    {NOTE_E8, 128},
    {NOTE_C8, 128},
    {NOTE_G7, 128},
    {NOTE_E7, 128},
    {NOTE_C7, 128},
    {NOTE_G6, 128},
    {NOTE_E6, 128},
    {NOTE_C6, 128},
    {NOTE_G5, 128},
    {NOTE_E5, 128},
    {NOTE_C5, 128},
    {NOTE_G4, 128},
    {NOTE_E4, 128},
    {NOTE_C4, 128},
    {NOTE_G3, 128},
    {NOTE_E3, 128},
    {NOTE_C3, 128},
    {NOTE_G2, 128},
    {NOTE_E2, 128},
    {NOTE_C2, 128},
    {NOTE_G1, 128},
    {NOTE_E1, 128},
    {NOTE_C1, 128},
    {NOTE_G0, 128},
    {NOTE_E0, 128},
    {NOTE_C0, 128},
    {NOTE_GM1, 128},
    {NOTE_EM1, 128},
    
    {REST, 8},
    {MELODY_END, 0},
};

struct note_t HAPPY_BIRTHDAY[] = {
    {NOTE_C4, 4},
    {NOTE_C4, 8}, 
    {NOTE_D4, -4},
    {NOTE_C4, -4},
    {NOTE_F4, -4},
    {NOTE_E4, -2},

    {NOTE_C4, 4},
    {NOTE_C4, 8}, 
    {NOTE_D4, -4},
    {NOTE_C4, -4},
    {NOTE_G4, -4},
    {NOTE_F4, -2},

    {NOTE_C4, 4},
    {NOTE_C4, 8},
    {NOTE_C5, -4},
    {NOTE_A4, -4},
    {NOTE_F4, -4}, 
    {NOTE_E4, -4},
    {NOTE_D4, -4},

    {REST, 8},

    {NOTE_AS4, 4},
    {NOTE_AS4, 8},
    {NOTE_A4, -4},
    {NOTE_F4, -4},
    {NOTE_G4, -4},
    {NOTE_F4, -2},

    {MELODY_END, 0},
    };

#endif // TONE_MELODIES_H