#include "utilities.h"

void replace_vector_element(std::vector<std::string> &str_vec, std::string old_str, std::string new_str) {
    for (std::vector<std::string>::iterator itr = str_vec.begin(); itr != str_vec.end(); ++itr) {
        if (*itr == old_str) {
            itr = str_vec.erase(itr);
            itr = str_vec.insert(itr, new_str);
        }
    }
}

void replace_set_element(std::set<std::string> &str_set, std::string old_str, std::string new_str) {
    for (std::set<std::string>::iterator itr = str_set.begin(); itr != str_set.end(); ++itr)  {
        if (*itr == old_str) {
            itr = str_set.erase(itr);
            itr = str_set.insert(itr, new_str);
        }
    }
}

int main() {
    // Oppgave 1
    // // a)
    // std::vector<std::string> string_vector {"Lorem", "ipsum", "dolor", "sit", "amet", "consectetur", "adipiscing", "elit"};

    // for (std::vector<std::string>::iterator itr = string_vector.begin(); itr != string_vector.end(); ++itr) {
    //     std::cout << *itr << " ";
    // }
    // std::cout << std::endl;


    // // b)
    // for (std::vector<std::string>::reverse_iterator ritr = string_vector.rbegin(); ritr != string_vector.rend(); ++ritr) {
    //     std::cout << *ritr << " ";
    // }
    // std::cout << std::endl;


    // // c)
    // replace_vector_element(string_vector, "Lorem", "Latin");
    // for (std::vector<std::string>::iterator itr = string_vector.begin(); itr != string_vector.end(); ++itr) {
    //     std::cout << *itr << " ";
    // }
    // std::cout << std::endl;


    // // d)
    // std::set<std::string> string_set {"Lorem", "ipsum", "dolor", "sit", "amet", "consectetur", "adipiscing", "elit"};

    // for (std::set<std::string>::iterator itr = string_set.begin(); itr != string_set.end(); ++itr) {
    //     std::cout << *itr << " ";
    // }
    // std::cout << std::endl;

    // for (std::set<std::string>::reverse_iterator ritr = string_set.rbegin(); ritr != string_set.rend(); ++ritr) {
    //     std::cout << *ritr << " ";
    // }
    // std::cout << std::endl;

    // replace_set_element(string_set, "Lorem", "Latin");
    // for (std::set<std::string>::iterator itr = string_set.begin(); itr != string_set.end(); ++itr) {
    //     std::cout << *itr << " ";
    // }
    // std::cout << std::endl;

    // Oppgave 2
    // a)
    
}