#pragma once
#include "utilities.h"

class Temps {
    public:
        double max;
        double min;
        friend std::istream& operator>>(std::istream& is, Temps& t);
};

std::vector<Temps> read_temps(std::string file_path);
void temp_stats(std::vector<Temps> temp_vector);