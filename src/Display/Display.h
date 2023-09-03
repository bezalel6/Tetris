#pragma once
#include <util.h>
#include <TFT_eSPI.h>  // Graphics and font library for ST7735 driver chip

class Display {
    SINGLETON(Display);

   public:
    void init();
    void loop();

   private:
    TFT_eSPI* tft;
};