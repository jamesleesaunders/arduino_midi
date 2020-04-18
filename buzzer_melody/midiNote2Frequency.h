/*************************************************
 * MIDI Note to Frequency Map
 *
 * Author: James Saunders
 * Source: https://www.inspiredacoustics.com/en/MIDI_note_numbers_and_center_frequencies
 *************************************************/

#define NOTE_G9  12543
#define NOTE_FS9 11839
#define NOTE_F9  11175
#define NOTE_E9  10548
#define NOTE_DS9 9956
#define NOTE_D9  9397
#define NOTE_CS9 8869
#define NOTE_C9  8372
#define NOTE_B8  7902
#define NOTE_AS8 7458
#define NOTE_A8  7040
#define NOTE_GS8 6644
#define NOTE_G8  6271
#define NOTE_FS8 5919
#define NOTE_F8  5587
#define NOTE_E8  5274
#define NOTE_DS8 4978
#define NOTE_D8  4698
#define NOTE_CS8 4434
#define NOTE_C8  4186
#define NOTE_B7  3951
#define NOTE_AS7 3729
#define NOTE_A7  3520
#define NOTE_GS7 3322
#define NOTE_G7  3135
#define NOTE_FS7 2959
#define NOTE_F7  2793
#define NOTE_E7  2637
#define NOTE_DS7 2489
#define NOTE_D7  2349
#define NOTE_CS7 2217
#define NOTE_C7  2093
#define NOTE_B6  1975
#define NOTE_AS6 1864
#define NOTE_A6  1760
#define NOTE_GS6 1661
#define NOTE_G6  1567
#define NOTE_FS6 1479
#define NOTE_F6  1396
#define NOTE_E6  1318
#define NOTE_DS6 1244
#define NOTE_D6  1174
#define NOTE_CS6 1108
#define NOTE_C6  1046
#define NOTE_B5  987
#define NOTE_AS5 932
#define NOTE_A5  880
#define NOTE_GS5 830
#define NOTE_G5  783
#define NOTE_FS5 739
#define NOTE_F5  698
#define NOTE_E5  659
#define NOTE_DS5 622
#define NOTE_D5  587
#define NOTE_CS5 554
#define NOTE_C5  523
#define NOTE_B4  493
#define NOTE_AS4 466
#define NOTE_A4  440
#define NOTE_GS4 415
#define NOTE_G4  392
#define NOTE_FS4 369
#define NOTE_F4  349
#define NOTE_E4  329
#define NOTE_DS4 311
#define NOTE_D4  293
#define NOTE_CS4 277
#define NOTE_C4  261
#define NOTE_B3  246
#define NOTE_AS3 233
#define NOTE_A3  220
#define NOTE_GS3 207
#define NOTE_G3  196
#define NOTE_FS3 185
#define NOTE_F3  174
#define NOTE_E3  164
#define NOTE_DS3 155
#define NOTE_D3  146
#define NOTE_CS3 138
#define NOTE_C3  130
#define NOTE_B2  123
#define NOTE_AS2 116
#define NOTE_A2  110
#define NOTE_GS2 103
#define NOTE_G2  98
#define NOTE_FS2 92
#define NOTE_F2  87
#define NOTE_E2  82
#define NOTE_DS2 77
#define NOTE_D2  73
#define NOTE_CS2 69
#define NOTE_C2  65
#define NOTE_B1  61
#define NOTE_AS1 58
#define NOTE_A1  55
#define NOTE_GS1 51
#define NOTE_G1  49
#define NOTE_FS1 46
#define NOTE_F1  43
#define NOTE_E1  41
#define NOTE_DS1 38
#define NOTE_D1  36
#define NOTE_CS1 34
#define NOTE_C1  32
#define NOTE_B0  30
#define NOTE_AS0 29
#define NOTE_A0  27

typedef struct {
  int midiNote;
  int frequency;
} MidiNotes;

