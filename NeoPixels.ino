// NeoPixel Functions // 

void initNeopixels() {
  strip.begin();
  strip.clear();
  strip.show();
  strip.setBrightness(10);
}
