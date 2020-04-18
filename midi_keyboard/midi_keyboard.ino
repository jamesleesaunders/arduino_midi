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

float potValue;
int midiPitchShift;
int midiNotePlaying;

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  for (int i = 0; i < NUM_BUTTONS; i++) {
    pinMode(buttons[i], INPUT_PULLUP);
  }
}

void loop() {
  readKeys();
  readPitch();
}

float mapfloat(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
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
  float pitchShift = mapfloat(midiPitchShift, 0, 127, 0.06, 1.06);
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
  int val = analogRead(pitchPot);

  // Smooth potentiometer value
  potValue = 0.9 * val + 0.1 * analogRead(0);
  
  if (potValue < 100) {
    potValue = 100;
  }
  
  // Convert to MIDI pitch shich value
  midiPitchShift = (uint8_t) (map(potValue, 100, 255, 0, 127));
}
