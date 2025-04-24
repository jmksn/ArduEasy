//
// Created by jhonatan on 22/04/25.
//

#ifndef ARDUEASY_BETWEEN_H
#define ARDUEASY_BETWEEN_H

#include "Interval.h"

template<class C>
class Between {
private:
    Interval interval;
    C &caller;

    void (*callback)();

public:
    Between(C &caller, double from, double to);

    C &then(void (*callback)());

    void testAndInvokeCallback(double v);
};

#include "Between.tpp"
#endif //ARDUEASY_BETWEEN_H
