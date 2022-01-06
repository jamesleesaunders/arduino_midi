/*************************************************
   MIDI Christmas Tree RGB NeoPixel Test

   Author: James Saunders
 *************************************************/

#include <Adafruit_NeoPixel.h>
#define NEO_PIN 6
#define NUM_PIXELS 7

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUM_PIXELS, NEO_PIN, NEO_RGB + NEO_KHZ800);

void setup() {
  pixels.begin();

}

void loop() {
  pixels.setPixelColor(0, pixels.Color(random(1,255), random(1,255), random(1,255)));
  pixels.setPixelColor(1, pixels.Color(random(1,255), random(1,255), random(1,255)));
  pixels.setPixelColor(2, pixels.Color(random(1,255), random(1,255), random(1,255)));
  pixels.setPixelColor(3, pixels.Color(random(1,255), random(1,255), random(1,255)));
  pixels.setPixelColor(4, pixels.Color(random(1,255), random(1,255), random(1,255)));
  pixels.setPixelColor(5, pixels.Color(random(1,255), random(1,255), random(1,255)));
  pixels.setPixelColor(6, pixels.Color(random(1,255), random(1,255), random(1,255)));
  pixels.show();
  delay(500);
}
