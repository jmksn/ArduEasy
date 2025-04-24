#ifndef ARDUEASY_SINGLEPINDEV_H
#define ARDUEASY_SINGLEPINDEV_H
#include "Arduino.h"

class SinglePinDev {
protected:
    uint8_t pin;
public:
    SinglePinDev(uint8_t pin);

    uint8_t getPin();
};

#endif //ARDUEASY_SINGLEPINDEV_H
