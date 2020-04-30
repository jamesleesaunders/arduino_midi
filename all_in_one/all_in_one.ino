/*************************************************
 * MIDI All-in-one
 *
 * Author: James Saunders
 *************************************************/

#include "midiNote2Frequency.h"
#include <MIDI.h>

#define NUM_BUTTONS 7
#define BUZZER_PIN 9

const uint8_t button1 = 2;
const uint8_t button2 = 3;
const uint8_t button3 = 4;
const uint8_t button4 = 5;
const uint8_t button5 = 6;
const uint8_t button6 = 7;
const uint8_t button7 = 8;
const int pitchPot = 0;  // A0 input

const uint8_t buttons[NUM_BUTTONS] = {button1, button2, button3, button4, button5, button6, button7};
const uint8_t midiNotes[NUM_BUTTONS] = {MIDI_A3, MIDI_B3, MIDI_C4, MIDI_D4, MIDI_E4, MIDI_F4, MIDI_G4};

const uint8_t midiChannel = 1;

int currentPitch = 0;
int currentNote = 0;
int cycleCount = 0;
float pitchVariance = 0;

// Created and binds the MIDI interface to the default hardware serial port.
MIDI_CREATE_DEFAULT_INSTANCE();

void setup() {
  MIDI.begin(MIDI_CHANNEL_OMNI);

  // Handle incoming MIDI messages.
  MIDI.setHandleNoteOn(handleNoteOn);
  MIDI.setHandleNoteOff(handleNoteOff);
  MIDI.setHandlePitchBend(handlePitchBend);

  // Initialize buttons.
  for (int i = 0; i < NUM_BUTTONS; i++) {
    pinMode(buttons[i], INPUT_PULLUP);
  }
}

void loop() {
  MIDI.turnThruOff();
  MIDI.read();
  readKeys();
  readPitch();
}

void handleNoteOn(byte channel, byte midiNote, byte velocity) {
  // Lookup pitch from MIDI Note
  int frequency = FreqFromMidiNote(midiNote);

  // Apply pitch variance
  int pitch = frequency * pow(2, (pitchVariance / 12));
  
  // Play Note
  tone(BUZZER_PIN, pitch, 2000);
}

void handleNoteOff(byte channel, byte midiNote, byte velocity) {
  // Stop Playing Note
  noTone(BUZZER_PIN);
}

void handlePitchBend(byte channel, int bend) {
  // Handle Pitch Bend
  pitchVariance = mapfloat(bend, -8192, 8192, -2, 2);
}

void readKeys() {
  for (int i = 0; i < NUM_BUTTONS; i++) {
    int midiNote = midiNotes[i];
    if (digitalRead(buttons[i]) == LOW) {
      if (midiNote != currentNote) {
        MIDI.sendNoteOff(currentNote, 127, midiChannel);
        MIDI.sendNoteOn(midiNote, 127, midiChannel);
        currentNote = midiNote;
      }
      cycleCount = 0;
    }
  }

  if (currentNote && cycleCount > 10) {
    for (int i = 0; i < NUM_BUTTONS; i++) {
      int midiNote = midiNotes[i];
      MIDI.sendNoteOff(midiNote, 127, midiChannel);
    }
    currentNote = 0;
    cycleCount = 0;
  }
  cycleCount++;
}

void readPitch() {
  int reading = analogRead(pitchPot);

  // Map pot readings into 24 bands.
  // https://forum.arduino.cc/index.php?topic=266687.0
  int bandValue = map(reading, 0, 1024, -12, 12);

  // Convert to MIDI frequency bend.
  int pitchValue = map(bandValue, -12, 12, -8192, 8192);

  if (pitchValue != currentPitch) {
    MIDI.sendPitchBend(pitchValue, midiChannel);
    currentPitch = pitchValue;
  }
}

float mapfloat(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
