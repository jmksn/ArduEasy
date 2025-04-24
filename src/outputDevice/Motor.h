//
// Created by jhonatan on 23/04/25.
//

#ifndef ARDUEASY_MOTOR_H
#define ARDUEASY_MOTOR_H

#include "../core/Timeout.h"
#include "../core/Processable.h"

class Motor : public Processable {
private:
    byte pinA;
    byte pinB;
    byte pinEnable;

    Timeout timeout;

    static int speedConvert(int value);

public:
    Motor(byte pinA, byte pinB, byte pinEnable);

    void process();

    void turnOff();

    void turnOn(int speed, unsigned long duration = 0);

};


#endif //ARDUEASY_MOTOR_H
