//
// Created by jhonatan on 22/04/25.
//

#ifndef ARDUEASY_INTERVAL_H
#define ARDUEASY_INTERVAL_H

class Interval {
public:
    double from, to;

    Interval(double from, double to);

    bool contains(double v);
};

#endif //ARDUEASY_INTERVAL_H
