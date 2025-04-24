#ifndef ARDUEASY_TIMEOUT_H
#define ARDUEASY_TIMEOUT_H

#include "Arduino.h"

class Timeout {
private:
    unsigned long lastTimeout;
    unsigned int interval;
public:
    unsigned int getInterval() const;

    void setInterval(unsigned int interval);

    void reset();

public:
    Timeout(unsigned int interval);

    bool isTimedOut();
};


#endif //ARDUEASY_TIMEOUT_H
