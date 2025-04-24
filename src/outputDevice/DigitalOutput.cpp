//
// Created by jhonatan on 23/04/25.
//

#include "DigitalOutput.h"

DigitalOutput::DigitalOutput(uint8_t pin) : DigitalOutSinglePin(pin) {}

void DigitalOutput::turnOn(long t = 0) {
    on();
    if (t) {
        timeout = t;
        last = millis();
    }
}

void DigitalOutput::turnOff(long t = 0) {
    off();
    if (t) {
        timeout = -t;
        last = millis();
    }
}

void DigitalOutput::process() {
    if (timeout != 0 && (millis() - last > abs(timeout))) {
        timeout > 0 ? turnOff() : turnOn();
    }
}