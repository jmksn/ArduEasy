//
// Created by jhonatan on 22/04/25.
//

#include "AnalogInputDevice.h"

AnalogInputDevice::AnalogInputDevice(int pin) : AnalogInPinDev(pin) {

}

AnalogInputDevice::~AnalogInputDevice() {
    betweens.first();
    while (betweens.hasNext()) {
        delete betweens.next();
    }
}

Between<AnalogInputDevice> &AnalogInputDevice::between(double from, double to) {
    Between<AnalogInputDevice> *e = new Between<AnalogInputDevice>(*this, from, to);
    betweens.add(e);
    return *e;
}

void AnalogInputDevice::process() {
    betweens.first();
    while (betweens.hasNext()) {
        betweens.next()->testAndInvokeCallback(getValue());
    }
}