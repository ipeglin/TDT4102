#include "utilities.h"
#include "card_deck.h"
#include "card.h"

Card_deck::Card_deck() {
    for (int i = 0; i <= static_cast<int>(Suit::DIAMONDS); i++) {
            for (int l = 1; l <= static_cast<int>(Rank::KING); l++) {
                Card new_card{static_cast<Suit>(i), static_cast<Rank>(l)};
                cards.push_back(new_card);
            }
        }
}

void Card_deck::swap(int first_index, int last_index) {
    Card temp{cards.at(last_index)};

    cards.at(last_index) = cards.at(first_index);
    cards.at(first_index) = temp;
}

void Card_deck::print() {
    for (Card &card : cards) {
        std::cout << card.to_string() << std::endl;
    }
}

void Card_deck::shuffle() {
    int counter{int(cards.size())};
    int i;

    while (counter) {
        i = rand() % (counter-- + 1);
        Card temp_card{cards.at(counter)};
        cards.at(counter) = cards.at(i);
        cards.at(i) = temp_card;
    }
}

Card Card_deck::draw_card() {
    Card top_card = cards.back();
    cards.pop_back();
    return top_card;
}

int Card_deck::get_deck_size() {
    return int(cards.size());
}

bool Card_deck::is_correct() {
    std::unordered_map<std::string, int> card_map;
    int deck_size{0};
    bool correct_deck{true};

    for (Card &card : cards) {
        std::string card_name{card.to_string()};
        if (card_map.find(card_name) == card_map.end()) {
            card_map.insert(std::pair<std::string, int>(card_name, 1));
        } else {
            card_map.at(card_name)++;
        }
    }

    for (const auto &item : card_map) {
        deck_size += item.second;

        if (item.second > 1) {
            std::cout << "The deck has a duplicate card: '" << item.first << "'" << std::endl;
            correct_deck = false;
            // break;
        }
    }

    if (deck_size != 52) {
        std::cout << "The deck is too large" << std::endl;
        correct_deck = false;
    }

    return correct_deck;
}