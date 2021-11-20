/*************************************************
   MIDI Christmas Tree LED

   Author: James Saunders
 *************************************************/

#include <MIDI.h>

// Created and binds the MIDI interface to the default hardware serial port
MIDI_CREATE_DEFAULT_INSTANCE();

#define LED_C 6
#define LED_D 7
#define LED_E 8
#define LED_F 10
#define LED_G 11
#define LED_A 12
#define LED_B 13

typedef struct {
  int midiNote;
  int led;
} MidiLed;

#define MIDI_G9  127
#define MIDI_F9  125
#define MIDI_E9  124
#define MIDI_D9  122
#define MIDI_C9  120
#define MIDI_B8  119
#define MIDI_A8  117
#define MIDI_G8  115
#define MIDI_F8  113
#define MIDI_E8  112
#define MIDI_D8  110
#define MIDI_C8  108
#define MIDI_B7  107
#define MIDI_A7  105
#define MIDI_G7  103
#define MIDI_F7  101
#define MIDI_E7  100
#define MIDI_D7  98
#define MIDI_C7  96
#define MIDI_B6  95
#define MIDI_A6  93
#define MIDI_G6  91
#define MIDI_F6  89
#define MIDI_E6  88
#define MIDI_D6  86
#define MIDI_C6  84
#define MIDI_B5  83
#define MIDI_A5  81
#define MIDI_G5  79
#define MIDI_F5  77
#define MIDI_E5  76
#define MIDI_D5  74
#define MIDI_C5  72
#define MIDI_B4  71
#define MIDI_A4  69
#define MIDI_G4  67
#define MIDI_F4  65
#define MIDI_E4  64
#define MIDI_D4  62
#define MIDI_C4  60
#define MIDI_B3  59
#define MIDI_A3  57
#define MIDI_G3  55
#define MIDI_F3  53
#define MIDI_E3  52
#define MIDI_D3  50
#define MIDI_C3  48
#define MIDI_B2  47
#define MIDI_A2  45
#define MIDI_G2  43
#define MIDI_F2  41
#define MIDI_E2  40
#define MIDI_D2  38
#define MIDI_C2  36
#define MIDI_B1  35
#define MIDI_A1  33
#define MIDI_G1  31
#define MIDI_F1  29
#define MIDI_E1  28
#define MIDI_D1  26
#define MIDI_C1  24
#define MIDI_B0  23
#define MIDI_A0  21

#define NUM_NOTES 63

MidiLed noteLookup[NUM_NOTES] = {
  {MIDI_G9,  LED_G},
  {MIDI_F9,  LED_F},
  {MIDI_E9,  LED_E},
  {MIDI_D9,  LED_D},
  {MIDI_C9,  LED_C},
  {MIDI_B8,  LED_B},
  {MIDI_A8,  LED_A},
  {MIDI_G8,  LED_G},
  {MIDI_F8,  LED_F},
  {MIDI_E8,  LED_E},
  {MIDI_D8,  LED_D},
  {MIDI_C8,  LED_C},
  {MIDI_B7,  LED_B},
  {MIDI_A7,  LED_A},
  {MIDI_G7,  LED_G},
  {MIDI_F7,  LED_F},
  {MIDI_E7,  LED_E},
  {MIDI_D7,  LED_D},
  {MIDI_C7,  LED_C},
  {MIDI_B6,  LED_B},
  {MIDI_A6,  LED_A},
  {MIDI_G6,  LED_G},
  {MIDI_F6,  LED_F},
  {MIDI_E6,  LED_E},
  {MIDI_D6,  LED_D},
  {MIDI_C6,  LED_C},
  {MIDI_B5,  LED_B},
  {MIDI_A5,  LED_A},
  {MIDI_G5,  LED_G},
  {MIDI_F5,  LED_F},
  {MIDI_E5,  LED_E},
  {MIDI_D5,  LED_D},
  {MIDI_C5,  LED_C},
  {MIDI_B4,  LED_B},
  {MIDI_A4,  LED_A},
  {MIDI_G4,  LED_G},
  {MIDI_F4,  LED_F},
  {MIDI_E4,  LED_E},
  {MIDI_D4,  LED_D},
  {MIDI_C4,  LED_C},
  {MIDI_B3,  LED_B},
  {MIDI_A3,  LED_A},
  {MIDI_G3,  LED_G},
  {MIDI_F3,  LED_F},
  {MIDI_E3,  LED_E},
  {MIDI_D3,  LED_D},
  {MIDI_C3,  LED_C},
  {MIDI_B2,  LED_B},
  {MIDI_A2,  LED_A},
  {MIDI_G2,  LED_G},
  {MIDI_F2,  LED_F},
  {MIDI_E2,  LED_E},
  {MIDI_D2,  LED_D},
  {MIDI_C2,  LED_C},
  {MIDI_B1,  LED_B},
  {MIDI_A1,  LED_A},
  {MIDI_G1,  LED_G},
  {MIDI_F1,  LED_F},
  {MIDI_E1,  LED_E},
  {MIDI_D1,  LED_D},
  {MIDI_C1,  LED_C},
  {MIDI_B0,  LED_B},
  {MIDI_A0,  LED_A}
};

MidiLed ledFromMidiNote(int midiNote) {
  for (int i = 0; i < NUM_NOTES; i++) {
    if (noteLookup[i].midiNote == midiNote) {
      return noteLookup[i];
    }
  }

  return;
}

void setup() {
  // Initialize LEDs
  pinMode(LED_A, OUTPUT);
  pinMode(LED_B, OUTPUT);
  pinMode(LED_C, OUTPUT);
  pinMode(LED_D, OUTPUT);
  pinMode(LED_E, OUTPUT);
  pinMode(LED_F, OUTPUT);
  pinMode(LED_G, OUTPUT);

  // Initialize the MIDI Library
  MIDI.begin(MIDI_CHANNEL_OMNI);

  MIDI.setHandleNoteOn(handleNoteOn);
  MIDI.setHandleNoteOff(handleNoteOff);
}

void loop() {
  MIDI.read();
}

void handleNoteOn(byte channel, byte midiNote, byte velocity) {
  int led = ledFromMidiNote(midiNote).led;
  digitalWrite(led, HIGH);
}

void handleNoteOff(byte channel, byte midiNote, byte velocity) {
  int led = ledFromMidiNote(midiNote).led;
  digitalWrite(led, LOW);
}
