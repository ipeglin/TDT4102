#pragma once
#include "utilities.h"
#include "car.h"

class Person {
    private:
        std::string name;
        std::string email;
        std::unique_ptr<Car> car;

    public:
        Person(std::string name, std::string email, std::unique_ptr<Car> car = nullptr);
        virtual ~Person();

        friend std::ostream& operator<<(std::ostream& os, const Person& person);

        std::string get_name() const;
        std::string get_email() const;
        bool has_available_seats() const;

        void set_email(std::string new_email_address);
};