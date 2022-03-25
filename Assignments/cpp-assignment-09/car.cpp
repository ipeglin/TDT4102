#include "Car.h"

bool Car::has_free_seats() const {
    return (free_seats > 0);
}

void Car::reserve_free_seat() {
    --free_seats;
}