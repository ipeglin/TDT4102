#pragma once
#include "libs.h"

/**
 * @brief Structs for a student that has a name, study_program and age.
 * 
 */
struct Student {
    string name;
    string study_program;
    int age;
    
    /**
     * @brief Construct a new Student object
     * 
     * @param name Name of the student.
     * @param study_program The study program the student is enrolled in.
     * @param age Age of the student.
     */
    Student(string name, string study_program, int age);
};

/**
 * @brief Increment a number by value n number of times.
 * 
 * @param num_for_incrementation The number that is to be incremented.
 * @param increment The amount the number will be incremented by.
 * @param amount_of_times The amount of times the incrementation is going to happen.
 * @return int
 */
int increment_by_value_num_times(int num_for_incrementation, int increment, int amount_of_times);

/**
 * @brief Increment a number by reference n number of times.
 * 
 * @param num_for_incrementation The number that is to be incremented.
 * @param increment The amount the number will be incremented by.
 * @param amount_of_times The amount of times the incrementation is going to happen.
 */
void increment_by_value_num_times_ref(int &num_for_incrementation, int increment, int amount_of_times);


/**
 * @brief Swaps the int values for two variables.
 * 
 * @param var1 First integer variable.
 * @param var2 Second integer variable.
 */
void swap_numbers(int &var1, int &var2);

/**
 * @brief Prints information about the student.
 * 
 * @param student Student object.
 */
void print_student(Student student);

/**
 * @brief Check if a student is in a study program.
 * 
 * @param student Student object.
 * @param program The study program to check if student is enrolled in.
 * @return true The student is in the study program.
 * @return false The student is not in the study program.
 */
bool is_in_program(Student student, string program);

/**
 * @brief Generate a string of length L with random characters in given interval.
 * 
 * @param string_length The length of the wanted string.
 * @param lower_limit The character with the lowest allowed ASCII decimal value.
 * @param upper_limit The character with the highest allowed ASCII decimal value.
 * @return string 
 */
string randomize_string(int string_length, char lower_limit, char upper_limit);

/**
 * @brief Prompt user to input a string with length L with characters in a given interval.
 * 
 * @param string_length The length of the wanted string.
 * @param lower_limit The character with the lowest allowed ASCII decimal value.
 * @param upper_limit The character with the highest allowed ASCII decimal value.
 * @return string 
 */
string read_input_to_string(int string_length, char lower_limit, char upper_limit);

/**
 * @brief Convert string to upper.
 * 
 * @param string String to be transformed to upper case.
 */
void string_to_upper(string &string);

/**
 * @brief Convert string to lower.
 * 
 * @param string String to be transformed to lower case.
 */
void string_to_lower(string &string);

/**
 * @brief Count the amount of occurrences of a character in a string.
 * 
 * @param input_string String for searching.
 * @param input_char Character to be searched for.
 * @return int 
 */
int count_char_in_string(string &input_string, char &input_char);