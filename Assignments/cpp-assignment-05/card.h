#pragma once
#include "utilities.h"

enum class Suit {
    SPADES = 0,
    CLUBS,
    HEARTS,
    DIAMONDS
};

enum class Rank {
    ACE = 1,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING
};

class Card {
    private:
        Suit suit;
        Rank rank;
    public:
        Card(Suit suit, Rank rank);
        Card();

        void set_suit(Suit new_suit);
        Suit get_suit();

        void set_rank(Rank new_rank);
        Rank get_rank();

        std::string to_string();
};

std::string suit_to_string(Suit card_suit);
std::string rank_to_string(Rank card_rank);