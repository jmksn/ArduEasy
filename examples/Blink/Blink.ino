#include "ArduEasy.h"

Led led(LED_BUILTIN);

void setup() {
    led.blink(1000, 1000);
}

void loop() {
    ArduEasy::run();
}
