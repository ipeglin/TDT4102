#include "person.h"

Person::Person(std::string name, std::string email, std::unique_ptr<Car> car)
    : name{name}, email{email}, car{std::make_unique<Car>(car)} {}
Person::~Person() {
    std::cout << "Person object was deleted from heap: " << this->get_name() << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Person& person) {
    os << "Name: " << person.name << std::endl
       << "Email: " << person.email << std::endl;
    
    if (person.car.get() != nullptr) {
        os << "Car: " << person.car.get() << std::endl;
    }

    return os;
}

std::string Person::get_name() const {
    return this->name;
}

std::string Person::get_email() const {
    return this->email;
}

bool Person::has_available_seats() const {
    if (this->car.get() != nullptr && this->car.get()->has_free_seats()) {
        return true;
    } else {
        return false;
    }
}

void Person::set_email(std::string new_email_address) {
    this->email = new_email_address;
}