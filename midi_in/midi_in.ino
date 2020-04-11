/*************************************************
 * MIDI In LED Example
 *
 * Author: James Saunders
 *************************************************/

#include <MIDI.h>


#define LED 13

// Create an instance of the library with default name, serial port and settings.
MIDI_CREATE_DEFAULT_INSTANCE();

void setup() {
	// Set Arduino board pin 13 to output
  pinMode (LED, OUTPUT);

  // Initialize the MIDI Library.
  // OMNI sets it to listen to all channels..
  // MIDI.begin(2) would set it to respond to notes on channel 2 only.
  MIDI.begin(MIDI_CHANNEL_OMNI);

  // This is important!! This command tells the MIDI Library which function you want to call when a NOTE ON command
  // is received. In this case it's "MyHandleNoteOn".
  MIDI.setHandleNoteOn(MyHandleNoteOn);

  // This command tells the MIDI Library
  // to call "MyHandleNoteOff" when a NOTE OFF command is received.
  MIDI.setHandleNoteOff(MyHandleNoteOff);
}

void loop() {
	// Continuously check if MIDI data has been received.
  MIDI.read();
}

// MyHandleNoteON is the function that will be called by the MIDI Library
// when a MIDI NOTE ON message is received.
// It will be passed bytes for Channel, Note, and Velocity
void MyHandleNoteOn(byte channel, byte midiNote, byte velocity) {

	// Turn LED on
  digitalWrite(LED, HIGH);
}

// MyHandleNoteOFF is the function that will be called by the MIDI Library
// when a MIDI NOTE OFF message is received.
// * A NOTE ON message with Velocity = 0 will be treated as a NOTE OFF message *
// It will be passed bytes for Channel, Note, and Velocity
void MyHandleNoteOff(byte channel, byte midiNote, byte velocity) {
	// Turn LED off
  digitalWrite(LED, LOW);
}