#pragma once
#include "utilities.h"
#include "card_deck.h"
#include "card.h"

class Blackjack {
    private:
        Card_deck deck;

        std::vector<Card> player_hand;
        std::vector<Card> dealer_hand;

        int player_hand_value{0};
        int dealer_hand_value{0};
    public:
        /**
         * @brief Construct a new Blackjack object
         * 
         */
        Blackjack();
        

        /**
         * @brief Get the value of a card
         * 
         * @param card 
         * @return int 
         */
        int get_card_value(Card &card);


        /**
         * @brief Get the total value of a hand
         * 
         * @param hand 
         * @return int 
         */
        int get_hand_value(std::vector<Card> &hand);


        /**
         * @brief Check is a card is an ace
         * 
         * @param card 
         * @return true 
         * @return false 
         */
        bool is_ace(Card &card);


        /**
         * @brief Check if the user wants to draw a card
         * 
         * @return true 
         * @return false 
         */
        bool ask_draw_card();


        /**
         * @brief Show th players hand
         * 
         */
        void show_player_hand();


        /**
         * @brief Draw card from the deck, and give to the player
         * 
         */
        void draw_player_card();


        /**
         * @brief Draw card from the deck, and give to the dealer
         * 
         */
        void draw_dealer_card();


        /**
         * @brief Run the game Blackjack
         * 
         */
        void play_game();
};