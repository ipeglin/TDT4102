#include "files.h"

std::vector<std::string> get_words_from_user() {
    std::string input_string;
    std::vector<std::string> string_vector;

    do {
        std::cout << "New word: ";
        std::cin >> input_string;
        string_vector.push_back(input_string);
    } while (input_string != "quit");

    string_vector.pop_back();

    return string_vector;
}

void write_words_to_file(std::vector<std::string> &string_vector, std::string file_path) {
    std::ofstream output_stream;
    output_stream.open(file_path);

    for (std::string &word : string_vector) {
        output_stream << word << std::endl;
    }

    output_stream.close();
}

void rewrite_to_new_file(std::string reference_file, std::string target_file) {
    if (std::ifstream{reference_file}) {
        std::ifstream reference_stream{reference_file};
        std::ofstream target_stream{target_file};

        std::string line;
        int line_number{1};

        while (getline(reference_stream, line)) {
            target_stream << line_number << " " << line << std::endl;
            line_number++;
        }
    } else {
        std::cout << "this doesnt exist" << std::endl;
    }
}

std::map<char, int> get_character_map(std::string file_path) {
    std::map<char, int> character_map;

    if (std::ifstream{file_path}) {
        std::ifstream input_stream{file_path};

        char character;
        while (input_stream >> character) {
            character = tolower(character);

            if (character >= 97 && character <=122) {
                if (character_map.find(character) == character_map.end()) {
                    character_map.insert(std::pair<char, int>(character, 1));
                } else {
                    character_map.at(character)++;
                }
            }
        }
    }

    return character_map;
}

void show_character_map(std::map<char, int> &map) {
    for (const auto &item : map) {
        std::cout << item.first << " : " << item.second << std::endl;
    }
}