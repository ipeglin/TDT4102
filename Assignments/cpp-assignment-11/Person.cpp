#include "Person.h"

std::string Person::get_first_name() const {
    return first_name;
}
        
std::string Person::get_last_name() const {
    return last_name;
}
void Person::set_last_name(std::string new_last_name) {
    last_name = new_last_name;
}

std::string Person::get_full_name() const {
    std::string full_name{first_name + " " + last_name};
    return full_name;
}

std::ostream &operator<<(std::ostream &os, Person &person) {
    os << "Full name: " << person.get_full_name() << std::endl;

    return os;
}