/*************************************************
 * MIDI In LED Example
 *
 * Author: James Saunders
 *************************************************/

#include <MIDI.h>

#define LED 13

// Created and binds the MIDI interface to the default hardware serial port.
MIDI_CREATE_DEFAULT_INSTANCE();

void setup() {
  // Set Arduino board pin 13 to output.
  pinMode (LED, OUTPUT);

  // Initialize the MIDI Library.
  // OMNI sets it to listen to all channels. MIDI.begin(2) would set it to respond to notes on channel 2 only.
  MIDI.begin(MIDI_CHANNEL_OMNI);

  // This is important!! This command tells the MIDI Library which function you want to call when a NOTE ON command
  // is received. In this case it's "handleNoteOn".
  MIDI.setHandleNoteOn(handleNoteOn);

  // This command tells the MIDI Library to call "handleNoteOff" when a NOTE OFF command is received.
  MIDI.setHandleNoteOff(handleNoteOff);
}

void loop() {
  // Continuously check if MIDI data has been received.
  MIDI.read();
}

// handleNoteOn() is the function that will be called by the MIDI Library when a MIDI NOTE ON message is received.
// It will be passed bytes for Channel, Note, and Velocity.
void handleNoteOn(byte channel, byte midiNote, byte velocity) {
  // Turn LED On.
  digitalWrite(LED, HIGH);
}

// handleNoteOff() is the function that will be called by the MIDI Library when a MIDI NOTE OFF message is received.
// A NOTE ON message with Velocity = 0 will be treated as a NOTE OFF message.
// It will be passed bytes for Channel, Note, and Velocity.
void handleNoteOff(byte channel, byte midiNote, byte velocity) {
  // Turn LED Off.
  digitalWrite(LED, LOW);
}
