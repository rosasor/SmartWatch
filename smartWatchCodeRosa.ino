// ATTiny 25/45/85 Neopixel Watch Code //
// CRT360 Advanced Prototyping
// Rosa Wheelen 2/8/2022


// States
#include "tinysnore.h"  // Include TinySnore Library
int mode = -1;          // -1: Sleep || 0 - Display Time || 1 - Set Time || 2 - Rainbow || 3 - Flashbang

// NeoPixels
#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel strip(13, 0, NEO_GRB + NEO_KHZ800);

// Buttons
#include <Bounce2.h>
int buttonPins[4] = {1, 2, 3, 4};
Bounce * buttons = new Bounce[4];

// Time var
long int curHours = 0;
long int curMinutes = 0;
long int curSeconds = 0;

long int addMin = 0;
long int addHour = 0;

// Set time var
long int secondLed;
long int minuteLed;
long int hourLed;



void setup() {
  initButtons();
  initNeopixels();
}

void loop() {
  updateTime();
  updateButtons();

  switch (mode) {
    case -1: fallAsleep(); break; //turn watch off
    case 0: displayTime(); break; //display time on watch
    case 1: setTime(); break; //set the watch time
    case 2: rainbowMode(); break;
    case 3: flashbang(); break;
  }
}
