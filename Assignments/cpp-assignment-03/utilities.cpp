#include <cstdlib>

#include "utilities.h"

int get_random_number() {
    return rand();
}

int random_with_limits(int lower_limit, int upper_limit) {
    return lower_limit + get_random_number() % (upper_limit + 1- lower_limit); // Get random int between lower- and upper
}