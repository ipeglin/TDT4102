#include "Person.h"

std::ostream &operator<<(std::ostream &os, const Person &person) {
    os << "Name: " << person.get_name() << std::endl
       << "Email: " << person.get_email() << std::endl
       << "Has available seats: " << person.has_available_seats() << std::endl;

    return os;
}



std::string Person::get_name() const {
    return name;
}

std::string Person::get_email() const {
    return email;
}

bool Person::has_available_seats() const {
    if (car != nullptr) {
        return car->has_free_seats();
    }

    return false;
}



void Person::set_email(std::string new_email) {
    email = new_email;
}