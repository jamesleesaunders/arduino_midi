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

int midiPitchShift;
int midiNotePlaying = 57;

const int numReadings = 10;
int readings[numReadings];      // the readings from the analog input
int readIndex = 0;              // the index of the current reading

// Created and binds the MIDI interface to the default hardware Serial port
MIDI_CREATE_DEFAULT_INSTANCE();

void setup() {
  // Serial.begin(9600);
  MIDI.begin(MIDI_CHANNEL_OMNI);

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
        // Serial.print("Note: ");
        // Serial.println(midiNote);
        MIDI.sendNoteOn(midiNote, 127, 1);
        delay(1000);
        MIDI.sendNoteOff(midiNote, 127, 1);
    }
  }
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

  // Convert to MIDI pitch shich value
  midiPitchShift = (uint8_t) (map(average, 300, 1022, 0, 127));

  // TODO
  // MIDI.sendPitchBend();
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
