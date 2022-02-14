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
        Blackjack();
        
        int get_card_value(Card &card);
        int get_hand_value(std::vector<Card> &hand);
        int get_deck_size();

        bool is_ace(Card &card);
        bool ask_draw_card();
        
        void show_player_hand();
        void draw_player_card();
        void draw_dealer_card();
        void play_game();
};