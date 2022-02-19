#include "utilities.h"
#include "files.h"
#include "strings.h"
#include "course_catalog.h"
#include "temp.h"

using namespace std;

int main() {
    string test_file{"test.txt"};

    // vector<string> word_vector{get_words_from_user()};
    // write_words_to_file(word_vector, test_file);
    // rewrite_to_new_file(test_file, "new.txt");

    // std::map<char, int> character_map{get_character_map("grunnlov.txt")};
    // show_character_map(character_map);

    // The [] operator is not supported for maps. Only arrays and vectors

    Course_catalog cc;

    // insert() does not overwrite map values, but the [] operator does

    cout << cc;

    ifstream temp_file{"temperatures.txt"};
    Temps t;
    temp_file >> t;
}