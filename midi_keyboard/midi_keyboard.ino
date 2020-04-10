#define NUM_BUTTONS  7

const uint8_t button1 = 2;
const uint8_t button2 = 3;
const uint8_t button3 = 4;
const uint8_t button4 = 5;
const uint8_t button5 = 6;
const uint8_t button6 = 7;
const uint8_t button7 = 8;

const int intensityPot = 0;  // A0 input

const uint8_t buttons[NUM_BUTTONS] = {button1, button2, button3, button4, button5, button6, button7};
// const byte notePitches[NUM_BUTTONS] = {C3, D3, E3, F3, G3, A3, B3};

uint8_t notesTime[NUM_BUTTONS];
uint8_t pressedButtons = 0x00;
uint8_t previousButtons = 0x00;
uint8_t intensity;

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  for (int i = 0; i < NUM_BUTTONS; i++)
    pinMode(buttons[i], INPUT_PULLUP);
}


void loop() {
  readButtons();
  readIntensity();
  playNotes();
}


void readButtons() {
  for (int i = 0; i < NUM_BUTTONS; i++) {
    if (digitalRead(buttons[i]) == LOW) {
      Serial.print("Note: ");
      Serial.print(i);
      Serial.println();
    } else {
      
    }
  }
}

void readIntensity() {
  int val = analogRead(intensityPot);
  if (val > 500) {
    Serial.print("Pitch: ");
    Serial.print(val);
    Serial.println();
  }
}

void playNotes() {

}
