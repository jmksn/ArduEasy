//
// Created by jhonatan on 22/03/2020.
//

#ifndef ARDUEASY_ANALOGINPINDEV_H
#define ARDUEASY_ANALOGINPINDEV_H

#include "SinglePinDev.h"
class AnalogInPinDev : SinglePinDev {
public:
    AnalogInPinDev(int pin);

    int getValue();
};
#endif //ARDUEASY_ANALOGINPINDEV_H
