#include "Car.h"

Car::Car(int number_of_free_seats) : free_seats{number_of_free_seats} {}

Car::~Car() {
    std::cout << "Instance deleted (Car)" << std::endl;
}



bool Car::has_free_seats() const {
    return (free_seats > 0);
}

void Car::reserve_free_seat() {
    --free_seats;
}