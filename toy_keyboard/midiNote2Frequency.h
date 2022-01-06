/*************************************************
 * MIDI Note to Frequency Map
 *
 * Author: James Saunders
 * Source: https://www.inspiredacoustics.com/en/MIDI_note_numbers_and_center_frequencies
 *************************************************/

#define MIDI_G9  127
#define MIDI_FS9 126
#define MIDI_F9  125
#define MIDI_E9  124
#define MIDI_DS9 123
#define MIDI_D9  122
#define MIDI_CS9 121
#define MIDI_C9  120
#define MIDI_B8  119
#define MIDI_AS8 118
#define MIDI_A8  117
#define MIDI_GS8 116
#define MIDI_G8  115
#define MIDI_FS8 114
#define MIDI_F8  113
#define MIDI_E8  112
#define MIDI_DS8 111
#define MIDI_D8  110
#define MIDI_CS8 109
#define MIDI_C8  108
#define MIDI_B7  107
#define MIDI_AS7 106
#define MIDI_A7  105
#define MIDI_GS7 104
#define MIDI_G7  103
#define MIDI_FS7 102
#define MIDI_F7  101
#define MIDI_E7  100
#define MIDI_DS7 99
#define MIDI_D7  98
#define MIDI_CS7 97
#define MIDI_C7  96
#define MIDI_B6  95
#define MIDI_AS6 94
#define MIDI_A6  93
#define MIDI_GS6 92
#define MIDI_G6  91
#define MIDI_FS6 90
#define MIDI_F6  89
#define MIDI_E6  88
#define MIDI_DS6 87
#define MIDI_D6  86
#define MIDI_CS6 85
#define MIDI_C6  84
#define MIDI_B5  83
#define MIDI_AS5 82
#define MIDI_A5  81
#define MIDI_GS5 80
#define MIDI_G5  79
#define MIDI_FS5 78
#define MIDI_F5  77
#define MIDI_E5  76
#define MIDI_DS5 75
#define MIDI_D5  74
#define MIDI_CS5 73
#define MIDI_C5  72
#define MIDI_B4  71
#define MIDI_AS4 70
#define MIDI_A4  69
#define MIDI_GS4 68
#define MIDI_G4  67
#define MIDI_FS4 66
#define MIDI_F4  65
#define MIDI_E4  64
#define MIDI_DS4 63
#define MIDI_D4  62
#define MIDI_CS4 61
#define MIDI_C4  60
#define MIDI_B3  59
#define MIDI_AS3 58
#define MIDI_A3  57
#define MIDI_GS3 56
#define MIDI_G3  55
#define MIDI_FS3 54
#define MIDI_F3  53
#define MIDI_E3  52
#define MIDI_DS3 51
#define MIDI_D3  50
#define MIDI_CS3 49
#define MIDI_C3  48
#define MIDI_B2  47
#define MIDI_AS2 46
#define MIDI_A2  45
#define MIDI_GS2 44
#define MIDI_G2  43
#define MIDI_FS2 42
#define MIDI_F2  41
#define MIDI_E2  40
#define MIDI_DS2 39
#define MIDI_D2  38
#define MIDI_CS2 37
#define MIDI_C2  36
#define MIDI_B1  35
#define MIDI_AS1 34
#define MIDI_A1  33
#define MIDI_GS1 32
#define MIDI_G1  31
#define MIDI_FS1 30
#define MIDI_F1  29
#define MIDI_E1  28
#define MIDI_DS1 27
#define MIDI_D1  26
#define MIDI_CS1 25
#define MIDI_C1  24
#define MIDI_B0  23
#define MIDI_AS0 22
#define MIDI_A0  21

