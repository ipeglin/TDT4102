#pragma once
#include "utilities.h"

class Animal {
    protected:
        std::string name;
        int age;
    
    public:
        Animal(std::string name, int age) : name{name}, age{age} {};
        virtual ~Animal() {};
        virtual std::string animal_to_string() = 0;
};

class Cat : public Animal {
    public:
        Cat(std::string name, int age) : Animal{name, age} {};
        std::string animal_to_string();
};

class Dog : public Animal {
    public:
        Dog(std::string name, int age) : Animal{name, age} {};
        std::string animal_to_string();
};