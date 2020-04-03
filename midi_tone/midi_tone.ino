# include <MIDI.h>  // Add Midi Library
# include "midiNote2Frequency.h"

#define LED_PIN 13    // Arduino Board LED is on Pin 13
#define TONE_PIN 8

//Create an instance of the library with default name, serial port and settings
MIDI_CREATE_DEFAULT_INSTANCE();

void setup() {
  pinMode (LED_PIN, OUTPUT); // Set Arduino board pin 13 to output
  MIDI.begin(MIDI_CHANNEL_OMNI);
  MIDI.setHandleNoteOn(MyHandleNoteOn); // This is important!! This command
  MIDI.setHandleNoteOff(MyHandleNoteOff); // This command tells the Midi Library 
}

void loop() { // Main loop
  MIDI.read(); // Continuously check if Midi data has been received.
}

void MyHandleNoteOn(byte channel, byte midiNote, byte velocity) { 
  digitalWrite(LED_PIN, HIGH);  // Turn LED on
  int frequency = FreqFromMidiNote(midiNote);
  tone(8, frequency, 2000);
}

void MyHandleNoteOff(byte channel, byte miniNote, byte velocity) { 
  digitalWrite(LED_PIN, LOW);  // Turn LED off
  noTone(8);
}