#define FREQ_G9  12543
#define FREQ_FS9 11839
#define FREQ_F9  11175
#define FREQ_E9  10548
#define FREQ_DS9 9956
#define FREQ_D9  9397
#define FREQ_CS9 8869
#define FREQ_C9  8372
#define FREQ_B8  7902
#define FREQ_AS8 7458
#define FREQ_A8  7040
#define FREQ_GS8 6644
#define FREQ_G8  6271
#define FREQ_FS8 5919
#define FREQ_F8  5587
#define FREQ_E8  5274
#define FREQ_DS8 4978
#define FREQ_D8  4698
#define FREQ_CS8 4434
#define FREQ_C8  4186
#define FREQ_B7  3951
#define FREQ_AS7 3729
#define FREQ_A7  3520
#define FREQ_GS7 3322
#define FREQ_G7  3135
#define FREQ_FS7 2959
#define FREQ_F7  2793
#define FREQ_E7  2637
#define FREQ_DS7 2489
#define FREQ_D7  2349
#define FREQ_CS7 2217
#define FREQ_C7  2093
#define FREQ_B6  1975
#define FREQ_AS6 1864
#define FREQ_A6  1760
#define FREQ_GS6 1661
#define FREQ_G6  1567
#define FREQ_FS6 1479
#define FREQ_F6  1396
#define FREQ_E6  1318
#define FREQ_DS6 1244
#define FREQ_D6  1174
#define FREQ_CS6 1108
#define FREQ_C6  1046
#define FREQ_B5  987
#define FREQ_AS5 932
#define FREQ_A5  880
#define FREQ_GS5 830
#define FREQ_G5  783
#define FREQ_FS5 739
#define FREQ_F5  698
#define FREQ_E5  659
#define FREQ_DS5 622
#define FREQ_D5  587
#define FREQ_CS5 554
#define FREQ_C5  523
#define FREQ_B4  493
#define FREQ_AS4 466
#define FREQ_A4  440
#define FREQ_GS4 415
#define FREQ_G4  392
#define FREQ_FS4 369
#define FREQ_F4  349
#define FREQ_E4  329
#define FREQ_DS4 311
#define FREQ_D4  293
#define FREQ_CS4 277
#define FREQ_C4  261
#define FREQ_B3  246
#define FREQ_AS3 233
#define FREQ_A3  220
#define FREQ_GS3 207
#define FREQ_G3  196
#define FREQ_FS3 185
#define FREQ_F3  174
#define FREQ_E3  164
#define FREQ_DS3 155
#define FREQ_D3  146
#define FREQ_CS3 138
#define FREQ_C3  130
#define FREQ_B2  123
#define FREQ_AS2 116
#define FREQ_A2  110
#define FREQ_GS2 103
#define FREQ_G2  98
#define FREQ_FS2 92
#define FREQ_F2  87
#define FREQ_E2  82
#define FREQ_DS2 77
#define FREQ_D2  73
#define FREQ_CS2 69
#define FREQ_C2  65
#define FREQ_B1  61
#define FREQ_AS1 58
#define FREQ_A1  55
#define FREQ_GS1 51
#define FREQ_G1  49
#define FREQ_FS1 46
#define FREQ_F1  43
#define FREQ_E1  41
#define FREQ_DS1 38
#define FREQ_D1  36
#define FREQ_CS1 34
#define FREQ_C1  32
#define FREQ_B0  30
#define FREQ_AS0 29
#define FREQ_A0  27

typedef struct {
  int midiNote;
  int frequency;
} MidiNotes;

#define NUM_NOTES 107

