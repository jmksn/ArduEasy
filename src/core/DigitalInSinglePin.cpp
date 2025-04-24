//
// Created by jhonatan on 22/04/25.
//

#include "DigitalInSinglePin.h"

DigitalInSinglePin::DigitalInSinglePin(int pin) : SinglePinDev(pin) {
    pinMode(pin, INPUT);
}

byte DigitalInSinglePin::getState() {
    return digitalRead(getPin());
}