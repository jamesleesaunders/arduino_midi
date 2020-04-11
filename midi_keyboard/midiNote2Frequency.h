/*************************************************
 * MIDI Note to Frequency Map
 *
 * Author: James Saunders
 * Source: https://www.inspiredacoustics.com/en/MIDI_note_numbers_and_center_frequencies
 *************************************************/

#define NOTE_G9  127
#define NOTE_FS9 126
#define NOTE_F9  125
#define NOTE_E9  124
#define NOTE_DS9 123
#define NOTE_D9  122
#define NOTE_CS9 121
#define NOTE_C9  120
#define NOTE_B8  119
#define NOTE_AS8 118
#define NOTE_A8  117
#define NOTE_GS8 116
#define NOTE_G8  115
#define NOTE_FS8 114
#define NOTE_F8  113
#define NOTE_E8  112
#define NOTE_DS8 111
#define NOTE_D8  110
#define NOTE_CS8 109
#define NOTE_C8  108
#define NOTE_B7  107
#define NOTE_AS7 106
#define NOTE_A7  105
#define NOTE_GS7 104
#define NOTE_G7  103
#define NOTE_FS7 102
#define NOTE_F7  101
#define NOTE_E7  100
#define NOTE_DS7 99
#define NOTE_D7  98
#define NOTE_CS7 97
#define NOTE_C7  96
#define NOTE_B6  95
#define NOTE_AS6 94
#define NOTE_A6  93
#define NOTE_GS6 92
#define NOTE_G6  91
#define NOTE_FS6 90
#define NOTE_F6  89
#define NOTE_E6  88
#define NOTE_DS6 87
#define NOTE_D6  86
#define NOTE_CS6 85
#define NOTE_C6  84
#define NOTE_B5  83
#define NOTE_AS5 82
#define NOTE_A5  81
#define NOTE_GS5 80
#define NOTE_G5  79
#define NOTE_FS5 78
#define NOTE_F5  77
#define NOTE_E5  76
#define NOTE_DS5 75
#define NOTE_D5  74
#define NOTE_CS5 73
#define NOTE_C5  72
#define NOTE_B4  71
#define NOTE_AS4 70
#define NOTE_A4  69
#define NOTE_GS4 68
#define NOTE_G4  67
#define NOTE_FS4 66
#define NOTE_F4  65
#define NOTE_E4  64
#define NOTE_DS4 63
#define NOTE_D4  62
#define NOTE_CS4 61
#define NOTE_C4  60
#define NOTE_B3  59
#define NOTE_AS3 58
#define NOTE_A3  57
#define NOTE_GS3 56
#define NOTE_G3  55
#define NOTE_FS3 54
#define NOTE_F3  53
#define NOTE_E3  52
#define NOTE_DS3 51
#define NOTE_D3  50
#define NOTE_CS3 49
#define NOTE_C3  48
#define NOTE_B2  47
#define NOTE_AS2 46
#define NOTE_A2  45
#define NOTE_GS2 44
#define NOTE_G2  43
#define NOTE_FS2 42
#define NOTE_F2  41
#define NOTE_E2  40
#define NOTE_DS2 39
#define NOTE_D2  38
#define NOTE_CS2 37
#define NOTE_C2  36
#define NOTE_B1  35
#define NOTE_AS1 34
#define NOTE_A1  33
#define NOTE_GS1 32
#define NOTE_G1  31
#define NOTE_FS1 30
#define NOTE_F1  29
#define NOTE_E1  28
#define NOTE_DS1 27
#define NOTE_D1  26
#define NOTE_CS1 25
#define NOTE_C1  24
#define NOTE_B0  23
#define NOTE_AS0 22
#define NOTE_A0  21

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
	{99, NOTE_DS7},
	{98, NOTE_D7},
	{97, NOTE_CS7},
	{96, NOTE_C7},
	{95, NOTE_B6},
	{94, NOTE_AS6},
	{93, NOTE_A6},
	{92, NOTE_GS6},
	{91, NOTE_G6},
	{90, NOTE_FS6},
	{89, NOTE_F6},
	{88, NOTE_E6},
	{87, NOTE_DS6},
	{86, NOTE_D6},
	{85, NOTE_CS6},
	{84, NOTE_C6},
	{83, NOTE_B5},
	{82, NOTE_AS5},
	{81, NOTE_A5},
	{80, NOTE_GS5},
	{79, NOTE_G5},
	{78, NOTE_FS5},
	{77, NOTE_F5},
	{76, NOTE_E5},
	{75, NOTE_DS5},
	{74, NOTE_D5},
	{73, NOTE_CS5},
	{72, NOTE_C5},
	{71, NOTE_B4},
	{70, NOTE_AS4},
	{69, NOTE_A4},
	{68, NOTE_GS4},
	{67, NOTE_G4},
	{66, NOTE_FS4},
	{65, NOTE_F4},
	{64, NOTE_E4},
	{63, NOTE_DS4},
	{62, NOTE_D4},
	{61, NOTE_CS4},
	{60, NOTE_C4},
	{59, NOTE_B3},
	{58, NOTE_AS3},
	{57, NOTE_A3},
	{56, NOTE_GS3},
	{55, NOTE_G3},
	{54, NOTE_FS3},
	{53, NOTE_F3},
	{52, NOTE_E3},
	{51, NOTE_DS3},
	{50, NOTE_D3},
	{49, NOTE_CS3},
	{48, NOTE_C3},
	{47, NOTE_B2},
	{46, NOTE_AS2},
	{45, NOTE_A2},
	{44, NOTE_GS2},
	{43, NOTE_G2},
	{42, NOTE_FS2},
	{41, NOTE_F2},
	{40, NOTE_E2},
	{39, NOTE_DS2},
	{38, NOTE_D2},
	{37, NOTE_CS2},
	{36, NOTE_C2},
	{35, NOTE_B1},
	{34, NOTE_AS1},
	{33, NOTE_A1},
	{32, NOTE_GS1},
	{31, NOTE_G1},
	{30, NOTE_FS1},
	{29, NOTE_F1},
	{28, NOTE_E1},
	{27, NOTE_DS1},
	{26, NOTE_D1},
	{25, NOTE_CS1},
	{24, NOTE_C1},
	{23, NOTE_B0},
	{22, NOTE_AS0},
	{21, NOTE_A0}
};

int FreqFromMidiNote(int midiNote) {  
  for(int i = 0; i < sizeof(noteLookup); i++) {
    if(noteLookup[i].midiNote == midiNote) {
      return noteLookup[i].frequency;
    }
  }
  
  return 0;
}
