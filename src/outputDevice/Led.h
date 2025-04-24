//
// Created by jhonatan on 15/11/24.
//

#ifndef ARDUEASY_LED_H
#define ARDUEASY_LED_H

#include "../ArduEasy.h"
#include "../core/DigitalOutSinglePin.h"

enum LedState : uint8_t {
    OFF,
    ON,
    BLINKING,
    BLINKING_TIMES
};

class Led : DigitalOutSinglePin, public Processable {
private:
    LedState state;
    int blinkOnDur, blinkOffDur;
    uint8_t times;
    long last;

    void onDisable();
    void process();
    void processBlinkStates();

public:

    Led(byte pin);

    void turnOn();

    void turnOff();

    void toggle();

    void blink(int onDur = 500 , int offDur = 500);

    void blinkTimes(uint8_t times, int onDur = 500 , int offDur = 500);

    void noBlink();

    bool isBlinking();

};

#endif //ARDUEASY_LED_H
