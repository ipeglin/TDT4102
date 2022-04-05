#include "utilities.h"
#include "Person.h"
#include "LinkedList.h"

#pragma execution_character_set("utf-8")

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

namespace templates {
    template <typename T>
    T maximum(T first, T second) {
        return first * (first > second) + second * (first < second);
    }

    template <typename T>
    void shuffle(std::vector<T> &vec) {
        int counter{int(vec.size())};
        int i;

        while (counter) {
            i = rand() % (counter-- + 1);
            T temp_element{vec.at(counter)};
            vec.at(counter) = vec.at(i);
            vec.at(i) = temp_element;
        }
    }
}

template <typename T>
std::ostream& operator<<(std::ostream &os, std::vector<T> vec) {
    for (std::vector<T>::iterator itr = vec.begin(); itr != vec.end(); ++itr) {
        os << *itr << " ";
    }

    return os;
}


int main() {
    SetConsoleOutputCP(65001); // Setting characterset for console to UTF-8
    srand(unsigned(time(nullptr)));

    // Oppgave 1
    // a)
    std::vector<std::string> string_vector {"Lorem", "ipsum", "dolor", "sit", "amet", "consectetur", "adipiscing", "elit"};

    for (std::vector<std::string>::iterator itr = string_vector.begin(); itr != string_vector.end(); ++itr) {
        std::cout << *itr << " ";
    }
    std::cout << std::endl;


    // b)
    for (std::vector<std::string>::reverse_iterator ritr = string_vector.rbegin(); ritr != string_vector.rend(); ++ritr) {
        std::cout << *ritr << " ";
    }
    std::cout << std::endl;


    // c)
    replace_vector_element(string_vector, "Lorem", "Latin");
    for (std::vector<std::string>::iterator itr = string_vector.begin(); itr != string_vector.end(); ++itr) {
        std::cout << *itr << " ";
    }
    std::cout << std::endl;


    // d)
    std::set<std::string> string_set {"Lorem", "ipsum", "dolor", "sit", "amet", "consectetur", "adipiscing", "elit"};

    for (std::set<std::string>::iterator itr = string_set.begin(); itr != string_set.end(); ++itr) {
        std::cout << *itr << " ";
    }
    std::cout << std::endl;

    for (std::set<std::string>::reverse_iterator ritr = string_set.rbegin(); ritr != string_set.rend(); ++ritr) {
        std::cout << *ritr << " ";
    }
    std::cout << std::endl;

    replace_set_element(string_set, "Lorem", "Latin");
    for (std::set<std::string>::iterator itr = string_set.begin(); itr != string_set.end(); ++itr) {
        std::cout << *itr << " ";
    }
    std::cout << std::endl;



    // Oppgave 2
    // a)
    std::list<Person> person_list;

    Person person_1{"Ola", "Nordmann"};
    Person person_2{"Kari", "Nordmann"};

    insert_ordered_person(person_list, person_1);
    insert_ordered_person(person_list, person_2);

    for (std::list<Person>::iterator itr = person_list.begin(); itr != person_list.end(); ++itr) {
        std::cout << *itr << std::endl;
    }



    /** Oppgave 3b)
     * En lenket liste vil ha sin fordel når elementene har en tydelig relasjon mellom hverandre.
     *  Dersom informasjon i den dene noden endrer seg burde det være enkelt å navigere til andre noder som påvirkes av dette.
     *  I tillegg er løkker svært ineffektivt når det gjelder tid, der pekere til forrige- og neste node er drastisk raskere.
     * 
     * For en stack kunne man benyttet LinkedList for å holde styr på hva som er den nyeste noden som er lagt til,
     *  og hvilken node som er den neste uten å måtte iterere igjennom hele containeren på nytt, eller å måtte bruke indekser.
     * 
     */



    // Oppgave 4
    // a)
    
    int a{1};
    int b{2};
    int c{templates::maximum(a, b)};
    
    std::cout << "c er nå " << c << std::endl;

    double d{2.4};
    double e{3.2};
    double f{templates::maximum(d, e)};

    std::cout << "f er nå " << f << std::endl;


    // b)
    std::vector<int> a_vec{1, 2, 3, 4, 5, 6, 7};
    templates::shuffle(a_vec);
    std::cout << a_vec << std::endl;

    std::vector<double> b_vec{1.2, 2.2, 3.2, 4.2};
    templates::shuffle(b_vec);
    std::cout << b_vec << std::endl;

    std::vector<std::string> c_vec{"one", "two", "three", "four"};
    templates::shuffle(c_vec);
    std::cout << c_vec << std::endl;
}