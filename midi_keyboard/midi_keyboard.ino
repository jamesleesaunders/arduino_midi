/*************************************************
 * MIDI Keyboard Example
 *
 * Author: James Saunders
 *************************************************/

#include <MIDI.h>
#include "midiNote2Frequency.h"

#define NUM_BUTTONS 7
#define LED_PIN 13
#define BUZZER_PIN 9

const uint8_t button1 = 2;
const uint8_t button2 = 3;
const uint8_t button3 = 4;
const uint8_t button4 = 5;
const uint8_t button5 = 6;
const uint8_t button6 = 7;
const uint8_t button7 = 8;
const int intensityPot = 0;  // A0 input

const uint8_t buttons[NUM_BUTTONS] = {button1, button2, button3, button4, button5, button6, button7};
const uint8_t midiNotes[NUM_BUTTONS] = {57, 59, 60, 62, 64, 65, 67};

uint8_t intensity;

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  for (int i = 0; i < NUM_BUTTONS; i++) {
    pinMode(buttons[i], INPUT_PULLUP);
  }
}

void loop() {
  readButtons();
  readIntensity();
}

void readButtons() {
  for (int i = 0; i < NUM_BUTTONS; i++) {
    int midiNote = midiNotes[i];
    if (digitalRead(buttons[i]) == LOW) {
      digitalWrite(LED_PIN, LOW);
      MyHandleNoteOn(0, midiNote, 0);
    }
  }
}

void readIntensity() {
  int intensity = analogRead(intensityPot);
  setIntensity(intensity);
}

void MyHandleNoteOn(byte channel, byte midiNote, byte velocity) {
  digitalWrite(LED_PIN, HIGH);
  Serial.print("Note: ");
  Serial.print(midiNote);
  Serial.println();
  int frequency = FreqFromMidiNote(midiNote);
  tone(BUZZER_PIN, frequency, 500);
}

void MyHandleNoteOff(byte channel, byte miniNote, byte velocity) {
  noTone(BUZZER_PIN);
}

void setIntensity(byte val) {
  if (val < 100) {
    val = 100;
  }
  intensity = (uint8_t) (map(val, 100, 255, 0, 127));
  Serial.print("Intensity: ");
  Serial.print(intensity);
  Serial.println();
}
