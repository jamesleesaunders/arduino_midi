/*************************************************
 * MIDI All-in-one
 *
 * Author: James Saunders
 *************************************************/

#include "midiNote2Frequency.h"
#include <MIDI.h>

#define NUM_BUTTONS 7
#define NUM_NOTES 12

#define BUZZER_PIN 9
#define LED_PIN 13

const uint8_t button1 = 2;
const uint8_t button2 = 3;
const uint8_t button3 = 4;
const uint8_t button4 = 5;
const uint8_t button5 = 6;
const uint8_t button6 = 7;
const uint8_t button7 = 8;
const int pitchPot = 0;  // A0 input

const uint8_t buttons[NUM_BUTTONS] = {button1, button2, button3, button4, button5, button6, button7};
const uint8_t buttonIds[NUM_BUTTONS] = {1, 2, 4, 8, 16, 32, 64};

typedef struct {
  int buttonId;
  int midiNote;
} NoteLookup;

NoteLookup midiNotes[NUM_NOTES] = {
    {1, MIDI_C4},
    {3, MIDI_CS4},
    {2, MIDI_D4},
    {6, MIDI_DS4},
    {4, MIDI_E4},
    {8, MIDI_F4},
    {24, MIDI_FS4},
    {16, MIDI_G4},
    {48, MIDI_GS4},
    {32, MIDI_A4},
    {96, MIDI_AS4},
    {64, MIDI_B4}
};

int midiNoteFromButtonId(int buttonId) {
  for (int i = 0; i < 12; i++) {
    if (midiNotes[i].buttonId == buttonId) {
      return midiNotes[i].midiNote;
    }
  }

  return 0;
}

const uint8_t midiChannel = 1;

// The readings from the analog input.
const int numReadings = 10;
int readings[numReadings];
// The index of the current reading.
int readIndex = 0;

int currentPitch = 0;
int currentNote = 0;
float pitchVariance = 1.0;

int notePlaying = 0;

// Created and binds the MIDI interface to the default hardware serial port.
MIDI_CREATE_DEFAULT_INSTANCE();

void setup() {
  MIDI.begin(MIDI_CHANNEL_OMNI);

  // Handle incoming MIDI messages.
  MIDI.setHandleNoteOn(handleNoteOn);
  MIDI.setHandleNoteOff(handleNoteOff);
  MIDI.setHandlePitchBend(handlePitchBend);

  // Set Arduino board pin 13 to output.
  pinMode(LED_PIN, OUTPUT);

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
  int frequency = freqFromMidiNote(midiNote);

  // Apply pitch variance
  int pitch = frequency * pitchVariance;

  // Play Note
  tone(BUZZER_PIN, pitch, 2000);
  digitalWrite(LED_PIN, HIGH);
  
  notePlaying = midiNote;
}

void handleNoteOff(byte channel, byte midiNote, byte velocity) {
  // Stop Playing Note
  noTone(BUZZER_PIN);
  digitalWrite(LED_PIN, LOW);

  notePlaying = 0;
}

void handlePitchBend(byte channel, int bend) {
  // Handle Pitch Bend
  float variance = mapfloat(bend, -8192, 8192, -2, 2);
  pitchVariance = pow(2, (variance / 12));

  if (notePlaying) {
     handleNoteOn(channel, notePlaying, 0);
  }
}

void readKeys() {
  int buttonId = 0;
  for (int i = 0; i < NUM_BUTTONS; i++) {
    if (digitalRead(buttons[i]) == LOW) {
      buttonId = buttonId + buttonIds[i];
    }
  }
  
  int midiNote = midiNoteFromButtonId(buttonId);
  if (midiNote && midiNote != currentNote) {
    // It's a new note...
    MIDI.sendNoteOff(currentNote, 127, midiChannel);
    MIDI.sendNoteOn(midiNote, 127, midiChannel);
    currentNote = midiNote;
  }

  if (!midiNote && currentNote) {
    // Turn everything off...
    for (int i = 0; i < NUM_NOTES; i++) {
      int midiNote = midiNotes[i].midiNote;
      MIDI.sendNoteOff(midiNote, 127, midiChannel);
    }
    currentNote = 0;
  }
}

void readPitch() {
  int reading = analogRead(pitchPot);

  // Smooth readings by averaging values.
  readings[readIndex] = reading;
  // Advance to the next position in the array.
  readIndex = readIndex + 1;

  int average = arrayAverage(readings, numReadings);

  // If we're at the end of the array wrap around to the beginning.
  if (readIndex >= numReadings) {
    readIndex = 0;
  }

  // Map pot readings into 24 bands.
  // https://forum.arduino.cc/index.php?topic=266687.0
  int bandValue = map(average, 0, 1024, -12, 12);

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

float arrayAverage(int * array, int len) {
  long sum = 0L ;  // Sum will be larger than an item, long for safety.
  for (int i = 0 ; i < len ; i++) {
    sum += array [i];
  }
  return  ((float) sum) / len ;  // Average will be fractional, so float may be appropriate.
}
