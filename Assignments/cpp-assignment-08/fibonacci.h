#pragma once
#include "utilities.h"

/**
 * @brief Fill an array with a specific amount of numbers in the Fibonacci sequence
 * 
 * @param results Pointer to array
 * @param length Amount of Fibonacci numbers to store
 */
void fill_in_fibonacci_numbers(int* results, int length);

/**
 * @brief Print content of array
 * 
 * @param array Array to be displayed
 * @param array_length Amount of elements in the array
 */
void print_array(int* array, int array_length);

/**
 * @brief Create a fibonacci object
 * 
 */
void create_fibonacci();