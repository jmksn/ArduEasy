//
// Created by jhonatan on 22/04/25.
//

#include "Interval.h"

Interval::Interval(double from, double to) : from(from), to(to) {}

bool Interval::contains(double v)  {
    return (from <= v && v <= to);
}