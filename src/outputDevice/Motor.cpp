//
// Created by jhonatan on 23/04/25.
//

#include "Motor.h"

int Motor::speedConvert(int value) {
    return 2.55 * value;
}

Motor::Motor(byte pinA, byte pinB, byte pinEnable) : pinA(pinA), pinB(pinB), pinEnable(pinEnable), timeout(0) {
    pinMode(pinA, OUTPUT);
    pinMode(pinB, OUTPUT);
    pinMode(pinEnable, OUTPUT);

    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, LOW);
    digitalWrite(pinEnable, LOW);
}

void Motor::process() {
    if (timeout.getInterval() != 0 && timeout.isTimedOut()) {
        turnOff();
    }
}

void Motor::turnOff() {
    timeout.setInterval(0);
    digitalWrite(pinEnable, LOW);
}

void Motor::turnOn(int speed, unsigned long duration = 0) {
    int rSpeed = speed < 0 ? -speed : speed;
    timeout.setInterval(duration);
    if (speed > 0) {
        digitalWrite(pinA, HIGH);
        digitalWrite(pinB, LOW);
    } else {
        digitalWrite(pinA, LOW);
        digitalWrite(pinB, HIGH);
    }
    analogWrite(pinEnable, speedConvert(rSpeed));
}