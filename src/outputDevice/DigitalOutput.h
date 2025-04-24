//
// Created by jhonatan on 23/04/25.
//

#ifndef ARDUEASY_DIGITALOUTPUT_H
#define ARDUEASY_DIGITALOUTPUT_H

#include "../core/DigitalOutSinglePin.h"
#include "../core/Processable.h"

class DigitalOutput : public DigitalOutSinglePin, public Processable {
private:
    long timeout = 0L;
    unsigned long last = 0;
public:
    DigitalOutput(uint8_t pin);

    void turnOn(long t = 0);

    void turnOff(long t = 0);

    void process();
};

#endif //ARDUEASY_DIGITALOUTPUT_H
