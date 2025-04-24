#include "PostDelayedAction.h"

PostDelayedAction::PostDelayedAction(void (*callback)(), unsigned long timeout) : timeout(timeout), callback(callback),
                                                                                  lastRun(0) {}

void PostDelayedAction::reset() {
    lastRun = 0;
}

void PostDelayedAction::execute() {
    if (lastRun == 0) {
        if (callback != nullptr) {
            callback();
        }
        lastRun = millis();
    } else if (millis() > (lastRun + timeout)) {
        terminate();
    }
}