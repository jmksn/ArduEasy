//
// Created by jhonatan on 22/04/25.
//

#ifndef ARDUEASY_ANALOGINPUTDEVICE_H
#define ARDUEASY_ANALOGINPUTDEVICE_H

#include "../core/AnalogInPinDev.h"
#include "../core/Processable.h"
#include "../utils/Between.h"

class AnalogInputDevice : public AnalogInPinDev, public Processable {
private:
    List<Between<AnalogInputDevice>> betweens;
public:
    AnalogInputDevice(int pin);

    ~AnalogInputDevice();

    Between<AnalogInputDevice> &between(double from, double to);

    void process();
};

#endif //ARDUEASY_ANALOGINPUTDEVICE_H
