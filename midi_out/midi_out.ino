/*************************************************
  MIDI Out Example

  Author: James Saunders
*************************************************/

#include <MIDI.h>
#include "midiNote2Frequency.h"

// Created and binds the MIDI interface to the default hardware Serial port
MIDI_CREATE_DEFAULT_INSTANCE();

void setup() {
  // Listen to all incoming messages
  MIDI.begin(MIDI_CHANNEL_OMNI);
}

void loop() {
  // Send note 42 with velocity 127 on channel 1
  MIDI.sendNoteOn(NOTE_C4, 127, 1);
  delay(1000);
  MIDI.sendNoteOff(NOTE_C4, 127, 1);
  delay(1000);
}
