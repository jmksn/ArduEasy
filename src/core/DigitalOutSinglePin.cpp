#include "DigitalOutSinglePin.h"

DigitalOutSinglePin::DigitalOutSinglePin(uint8_t pin) : SinglePinDev(pin) {
    pinMode(pin, OUTPUT);
}

void DigitalOutSinglePin::on() {
    digitalWrite(getPin(), HIGH);
}

void DigitalOutSinglePin::off() {
    digitalWrite(getPin(), LOW);
}

bool DigitalOutSinglePin::isOn() {
    return digitalRead(getPin());
}
