// Modes //

long sleepTimer = 0;
long sleepInterval = 5000;

void fallAsleep() {
  if (millis() - sleepTimer > sleepInterval) {
    strip.clear(); strip.show();  // Clear out NeoPixel Display
    snore(5000);                 // Go to Sleep for 5 Seconds
    sleepTimer = millis();
  }
}


void updateTime() {
  curSeconds = millis() / 1000;
  curMinutes = (curSeconds / 60) + addMin;
  curHours = (curMinutes / 60) + addHour;
}


void displayTime() {

  //Mod//
  curSeconds = curSeconds % 60;
  curMinutes = curMinutes % 60;
  curHours = curHours % 12;

  //Seconds//
  long int secondLed = curSeconds / 5;
  strip.clear();
  if (secondLed <= 11) {
    strip.setPixelColor(11 - secondLed % 12, 0, 0, 255);
    strip.show();
  }

  //Minutes//
  long int minuteLed = curMinutes / 5; //dividing minutes by 5 will give the value between 1 to 12
  if (minuteLed <= 11) {
    strip.setPixelColor(11 - minuteLed % 12, 0, 255, 0);
    strip.show();
  }

  //Hours//
  long int hourLed = curHours;

  if (hourLed <= 11) {
    strip.setPixelColor(11 - hourLed % 12, 255, 0, 0);
    strip.show();
  }
  mode = -1;
}


void setTime() {
  strip.clear();
  strip.setPixelColor(11 - (minuteLed + addMin / 5), 0, 255, 0);
  strip.setPixelColor(11 - (hourLed + addHour), 255, 0, 0);
  strip.show();
}


void rainbowMode() {
  rainbow(10);
}

void flashbang() {
  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setBrightness(100);
    strip.setPixelColor(i, 255, 255, 255);
    strip.show();
  }
}

void rainbow(int wait) {
  strip.setBrightness(15);
  for (long firstPixelHue = 0; firstPixelHue < 5 * 65536; firstPixelHue += 256) {
    buttons[0].update();
    if (buttons[0].rose()) { //Makes watch go to sleep
      strip.setBrightness(10);
      mode = -1;
    }
    for (int i = 0; i < strip.numPixels() - 1; i++) {
      int pixelHue = firstPixelHue + (i * 65536L / strip.numPixels());
      strip.setPixelColor(11 - i, strip.gamma32(strip.ColorHSV(pixelHue)));
      buttons[0].update();
      if (buttons[0].rose()) { //Makes watch go to sleep
        strip.setBrightness(10);
        mode = -1;
      }
    }
    strip.show();
    delay(wait);
    buttons[0].update();
    if (buttons[0].rose()) { //Makes watch go to sleep
      strip.setBrightness(10);
      mode = -1;
    }
  }
}
