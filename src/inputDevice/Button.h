//
// Created by jhonatan on 23/04/25.
//

#ifndef ARDUEASY_BUTTON_H
#define ARDUEASY_BUTTON_H

#include "../core/DigitalInSinglePin.h"
#include "../core/Processable.h"
#include "../core/Timeout.h"

#define DEBOUNCE 50

class Button : DigitalInSinglePin, public Processable {
private:
    void (*callback)();

    byte lastState;
    Timeout timeout;

public:

    Button(int pin);

    void process();

    void onPress(void (*callback)());
};

#endif //ARDUEASY_BUTTON_H
