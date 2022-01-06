/*************************************************
   MIDI Christmas Tree RGB FastLED

   Author: James Saunders
 *************************************************/

#include <MIDI.h>
#include <FastLED.h>

// Created and binds the MIDI interface to the default hardware serial port
MIDI_CREATE_DEFAULT_INSTANCE();

#define LED_C 6
#define LED_D 5
#define LED_E 4
#define LED_F 3
#define LED_G 2
#define LED_A 1
#define LED_B 0

#define DATA_PIN 6
#define NUM_LEDS 7

CRGB leds[NUM_LEDS];

typedef struct {
  int midiNote;
  int led;
  int red;
  int green;
  int blue;
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
  {MIDI_G9,  LED_G, 255, 0, 0},
  {MIDI_F9,  LED_F, 255, 0, 0},
  {MIDI_E9,  LED_E, 255, 0, 0},
  {MIDI_D9,  LED_D, 255, 0, 0},
  {MIDI_C9,  LED_C, 255, 0, 0},
  {MIDI_B8,  LED_B, 255, 255, 0},
  {MIDI_A8,  LED_A, 255, 255, 0},
  {MIDI_G8,  LED_G, 255, 255, 0},
  {MIDI_F8,  LED_F, 255, 255, 0},
  {MIDI_E8,  LED_E, 255, 255, 0},
  {MIDI_D8,  LED_D, 255, 255, 0},
  {MIDI_C8,  LED_C, 255, 255, 0},
  {MIDI_B7,  LED_B, 0, 255, 0},
  {MIDI_A7,  LED_A, 0, 255, 0},
  {MIDI_G7,  LED_G, 0, 255, 0},
  {MIDI_F7,  LED_F, 0, 255, 0},
  {MIDI_E7,  LED_E, 0, 255, 0},
  {MIDI_D7,  LED_D, 0, 255, 0},
  {MIDI_C7,  LED_C, 0, 255, 0},
  {MIDI_B6,  LED_B, 0, 255, 255},
  {MIDI_A6,  LED_A, 0, 255, 255},
  {MIDI_G6,  LED_G, 0, 255, 255},
  {MIDI_F6,  LED_F, 0, 255, 255},
  {MIDI_E6,  LED_E, 0, 255, 255},
  {MIDI_D6,  LED_D, 0, 255, 255},
  {MIDI_C6,  LED_C, 0, 255, 255},
  {MIDI_B5,  LED_B, 0, 0, 255},
  {MIDI_A5,  LED_A, 0, 0, 255},
  {MIDI_G5,  LED_G, 0, 0, 255},
  {MIDI_F5,  LED_F, 0, 0, 255},
  {MIDI_E5,  LED_E, 0, 0, 255},
  {MIDI_D5,  LED_D, 0, 0, 255},
  {MIDI_C5,  LED_C, 0, 0, 255},
  {MIDI_B4,  LED_B, 255, 0, 255},
  {MIDI_A4,  LED_A, 255, 0, 255},
  {MIDI_G4,  LED_G, 255, 0, 255},
  {MIDI_F4,  LED_F, 255, 0, 255},
  {MIDI_E4,  LED_E, 255, 0, 255},
  {MIDI_D4,  LED_D, 255, 0, 255},
  {MIDI_C4,  LED_C, 255, 0, 255},
  {MIDI_B3,  LED_B, 255, 0, 0},
  {MIDI_A3,  LED_A, 255, 0, 0},
  {MIDI_G3,  LED_G, 255, 0, 0},
  {MIDI_F3,  LED_F, 255, 0, 0},
  {MIDI_E3,  LED_E, 255, 0, 0},
  {MIDI_D3,  LED_D, 255, 0, 0},
  {MIDI_C3,  LED_C, 255, 0, 0},
  {MIDI_B2,  LED_B, 255, 255, 0},
  {MIDI_A2,  LED_A, 255, 255, 0},
  {MIDI_G2,  LED_G, 255, 255, 0},
  {MIDI_F2,  LED_F, 255, 255, 0},
  {MIDI_E2,  LED_E, 255, 255, 0},
  {MIDI_D2,  LED_D, 255, 255, 0},
  {MIDI_C2,  LED_C, 255, 255, 0},
  {MIDI_B1,  LED_B, 0, 255, 0},
  {MIDI_A1,  LED_A, 0, 255, 0},
  {MIDI_G1,  LED_G, 0, 255, 0},
  {MIDI_F1,  LED_F, 0, 255, 0},
  {MIDI_E1,  LED_E, 0, 255, 0},
  {MIDI_D1,  LED_D, 0, 255, 0},
  {MIDI_C1,  LED_C, 0, 255, 0},
  {MIDI_B0,  LED_B, 0, 255, 255},
  {MIDI_A0,  LED_A, 0, 255, 255}
};

MidiLed ledFromMidiNote(int midiNote) {
  for (int i = 0; i < NUM_NOTES; i++) {
    if (noteLookup[i].midiNote == midiNote) {
      return noteLookup[i];
    }
  }

  return {midiNote, LED_F, 255, 255, 255};
}

void setup() {
  // Initialize NeoPixel Library
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);

  // Initialize the MIDI Library
  MIDI.begin(MIDI_CHANNEL_OMNI);

  MIDI.setHandleNoteOn(handleNoteOn);
  MIDI.setHandleNoteOff(handleNoteOff);
}

void loop() {
  MIDI.read();
}

void handleNoteOn(byte channel, byte midiNote, byte velocity) {
  MidiLed pixel = ledFromMidiNote(midiNote);

  leds[pixel.led].setRGB(pixel.red, pixel.green, pixel.blue);
  FastLED.show();
}

void handleNoteOff(byte channel, byte midiNote, byte velocity) {
  MidiLed pixel = ledFromMidiNote(midiNote);

  leds[pixel.led] = CRGB::Black;
  FastLED.show();
}
