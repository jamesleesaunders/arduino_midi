/*************************************************
 * Buzzer Keyboard Example
 *
 * Author: James Saunders
 *************************************************/

#include "midiNote2Frequency.h"

#define NUM_BUTTONS 7
#define PIEZO_PIN 9

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

float pitchVariance;
int currentNote;

// The readings from the analog input.
const int numReadings = 10;
int readings[numReadings];
// The index of the current reading.
int readIndex = 0;

void setup() {
  // Initialize buttons.
  for (int i = 0; i < NUM_BUTTONS; i++) {
    pinMode(buttons[i], INPUT_PULLUP);
  }

  // Initialize all the pitch shift readings to 0.
  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readings[thisReading] = 0;
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
        noTone(PIEZO_PIN);
        currentNote = midiNote;
      }
      
      // Lookup frequency from MIDI Note.
      int frequency = freqFromMidiNote(midiNote);

      // Apply pitch variance.
      int pitch = frequency * pow(2, (pitchVariance / 12));

      // Play Note.
      tone(PIEZO_PIN, pitch, 100);
    }
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

  pitchVariance = mapfloat(average, 0, 1023, -2, 2);
}

float arrayAverage(int * array, int len) {
  long sum = 0L ;  // Sum will be larger than an item, long for safety.
  for (int i = 0 ; i < len ; i++) {
    sum += array [i];
  }
  return  ((float) sum) / len ;  // Average will be fractional, so float may be appropriate.
}

float mapfloat(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
