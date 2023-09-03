#include "Display.h"
/*
  An example showing rainbow colours on a 1.8" TFT LCD screen
  and to show a basic example of font use.

  Make sure all the display driver and pin connections are correct by
  editing the User_Setup.h file in the TFT_eSPI library folder.

  Note that yield() or delay(0) must be called in long duration for/while
  loops to stop the ESP8266 watchdog triggering.

  #########################################################################
  ###### DON'T FORGET TO UPDATE THE User_Setup.h FILE IN THE LIBRARY ######
  #########################################################################
*/
#include "pin_config.h"
#include <SPI.h>
#include <Arduino.h>

void Display::init() {
    pinMode(PIN_POWER_ON, OUTPUT);
    digitalWrite(PIN_POWER_ON, HIGH);

    this->tft = new TFT_eSPI();
    this->tft->init();
    this->tft->setRotation(1);
    this->tft->fillScreen(TFT_BLACK);
}

void Display::loop() {
    // The standard ADAFruit font still works as before
    tft->setTextColor(TFT_WHITE);
    tft->setCursor(12, 5);
    tft->print("Original ADAfruit font!");

    // The new larger fonts do not use the .setCursor call, coords are embedded
    tft->setTextColor(TFT_WHITE, TFT_BLACK);  // Do not plot the background colour

    // Overlay the black text on top of the rainbow plot (the advantage of not drawing the backgorund colour!)
    tft->drawCentreString("Font size 2", 80, 14, 2);  // Draw text centre at position 80, 12 using font 2

    // tft.drawCentreString("Font size 2",81,12,2); // Draw text centre at position 80, 12 using font 2

    tft->drawCentreString("Font size 4", 80, 30, 4);  // Draw text centre at position 80, 24 using font 4

    tft->drawCentreString("12.34", 80, 54, 6);  // Draw text centre at position 80, 24 using font 6

    tft->drawCentreString("12.34 is in font size 6", 80, 92, 2);  // Draw text centre at position 80, 90 using font 2

    // Note the x position is the top left of the font!

    // draw a floating point number
    float pi = 3.14159;                                       // Value to print
    int precision = 3;                                        // Number of digits after decimal point
    int xpos = 50;                                            // x position
    int ypos = 110;                                           // y position
    int font = 2;                                             // font number only 2,4,6,7 valid. Font 6 only contains characters [space] 0 1 2 3 4 5 6 7 8 9 0 : a p m
    xpos += tft->drawFloat(pi, precision, xpos, ypos, font);  // Draw rounded number and return new xpos delta for next print position
    tft->drawString(" is pi", xpos, ypos, font);              // Continue printing from new x position
}
