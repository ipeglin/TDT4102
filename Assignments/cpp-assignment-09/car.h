#pragma once


class Car {
    private:
        int free_seats;

    public:
        Car(int number_of_free_seats) : free_seats{number_of_free_seats} {}

        bool has_free_seats() const;
        void reserve_free_seat();
};