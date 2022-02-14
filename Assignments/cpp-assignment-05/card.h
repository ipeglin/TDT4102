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
        /**
         * @brief Construct a new Card object
         * 
         * @param suit The suit of the card
         * @param rank The rank of the card
         */
        Card(Suit suit, Rank rank);
        Card();

        /**
         * @brief Set the card suit
         * 
         * @param new_suit 
         */
        void set_suit(Suit new_suit);


        /**
         * @brief Get the card suit
         * 
         * @return Suit 
         */
        Suit get_suit();


        /**
         * @brief Set the card rank
         * 
         * @param new_rank 
         */
        void set_rank(Rank new_rank);


        /**
         * @brief Get the card rank
         * 
         * @return Rank 
         */
        Rank get_rank();


        /**
         * @brief Get human readable string of cards properties
         * 
         * @return std::string 
         */
        std::string to_string();
};


/**
 * @brief Get appropriate string for card suit
 * 
 * @param card_suit
 * @return std::string 
 */
std::string suit_to_string(Suit card_suit);

/**
 * @brief Get appropriate string for card rank
 * 
 * @param card_rank 
 * @return std::string 
 */
std::string rank_to_string(Rank card_rank);