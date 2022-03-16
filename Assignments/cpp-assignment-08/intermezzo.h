#pragma once
#include "utilities.h"

class Dummy {
    public:
        int *num;
        Dummy();
        Dummy(const Dummy& dummy);
        ~Dummy();

        Dummy operator=(Dummy& dummy);
};

void dummy_test();