MidiNotes noteLookup[NUM_NOTES] = {
    {MIDI_G9,  FREQ_G9},
    {MIDI_FS9, FREQ_FS9},
    {MIDI_F9,  FREQ_F9},
    {MIDI_E9,  FREQ_E9},
    {MIDI_DS9, FREQ_DS9},
    {MIDI_D9,  FREQ_D9},
    {MIDI_CS9, FREQ_CS9},
    {MIDI_C9,  FREQ_C9},
    {MIDI_B8,  FREQ_B8},
    {MIDI_AS8, FREQ_AS8},
    {MIDI_A8,  FREQ_A8},
    {MIDI_GS8, FREQ_GS8},
    {MIDI_G8,  FREQ_G8},
    {MIDI_FS8, FREQ_FS8},
    {MIDI_F8,  FREQ_F8},
    {MIDI_E8,  FREQ_E8},
    {MIDI_DS8, FREQ_DS8},
    {MIDI_D8,  FREQ_D8},
    {MIDI_CS8, FREQ_CS8},
    {MIDI_C8,  FREQ_C8},
    {MIDI_B7,  FREQ_B7},
    {MIDI_AS7, FREQ_AS7},
    {MIDI_A7,  FREQ_A7},
    {MIDI_GS7, FREQ_GS7},
    {MIDI_G7,  FREQ_G7},
    {MIDI_FS7, FREQ_FS7},
    {MIDI_F7,  FREQ_F7},
    {MIDI_E7,  FREQ_E7},
    {MIDI_DS7, FREQ_DS7},
    {MIDI_D7,  FREQ_D7},
    {MIDI_CS7, FREQ_CS7},
    {MIDI_C7,  FREQ_C7},
    {MIDI_B6,  FREQ_B6},
    {MIDI_AS6, FREQ_AS6},
    {MIDI_A6,  FREQ_A6},
    {MIDI_GS6, FREQ_GS6},
    {MIDI_G6,  FREQ_G6},
    {MIDI_FS6, FREQ_FS6},
    {MIDI_F6,  FREQ_F6},
    {MIDI_E6,  FREQ_E6},
    {MIDI_DS6, FREQ_DS6},
    {MIDI_D6,  FREQ_D6},
    {MIDI_CS6, FREQ_CS6},
    {MIDI_C6,  FREQ_C6},
    {MIDI_B5,  FREQ_B5},
    {MIDI_AS5, FREQ_AS5},
    {MIDI_A5,  FREQ_A5},
    {MIDI_GS5, FREQ_GS5},
    {MIDI_G5,  FREQ_G5},
    {MIDI_FS5, FREQ_FS5},
    {MIDI_F5,  FREQ_F5},
    {MIDI_E5,  FREQ_E5},
    {MIDI_DS5, FREQ_DS5},
    {MIDI_D5,  FREQ_D5},
    {MIDI_CS5, FREQ_CS5},
    {MIDI_C5,  FREQ_C5},
    {MIDI_B4,  FREQ_B4},
    {MIDI_AS4, FREQ_AS4},
    {MIDI_A4,  FREQ_A4},
    {MIDI_GS4, FREQ_GS4},
    {MIDI_G4,  FREQ_G4},
    {MIDI_FS4, FREQ_FS4},
    {MIDI_F4,  FREQ_F4},
    {MIDI_E4,  FREQ_E4},
    {MIDI_DS4, FREQ_DS4},
    {MIDI_D4,  FREQ_D4},
    {MIDI_CS4, FREQ_CS4},
    {MIDI_C4,  FREQ_C4},
    {MIDI_B3,  FREQ_B3},
    {MIDI_AS3, FREQ_AS3},
    {MIDI_A3,  FREQ_A3},
    {MIDI_GS3, FREQ_GS3},
    {MIDI_G3,  FREQ_G3},
    {MIDI_FS3, FREQ_FS3},
    {MIDI_F3,  FREQ_F3},
    {MIDI_E3,  FREQ_E3},
    {MIDI_DS3, FREQ_DS3},
    {MIDI_D3,  FREQ_D3},
    {MIDI_CS3, FREQ_CS3},
    {MIDI_C3,  FREQ_C3},
    {MIDI_B2,  FREQ_B2},
    {MIDI_AS2, FREQ_AS2},
    {MIDI_A2,  FREQ_A2},
    {MIDI_GS2, FREQ_GS2},
    {MIDI_G2,  FREQ_G2},
    {MIDI_FS2, FREQ_FS2},
    {MIDI_F2,  FREQ_F2},
    {MIDI_E2,  FREQ_E2},
    {MIDI_DS2, FREQ_DS2},
    {MIDI_D2,  FREQ_D2},
    {MIDI_CS2, FREQ_CS2},
    {MIDI_C2,  FREQ_C2},
    {MIDI_B1,  FREQ_B1},
    {MIDI_AS1, FREQ_AS1},
    {MIDI_A1,  FREQ_A1},
    {MIDI_GS1, FREQ_GS1},
    {MIDI_G1,  FREQ_G1},
    {MIDI_FS1, FREQ_FS1},
    {MIDI_F1,  FREQ_F1},
    {MIDI_E1,  FREQ_E1},
    {MIDI_DS1, FREQ_DS1},
    {MIDI_D1,  FREQ_D1},
    {MIDI_CS1, FREQ_CS1},
    {MIDI_C1,  FREQ_C1},
    {MIDI_B0,  FREQ_B0},
    {MIDI_AS0, FREQ_AS0},
    {MIDI_A0,  FREQ_A0}
};

int freqFromMidiNote(int midiNote) {
  for (int i = 0; i < NUM_NOTES; i++) {
    if (noteLookup[i].midiNote == midiNote) {
      return noteLookup[i].frequency;
    }
  }

  return 0;
}
