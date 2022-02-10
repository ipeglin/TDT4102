#include "utilities.h"
#include "libs.h"

int increment_by_value_num_times(int num_for_incrementation, int increment, int amount_of_times) {
    for (int i = 0; i < amount_of_times; i++) {
        num_for_incrementation += increment;
    }
    return num_for_incrementation;
}

void increment_by_value_num_times_ref(int &num_for_incrementation, int increment, int amount_of_times) {
    for (int i = 0; i < amount_of_times; i++) {
        num_for_incrementation += increment;
    }
}

void swap_numbers(int &var1, int &var2) {
    vector<int> char_vector{var1, var2};

    var1 = char_vector.at(1);
    var2 = char_vector.at(0);
}

void print_student(Student student) {
    std::cout << "Student" << endl
              << "Name: " << student.name << endl
              << "Age: " << to_string(student.age) << endl
              << "Study Program: " << student.study_program << endl;
}

bool is_in_program(Student student, string program) {
    return (student.study_program == program);
}

string randomize_string(int string_length, char lower_limit, char upper_limit) {
    string temp_string;

    for (int i = 0; i < string_length; i++) {
        temp_string += to_string(char(lower_limit + rand() % (upper_limit + 1 - lower_limit)));
    }

    return temp_string;
}

void string_to_upper(string &string) {
    transform(string.begin(), string.end(), string.begin(), ::toupper);
}

void string_to_lower(string &string) {
    transform(string.begin(), string.end(), string.begin(), ::tolower);
}

string read_input_to_string(int string_length, char lower_limit, char upper_limit) {
    string input_string;
    std::vector<char> char_vector;
    bool is_out_of_bounds;

    lower_limit = toupper(lower_limit);
    upper_limit = toupper(upper_limit);

    std::cout << "LIMITS: " << lower_limit << " < x < " << upper_limit << endl;

    do {
        std::cout << "Skriv en streng med lengde " << to_string(string_length) << " med bokstaver mellom [" << to_string(lower_limit) << ", " << to_string(upper_limit) << "]" << endl
                  << "Tekststreng: ";
        std::cin >> input_string;

        if (int(input_string.size()) != string_length) {
            is_out_of_bounds = true;
            continue;
        }

        string temp_string{input_string};
        string_to_upper(temp_string);

        for (int i = 0; i < int(temp_string.size()); i++) {
            char_vector.push_back(int(temp_string.at(i)));
        }

        for (int i = 0; i < int(char_vector.size()); i++) {
            if (char_vector.at(i) < lower_limit || char_vector.at(i) > upper_limit) {
                is_out_of_bounds = true;
                break;
            }
        }
    } while (is_out_of_bounds);

    return input_string;
}

int count_char_in_string(string &input_string, char &input_char) {
    int counter{0};
    
    for (auto &chr : input_string) {
        if (chr == input_char) {
            counter++;
        }
    }

    return counter;
}