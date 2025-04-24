#include "AnalogInPinDev.h"

AnalogInPinDev::AnalogInPinDev(int pin) : SinglePinDev(pin) {
    pinMode(INPUT, pin);
}

int AnalogInPinDev::getValue() {
    return analogRead(getPin());
}
