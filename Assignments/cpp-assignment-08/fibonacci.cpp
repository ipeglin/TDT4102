#include "fibonacci.h"

void fill_in_fibonacci_numbers(int* results, int length) {
    for (int index = 0; index < length; index++) {
        if (index == 0) {
            results[index] = 0;
        } else if (index == 1) {
            results[index] = 1;
        } else {
            results[index] = results[index - 1] + results[index - 2];
        }
    }
}

void print_array(int* array, int array_length) {
    for (int index = 0; index < array_length; index++) {
        std::cout << "(Index #" << index << "): " << array[index] << std::endl;
    }
}

void create_fibonacci() {
    int sequence_length{10};
    // std::cout << "How many numbers do you want in the sequence: ";
    // std::cin >> sequence_length;
    int *fibonacci_numbers{new int[sequence_length]};
    fill_in_fibonacci_numbers(fibonacci_numbers, sequence_length);
    print_array(fibonacci_numbers, sequence_length);
    delete[] fibonacci_numbers;
}