/*************************************************
 * Buzzer Melody Example
 *
 * Author: James Saunders
 *************************************************/

#include "midiNote2Frequency.h"

#define BUZZER_PIN 9

// Notes in the melody.
int melody[] = {FREQ_C4, FREQ_G3, FREQ_G3, FREQ_A3, FREQ_G3, NULL, FREQ_B3, FREQ_C4};

// Note durations (4 = quarter note, 8 = eighth note etc).
int noteDurations[] = {4, 8, 8, 4, 4, 4, 4, 4};

void setup() {
}

void loop() {
  // Iterate over the notes of the melody.
  for (int thisNote = 0; thisNote < 8; thisNote++) {

    // To calculate the note duration, take one second divided by the note type.
    // e.g quarter note = 1000 / 4, eighth note = 1000/8 etc.
    int noteDuration = 1000 / noteDurations[thisNote];

    tone(BUZZER_PIN, melody[thisNote], noteDuration);

    // To distinguish the notes, set a minimum time between them.
    // The notes duration + 30% seems to work well.
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);

    // Stop the note playing.
    noTone(BUZZER_PIN);
  }

  delay(2000);
}
