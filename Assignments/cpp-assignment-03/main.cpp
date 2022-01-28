
#include <iostream>
#include <stdlib.h>
#include <string>
#include <canonball.h>

using namespace std;

void test_deviation(double compare_operand, double to_operand, double max_error, string name);

int main() {
    double max_error{0.0001};

    test_deviation(velY(25, 2.5), 0.475, max_error, "velY(25, 2.5)");
    test_deviation(velY(25, 5.0), -24.05, max_error, "velY(25, 5.0)");

    test_deviation(posX(0, 50, 2.5), 125.0, max_error, "posX(0, 50, 2.5)");
    test_deviation(posX(0, 50, 5), 250.0, max_error, "posX(0, 50, 5)");
    
    test_deviation(posY(0, 25, 2.5), 31.84, max_error, "posY(0, 25, 2.5)");
    test_deviation(posY(0, 25, 5), 2.375, max_error, "posY(0, 25, 5)");
}


void test_deviation(double compare_operand, double to_operand, double max_error, string name) {
    double deviation{abs(to_operand) - abs(compare_operand)};
    cout << ((deviation > max_error) ? "Ikke korrekt" : name + " = " + to_string(to_operand)) << endl;
}