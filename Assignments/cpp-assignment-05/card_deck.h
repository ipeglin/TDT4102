#pragma once
#include "utilities.h"
#include "card.h"

class Card_deck {
    private:
        std::vector<Card> cards;
    public:
        /**
         * @brief Construct a new Card_deck object
         * 
         */
        Card_deck();

        /**
         * @brief Swap values of two values in vector by index
         * 
         * @param first_index 
         * @param last_index 
         */
        void swap(int first_index, int last_index);

        /**
         * @brief Print all cards in the deck in human readable layout
         * 
         */
        void print();

        /**
         * @brief Shuffle deck of cards
         * 
         */
        void shuffle();

        /**
         * @brief Draw the top card from the deck
         * 
         * @return Card 
         */
        Card draw_card();

        /**
         * @brief Get the current amount of cards in the deck
         * 
         * @return int 
         */
        int get_deck_size();

        /**
         * @brief Check is correctly created with 52 unique cards
         * 
         * @return true 
         * @return false 
         */
        bool is_correct();
};
