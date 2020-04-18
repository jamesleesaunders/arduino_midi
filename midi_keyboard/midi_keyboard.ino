/*************************************************
 * MIDI Keyboard Example
 *
 * Author: James Saunders
 *************************************************/

#include <MIDI.h>
#include "midiNote2Frequency.h"

#define NUM_BUTTONS 7
#define LED_PIN 13
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
const uint8_t midiNotes[NUM_BUTTONS] = {57, 59, 60, 62, 64, 65, 67};

int midiPitchShift;
int midiNotePlaying;

const int numReadings = 10;
int readings[numReadings];      // the readings from the analog input
int readIndex = 0;              // the index of the current reading

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  for (int i = 0; i < NUM_BUTTONS; i++) {
    pinMode(buttons[i], INPUT_PULLUP);
  }

  // Initialize all the readings to 0
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
      digitalWrite(LED_PIN, HIGH);
      if (midiNote != midiNotePlaying) {
        MyHandleNoteOff(0, midiNotePlaying, 0);
        midiNotePlaying = midiNote;
      }
      MyHandleNoteOn(0, midiNote, 0);
    }
  }
}

void MyHandleNoteOn(byte channel, byte midiNote, byte velocity) {
  digitalWrite(LED_PIN, HIGH);

  // Lookup pitch from MIDI Note
  int pitch = FreqFromMidiNote(midiNote);

  // Difference between notes is ~6%
  float pitchShift = mapfloat(midiPitchShift, 0, 127, 0.94, 1.06);
  pitch = pitch * pitchShift;

  Serial.print("Note: ");
  Serial.println(midiNote);
  Serial.print("Pitch Shift: ");
  Serial.println(pitchShift);
  Serial.print("Pitch: ");
  Serial.println(pitch);

  tone(PIEZO_PIN, pitch, 100);
}

void MyHandleNoteOff(byte channel, byte midiNote, byte velocity) {
  digitalWrite(LED_PIN, LOW);
  noTone(PIEZO_PIN);
}

void readPitch() {
  int reading = analogRead(pitchPot);

  // Smooth readings by averaging out values.
  readings[readIndex] = reading;
  // Advance to the next position in the array.
  readIndex = readIndex + 1;

  int average = arrayAverage(readings, numReadings);
  if (average < 300) {
    average = 300;
  }

  // If we're at the end of the array wrap around to the beginning.
  if (readIndex >= numReadings) {
    readIndex = 0;
  }

  Serial.print("Reading: ");
  Serial.println(average);

  // Convert to MIDI pitch shich value
  midiPitchShift = (uint8_t) (map(average, 300, 1022, 0, 127));
}

float arrayAverage(int * array, int len) {
  long sum = 0L ;  // sum will be larger than an item, long for safety.
  for (int i = 0 ; i < len ; i++)
    sum += array [i] ;
  return  ((float) sum) / len ;  // average will be fractional, so float may be appropriate.
}

float mapfloat(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
