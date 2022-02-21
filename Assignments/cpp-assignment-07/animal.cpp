#include "utilities.h"
#include "animal.h"

std::string Cat::animal_to_string() {
    return "Cat: " + name + ", " + std::to_string(age);
}

std::string Dog::animal_to_string() {
    return "Dog: " + name + ", " + std::to_string(age);
}