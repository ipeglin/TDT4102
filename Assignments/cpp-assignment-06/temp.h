#pragma once
#include "utilities.h"

class Temps {
    public:
        double max;
        double min;
        friend std::istream& operator>>(std::istream &input, const Temps &t);
};
