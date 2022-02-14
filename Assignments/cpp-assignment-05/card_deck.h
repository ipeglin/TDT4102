#pragma once
#include "utilities.h"
#include "card.h"

class Card_deck {
    private:
        std::vector<Card> cards;
    public:
        Card_deck();

        void swap(int first_index, int last_index);
        void print();
        void shuffle();
        Card draw_card();
        int get_length();
        bool is_correct();
};
