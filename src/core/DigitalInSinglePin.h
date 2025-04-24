//
// Created by jhonatan on 22/03/2020.
//

#ifndef ARDUEASY_DIGITALINSINGLEPIN_H
#define ARDUEASY_DIGITALINSINGLEPIN_H

#include "SinglePinDev.h"
class DigitalInSinglePin : SinglePinDev {
public:
    DigitalInSinglePin(int pin);
    byte getState();
};
#endif //ARDUEASY_DIGITALINSINGLEPIN_H