#include "Led.h"
#include "../core/DigitalOutSinglePin.h"

void Led::onDisable() {
    off();
}

Led::Led(byte pin) : DigitalOutSinglePin(pin), state(OFF), last(0), times(0) {

}

void Led::process() {
    if (state == OFF) {
        off();
    } else if (state  == ON) {
        on();
    } else {
        processBlinkStates();
    }
}

void Led::turnOn() {
    state = ON;
}

void Led::turnOff() {
    state = OFF;
}

void Led::toggle() {
    state = state == OFF ? ON : state == ON ? OFF : state;
}

void Led::blink(int onDur, int offDur) {
    state = BLINKING;
    blinkOnDur = onDur;
    blinkOffDur = offDur;
}

void Led::blinkTimes(uint8_t times, int onDur, int offDur) {
    state = BLINKING_TIMES;
    blinkOnDur = onDur;
    blinkOffDur = offDur;
    this->times = times;
}

void Led::noBlink() {
    state = OFF;
}

bool Led::isBlinking() {
    return (isEnabled() && (state == BLINKING || state == BLINKING_TIMES));
}

void Led::processBlinkStates() {
    int s = isOn();
    int duration = s ? blinkOnDur : blinkOffDur;
    long now = millis();
    if (now > last + duration) {
        last = now;

        if (isOn()) {
            off();
        } else {
            if (state == BLINKING_TIMES) {
                if (times > 0)
                    times--;
                else {
                    state = OFF;
                    return;
                }
            }
            on();
        }
    }
}
