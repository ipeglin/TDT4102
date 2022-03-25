#include "car.h"

Car::Car(int number_of_seats) : free_seats{number_of_seats} {}

// Car::~Car() {
//     std::cout << "Car object deleted from heap" << std::endl;
//     delete this;
// }


bool Car::has_free_seats() const {
    return (free_seats > 0);
}

void Car::reserve_seat() {
    --free_seats;
}