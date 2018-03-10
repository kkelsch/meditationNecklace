#include "FastLED.h"

// How many leds in your strip?
#define NUM_LEDS 1
#define DATA_PIN 0

int MIN_BRIGHTNESS = 0;
int MAX_BRIGHTNESS = 100;
uint8_t loopLength = 40; // amount of milliseconds per loop. Higher = longer light

const CRGB currentPalette[]  =
{
  CRGB::Red,
  CRGB::Ivory, 
  CRGB::Blue,
  CRGB::Green,
 
  CRGB::Blue,
  CRGB::Purple,
  CRGB::Grey,
  CRGB::LavenderBlush,
 
  CRGB::LightBlue,
  CRGB::Lavender,
  CRGB::Magenta,
  CRGB::PaleTurquoise ,
 
  CRGB::Azure,
  CRGB::Green,
  CRGB::Blue,
  CRGB::BlueViolet
};


// Define the array of leds
CRGB leds[NUM_LEDS];
int gHue = 0;

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  FastLED.setBrightness(0);
}

void loop() {
  FillLEDsFromPaletteColors(gHue);
  FastLED.show();

  // "glow" brighter
  for (int i = MIN_BRIGHTNESS; i <= MAX_BRIGHTNESS; i++) {
    FastLED.setBrightness(i);
    FastLED.show();
    delay(loopLength);
  }

    // dim
  for (int i = MAX_BRIGHTNESS; i >= 0 ; i--) {
    FastLED.setBrightness(i);
    FastLED.show();
    delay(loopLength);
  }

  // move to next color
  gHue++;
  FastLED.setBrightness(0);
  delay(500);

  if(gHue>16){  // loop back around, size of currentPalette[]
    gHue = 0;
  }

}



void FillLEDsFromPaletteColors( uint8_t colorIndex)
{ 
  for( int i = 0; i < NUM_LEDS; i++) {
    leds[i] = currentPalette[colorIndex];
  }
}


