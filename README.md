/*
# smartWatch
This code is still being worked on!
NeoPixel Based Interactive Gamer Watch
This project uses an ATTiny85 to display the time in a unique way.

 There are 4 modes:
 1. Display Time
      The time is displayed in a 12 hour format, hours are represented by the red led and minutes are 
      represented by the green led.
 2. Set Time
      Hours are represented by the red led and minutes are represented by the green led. 
      The two bottom buttons will adjust the hours and minutes. Pressing button two will reset the time being 
      set to 0 hours and 0 minutes. Pressing button one will exit the set time mode.
 3. Rainbow
      The rainbow function will light up all the neopixels to make a traveling rainbow
 4. Flashbang
      The flashlight function will just light up all the neopixels to a bright white color. 
      Pressing button one will exit the mode.
      
 Hardware:
 - Custom designed PCB with 13 neopixels and 4 buttons
 - ATTiny85 processing chip
 - CR2032 lithium battery
 - AVRISP Programming Module (for programming the ATTiny 85)
 - 
 Software:
 - Arduino.ide
 - TimeLib.h library
 - Adafruit NeoPixel library
 - Bounce2.h library
 - tinysnore.h library
 - Zadig
 - ATTiny Core
 
 */
