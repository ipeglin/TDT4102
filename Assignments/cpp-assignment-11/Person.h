#pragma once
#include "utilities.h"

class Person {
    private:
        const std::string first_name;
        std::string last_name;

    public:
        /**
         * @brief Construct a new Person object
         * 
         * @param first_name First name of person
         * @param last_name Surname of person
         */
        Person(std::string first_name, std::string last_name) : first_name{first_name}, last_name{last_name} {}
        
        friend std::ostream &operator<<(std::ostream &os, Person &person);

        /**
         * @brief Get the first name object
         * 
         * @return std::string
         */
        std::string get_first_name() const;
        
        /**
         * @brief Get the last name object
         * 
         * @return std::string 
         */
        std::string get_last_name() const;


        /**
         * @brief Set the last name object
         * 
         * @param new_last_name New surname of person
         */
        void set_last_name(std::string new_last_name);

        /**
         * @brief Get the full name object
         * 
         * @return std::string 
         */
        std::string get_full_name() const;
};