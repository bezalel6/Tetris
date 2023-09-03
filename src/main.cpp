#include "Arduino.h"
#include "Display/Display.h"

void setup() {
    Serial.begin(115200);

    Display::getInstance().init();
}

void loop() {
    Display::getInstance().loop();
}
