#pragma once
#include "utilities.h"

class Person {
    private:
        const std::string first_name;
        std::string last_name;

    public:
        Person(std::string first_name, std::string last_name) : first_name{first_name}, last_name{last_name} {}

        std::string get_first_name() const;
        
        std::string get_last_name() const;
        void set_last_name(std::string new_last_name);

        std::string get_full_name() const;

        friend std::ostream &operator<<(std::ostream &os, Person &person);
};