#pragma once
#include "utilities.h"

std::vector<std::string> get_words_from_user();
void write_words_to_file(std::vector<std::string> &string_vector, std::string file_path);
void rewrite_to_new_file(std::string referance_file, std::string target_file);
std::map<char, int> get_character_map(std::string file_path);
void show_character_map(std::map<char, int> &map);