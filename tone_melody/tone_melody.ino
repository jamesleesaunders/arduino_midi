/*************************************************
 * MIDI Pitches Example
 *
 *************************************************/

# include "midiNote2Frequency.h"

#define BUZZER_PIN 9

// Notes in the melody
int melody[] = {NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4};

// Note durations (4 = quarter note, 8 = eighth note etc.)
int noteDurations[] = {4, 8, 8, 4, 4, 4, 4, 4};

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  
  // Iterate over the notes of the melody
  for (int thisNote = 0; thisNote < 8; thisNote++) {

    // To calculate the note duration, take one second divided by the note type.
    // e.g quarter note = 1000 / 4, eighth note = 1000/8 etc.
    int noteDuration = 1000 / noteDurations[thisNote];

    digitalWrite(LED_BUILTIN, HIGH);
    tone(BUZZER_PIN, melody[thisNote], noteDuration);
    digitalWrite(LED_BUILTIN, LOW);

    // To distinguish the notes, set a minimum time between them.
    // The note's duration + 30% seems to work well.
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);

    // Stop the tone playing
    noTone(BUZZER_PIN);
  }
}

void loop() {
}
