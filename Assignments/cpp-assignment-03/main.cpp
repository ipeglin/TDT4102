
#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>

#include "canonball.h"
#include "utilities.h"

using namespace std;

void test_deviation(double compare_operand, double to_operand, double max_error, string name);

int main() {
    double max_error{0.0001};
    int max_random_int{15};
    int min_random_int{3};

    srand(unsigned(time(nullptr))); // Timebased seed to generate random int

    // Testing values
    test_deviation(velY(25, 2.5), 0.475, max_error, "velY(25, 2.5)");
    test_deviation(velY(25, 5.0), -24.05, max_error, "velY(25, 5.0)");

    test_deviation(posX(0, 50, 2.5), 125.0, max_error, "posX(0, 50, 2.5)");
    test_deviation(posX(0, 50, 5), 250.0, max_error, "posX(0, 50, 5)");
    
    test_deviation(posY(0, 25, 2.5), 31.84, max_error, "posY(0, 25, 2.5)");
    test_deviation(posY(0, 25, 5), 2.375, max_error, "posY(0, 25, 5)");

    cout << "Er det korrekt avstand: " << is_correct_distance_to_target(0, 0, 0) << endl;

    cout << "Tilfeldige tall mellom " << min_random_int << " og " << max_random_int << ": " << endl;
    for (int i = 1; i <= 15; i++) {
        cout << "Number " + to_string(i) + ": " + to_string(random_with_limits(min_random_int, max_random_int)) << endl;
    }

    play_target_practice();
}

// Function returning deviation from expected output
void test_deviation(double compare_operand, double to_operand, double max_error, string name) {
    double deviation{abs(to_operand) - abs(compare_operand)};
    cout << ((deviation > max_error) ? "Ikke korrekt" : name + " = " + to_string(to_operand) + " | Korrekt") << endl;
}