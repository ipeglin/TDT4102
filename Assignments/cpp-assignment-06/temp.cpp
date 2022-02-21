#include "temp.h"

std::istream& operator>>(std::istream& is, Temps& t) {
    std::string input_string;
    is >> input_string;
    std::cout << "MAX '" << input_string.substr(0, input_string.find("\t")) << "' MIN '" << input_string.substr(input_string.find("\t") + 1) << "'" << std::endl;

    return is;

    // This is where it all goes wrong. How does >> overloading work?
    // t.max = std::stod(input_string.substr(0, input_string.find("\t")));
    // t.min = std::stod(input_string.substr(input_string.find("\t") + 1));

}