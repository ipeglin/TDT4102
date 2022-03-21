#include "car.h"
#include "utilities.h"

Car::Car(int number_of_seats) : free_seats{number_of_seats} {}


bool Car::has_free_seats() const {
    return (this->free_seats > 0);
}

void Car::reserve_seat() {
    this->free_seats--;
}