MidiNotes noteLookup[107] = {
  {127, NOTE_G9},
  {126, NOTE_FS9},
  {125, NOTE_F9},
  {124, NOTE_E9},
  {123, NOTE_DS9},
  {122, NOTE_D9},
  {121, NOTE_CS9},
  {120, NOTE_C9},
  {119, NOTE_B8},
  {118, NOTE_AS8},
  {117, NOTE_A8},
  {116, NOTE_GS8},
  {115, NOTE_G8},
  {114, NOTE_FS8},
  {113, NOTE_F8},
  {112, NOTE_E8},
  {111, NOTE_DS8},
  {110, NOTE_D8},
  {109, NOTE_CS8},
  {108, NOTE_C8},
  {107, NOTE_B7},
  {106, NOTE_AS7},
  {105, NOTE_A7},
  {104, NOTE_GS7},
  {103, NOTE_G7},
  {102, NOTE_FS7},
  {101, NOTE_F7},
  {100, NOTE_E7},
  {99,  NOTE_DS7},
  {98,  NOTE_D7},
  {97,  NOTE_CS7},
  {96,  NOTE_C7},
  {95,  NOTE_B6},
  {94,  NOTE_AS6},
  {93,  NOTE_A6},
  {92,  NOTE_GS6},
  {91,  NOTE_G6},
  {90,  NOTE_FS6},
  {89,  NOTE_F6},
  {88,  NOTE_E6},
  {87,  NOTE_DS6},
  {86,  NOTE_D6},
  {85,  NOTE_CS6},
  {84,  NOTE_C6},
  {83,  NOTE_B5},
  {82,  NOTE_AS5},
  {81,  NOTE_A5},
  {80,  NOTE_GS5},
  {79,  NOTE_G5},
  {78,  NOTE_FS5},
  {77,  NOTE_F5},
  {76,  NOTE_E5},
  {75,  NOTE_DS5},
  {74,  NOTE_D5},
  {73,  NOTE_CS5},
  {72,  NOTE_C5},
  {71,  NOTE_B4},
  {70,  NOTE_AS4},
  {69,  NOTE_A4},
  {68,  NOTE_GS4},
  {67,  NOTE_G4},
  {66,  NOTE_FS4},
  {65,  NOTE_F4},
  {64,  NOTE_E4},
  {63,  NOTE_DS4},
  {62,  NOTE_D4},
  {61,  NOTE_CS4},
  {60,  NOTE_C4},
  {59,  NOTE_B3},
  {58,  NOTE_AS3},
  {57,  NOTE_A3},
  {56,  NOTE_GS3},
  {55,  NOTE_G3},
  {54,  NOTE_FS3},
  {53,  NOTE_F3},
  {52,  NOTE_E3},
  {51,  NOTE_DS3},
  {50,  NOTE_D3},
  {49,  NOTE_CS3},
  {48,  NOTE_C3},
  {47,  NOTE_B2},
  {46,  NOTE_AS2},
  {45,  NOTE_A2},
  {44,  NOTE_GS2},
  {43,  NOTE_G2},
  {42,  NOTE_FS2},
  {41,  NOTE_F2},
  {40,  NOTE_E2},
  {39,  NOTE_DS2},
  {38,  NOTE_D2},
  {37,  NOTE_CS2},
  {36,  NOTE_C2},
  {35,  NOTE_B1},
  {34,  NOTE_AS1},
  {33,  NOTE_A1},
  {32,  NOTE_GS1},
  {31,  NOTE_G1},
  {30,  NOTE_FS1},
  {29,  NOTE_F1},
  {28,  NOTE_E1},
  {27,  NOTE_DS1},
  {26,  NOTE_D1},
  {25,  NOTE_CS1},
  {24,  NOTE_C1},
  {23,  NOTE_B0},
  {22,  NOTE_AS0},
  {21,  NOTE_A0}
};

int FreqFromMidiNote(int midiNote) {
  for (int i = 0; i < sizeof(noteLookup); i++) {
    if (noteLookup[i].midiNote == midiNote) {
      return noteLookup[i].frequency;
    }
  }

  return 0;
}
