#include "utilities.h"
#include "Person.h"

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

void insert_ordered_person(std::list<Person> &list, const Person &person) {
    if (list.size() == 0) {
        list.insert(list.begin(), person);
        return;
    }

    for (std::list<Person>::iterator it = list.begin(); it != list.end(); ++it) {
        Person current_person{*it};
        if (person.get_first_name().at(0) < current_person.get_first_name().at(0)) {
            list.insert(it, person);
            return;
        }
    }
}



int main() {
    // // Oppgave 1
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



    // // Oppgave 2
    // // a)
    // std::list<Person> person_list;

    // Person person_1{"Ola", "Nordmann"};
    // Person person_2{"Kari", "Nordmann"};

    // insert_ordered_person(person_list, person_1);
    // insert_ordered_person(person_list, person_2);

    // for (std::list<Person>::iterator itr = person_list.begin(); itr != person_list.end(); ++itr) {
    //     std::cout << *itr << std::endl;
    // }



    // Oppgave 3
    
}