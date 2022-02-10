#include "game.h"
#include "utilities.h"
#include "libs.h"

int check_characters_and_position(string &code, string &guess) {
    int nr_correct_positions{0};

    for (int i = 0; i < int(code.size()); i++) {
        if (code.at(i) == guess.at(i)) {
            nr_correct_positions++;
        }
    }

    return nr_correct_positions;
}

int check_characters(string &code, string &guess) {
    unordered_map<char, int> character_map{};
    int nr_correct_letters{0};

    for (char &chr : guess) {
        if (character_map.find(chr) == character_map.end()) {
            character_map.insert(pair<char, int>(chr, 0));
        }
    }

    for (char & chr : code) {
        if (character_map.find(chr) != character_map.end()) {
            character_map.at(chr)++;
        }
    }

    for (const auto &item : character_map) {
        nr_correct_letters += item.second;
    }

    return nr_correct_letters;
}

void play_mastermind() {
    constexpr int size{4};
    constexpr int letters{6};

    string guess;
    int lives{3};
    int nr_correct_letters{0};

    string code{randomize_string(size, 'A', 'A' + (letters - 1))};

    do {
        string guess{read_input_to_string(size, 'A', 'A' + (letters - 1))};
        nr_correct_letters = check_characters_and_position(code, guess);

        std::cout << "Du gjettet " << check_characters(code, guess) << " riktige bokstaver der " << nr_correct_letters << " bokstaver var på riktig plass" << endl;

        if (nr_correct_letters < size) {
            lives--;
        }

    } while (nr_correct_letters < size || lives <= 0);

    if (nr_correct_letters == size) {
        std::cout << "Gratulerer! Du vant!" << endl;
    } else {
        std::cout << "Du er veldig dårlig til å gjette!" << endl;
    }
}