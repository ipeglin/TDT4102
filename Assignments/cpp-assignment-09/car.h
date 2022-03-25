#pragma once

class Car {
    private:
        int free_seats;

    public:
        Car(int number_of_seats);
        // virtual ~Car();

        bool has_free_seats() const;
        void reserve_seat();
};