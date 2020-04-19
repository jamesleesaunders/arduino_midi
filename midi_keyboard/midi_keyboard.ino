/*************************************************
 * MIDI Keyboard Example
 *
 * Author: James Saunders
 *************************************************/

#include <MIDI.h>

#define NUM_BUTTONS 7

const uint8_t button1 = 2;
const uint8_t button2 = 3;
const uint8_t button3 = 4;
const uint8_t button4 = 5;
const uint8_t button5 = 6;
const uint8_t button6 = 7;
const uint8_t button7 = 8;
const int pitchPot = 0;  // A0 input

const uint8_t buttons[NUM_BUTTONS] = {button1, button2, button3, button4, button5, button6, button7};
const uint8_t midiNotes[NUM_BUTTONS] = {57, 59, 60, 62, 64, 65, 67};

int currentPitch = 0;
int currentNote = 0;
int cycleCount = 0;

// Created and binds the MIDI interface to the default hardware Serial port
MIDI_CREATE_DEFAULT_INSTANCE();

void setup() {
  MIDI.begin(MIDI_CHANNEL_OMNI);

  for (int i = 0; i < NUM_BUTTONS; i++) {
    pinMode(buttons[i], INPUT_PULLUP);
  }

}

void loop() {
  readKeys();
  readPitch();
}

void readKeys() {
  for (int i = 0; i < NUM_BUTTONS; i++) {
    int midiNote = midiNotes[i];
    if (digitalRead(buttons[i]) == LOW) {
      if (midiNote != currentNote) {
        MIDI.sendNoteOff(currentNote, 127, 1);
        MIDI.sendNoteOn(midiNote, 127, 1);
        currentNote = midiNote;
      }
      cycleCount = 0;
    }
  }

  if (currentNote && cycleCount > 10) {
    MIDI.sendNoteOff(currentNote, 127, 1);
    currentNote = 0;
    cycleCount = 0;
  }
  cycleCount++;
}


void readPitch() {
  int reading = analogRead(pitchPot);

  if (reading < 300) {
    reading = 300;
  }
  reading = map(reading, 300, 1023, 0, 10);
  int pitchVal = map(reading, 0, 10, -8192, 8192);

  if (pitchVal != currentPitch) {
    MIDI.sendPitchBend(pitchVal, 1);
    currentPitch = pitchVal;
  }
}
