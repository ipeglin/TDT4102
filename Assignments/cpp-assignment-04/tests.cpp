#include "tests.h"
#include "utilities.h"
#include "libs.h"

void test_call_by_value() {
    int v0{5};
    int increment{2};
    int iterations{10};

    int result{increment_by_value_num_times(v0, increment, iterations)};
    std::cout << "v0: " << v0 << " increment: " << increment << " iterations: " << iterations << " results: " << result << endl;
}

void test_call_by_reference() {
    int v0{5};
    int increment{2};
    int iterations{10};

    std::cout << "v0: " << v0 << " increment: " << increment << " iterations: " << iterations;
    increment_by_value_num_times_ref(v0, increment, iterations);
    std::cout << " results: " << v0 << endl;
}

void test_string() {
    string grades;

    vector<int> grade_count;
    vector<char> possible_grades{'A', 'B', 'C', 'D', 'E', 'F'};

    grades = randomize_string(8, 'A', 'F');

    std::cout << "Karakterer: " << grades << endl;

    for (int i = 0; i < int(possible_grades.size()); i++) {
        grade_count.push_back(count_char_in_string(grades, possible_grades.at(i)));
    }

    int total_grade_score{0};

    for (int i = 5; i > 0; i--) {
        std::cout << "i = " << to_string(i) << " (i % 5) = " << to_string(i % 5) << " CHAR: " << grade_count.at(i % 5) << endl;
        total_grade_score += (i * grade_count.at(i % 5));
    }

    double avrg_grades{static_cast<double>(total_grade_score / int(grade_count.size()))};

    std::cout << "Gjennomsnittlig karakter: " << to_string(avrg_grades) << endl;
}