/*************************************************
 * MIDI Out Example
 *
 * Author: James Saunders
 *************************************************/

#include <MIDI.h>
#include "midiNote2Frequency.h"

const uint8_t midiChannel = 1;

// Notes in the melody
int melody[] = {MIDI_C4, MIDI_G3, MIDI_G3, MIDI_A3, MIDI_G3, 0, MIDI_B3, MIDI_C4};

// Note durations (4 = quarter note, 8 = eighth note etc.)
int noteDurations[] = {4, 8, 8, 4, 4, 4, 4, 4};

// Created and binds the MIDI interface to the default hardware Serial port
MIDI_CREATE_DEFAULT_INSTANCE();

void setup() {
  // Listen to all incoming messages
  MIDI.begin(MIDI_CHANNEL_OMNI);
}

void loop() {
  // Iterate over the notes of the melody
  for (int thisNote = 0; thisNote < 8; thisNote++) {

    // To calculate the note duration, take one second divided by the note type.
    // e.g quarter note = 1000 / 4, eighth note = 1000/8 etc.
    int noteDuration = 1000 / noteDurations[thisNote];

    if(melody[thisNote]) {
      MIDI.sendNoteOn(melody[thisNote], 127, midiChannel);
    }

    // To distinguish the notes, set a minimum time between them.
    // The note's duration + 30% seems to work well.
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);

    // Stop the tone playing
    if(melody[thisNote]) {
      MIDI.sendNoteOff(melody[thisNote], 127, midiChannel);
    }
  }

  delay(2000);
}
