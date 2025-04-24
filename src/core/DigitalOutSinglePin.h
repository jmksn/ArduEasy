#ifndef ARDUEASY_DIGITALOUTSINGLEPIN_H
#define ARDUEASY_DIGITALOUTSINGLEPIN_H

#include "SinglePinDev.h"
#include "Arduino.h"

class DigitalOutSinglePin : SinglePinDev {
public:
    DigitalOutSinglePin(uint8_t pin);

    virtual void on();

    virtual void off();

    virtual bool isOn();
};

#endif //ARDUEASY_DIGITALOUTSINGLEPIN_H
