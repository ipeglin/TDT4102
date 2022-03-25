#pragma once
#include "utilities.h"


class Car {
    private:
        int free_seats;

    public:
        Car(int number_of_free_seats);
        ~Car();

        bool has_free_seats() const;
        void reserve_free_seat();
};