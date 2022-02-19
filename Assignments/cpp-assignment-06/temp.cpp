#include "temp.h"

std::istream& operator>>(std::istream &input, Temps &t) {
    std::string temp_string;
    input >> temp_string;

    // Theres an error here.
    // t.max = std::stod(temp_string.substr(0, temp_string.find(",")));
    // t.min = std::stod(temp_string.substr(temp_string.find(",") + 1));
}