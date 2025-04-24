#include "Timeout.h"

Timeout::Timeout(unsigned int interval) : lastTimeout(millis()), interval(interval) {
}

bool Timeout::isTimedOut() {
    unsigned long now = millis();
    if (now > lastTimeout + interval) {
        lastTimeout = now;
        return true;
    }

    return false;
}

unsigned int Timeout::getInterval() const {
    return interval;
}

void Timeout::setInterval(unsigned int interval) {
    Timeout::interval = interval;
}

void Timeout::reset() {
    lastTimeout = millis();
}
