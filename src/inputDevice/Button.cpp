//
// Created by jhonatan on 23/04/25.
//

#include "Button.h"

Button::Button(int pin)  : DigitalInSinglePin(pin), lastState(LOW), timeout(DEBOUNCE) {}

void Button::process() {
    if (timeout.isTimedOut()) {
        byte state = getState();
        if (state && state != lastState && callback != nullptr) {
            callback();
        }
        lastState = state;
    }
}

void Button::onPress(void (*callback)()) {
    this->callback = callback;
}