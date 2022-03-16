#include "strings.h"
#include "utilities.h"

void string_to_upper(std::string &input_string) {
    transform(input_string.begin(), input_string.end(), input_string.begin(), ::toupper);
}

void string_to_lower(std::string &input_string) {
    transform(input_string.begin(), input_string.end(), input_string.begin(), ::tolower);
}