#include "blackjack.h"

Blackjack::Blackjack() {
    deck.shuffle();
};

bool Blackjack::is_ace(Card &card) {
    return (card.get_rank() == Rank::ACE);
}

int Blackjack::get_card_value(Card &card) {
    int card_value;
    switch (card.get_rank()) {
        case Rank::ACE:
            card_value = 11;
            break;
        case Rank::JACK:
            card_value = 10;
            break;
        case Rank::QUEEN:
            card_value = 10;
            break;
        case Rank::KING:
            card_value = 10;
            break;
        default:
            card_value = static_cast<int>(card.get_rank());
            break;
    }

    return card_value;
}

int Blackjack::get_hand_value(std::vector<Card> &hand) {
    int hand_value{0};

    for (Card &card : hand) {
        if (card.get_rank() != Rank::ACE) {
            hand_value += get_card_value(card);
        } else {
            if (hand_value + get_card_value(card) <= 21) {
                hand_value += get_card_value(card);
            } else {
                hand_value += 1;
            }
        }
    }

    return hand_value;
}

void Blackjack::show_player_hand() {
    for (Card &card : player_hand) {
        std::cout << "\t" << card.to_string() << std::endl;
    }
}

bool Blackjack::ask_draw_card() {
    char answer;

    std::cout << "Do you wish to draw (y/n): ";
    std::cin >> answer;
    std::cout <<  std::endl;

    return (answer == 'y') ? true : false;
}

int Blackjack::get_deck_size() {
    return (deck.get_length());
}

void Blackjack::draw_player_card() {
    player_hand.push_back(deck.draw_card());
    player_hand_value = get_hand_value(player_hand);
}

void Blackjack::draw_dealer_card() {
    dealer_hand.push_back(deck.draw_card());
    dealer_hand_value = get_hand_value(dealer_hand);
}

void Blackjack::play_game() {
    bool still_playing{true};
    do {
        if (ask_draw_card()) {
            draw_player_card();
            std::cout << "Your hand: " << player_hand_value << std::endl;
            show_player_hand();
            std::cout << std::endl;
        } else {
            still_playing = false;
        }

        if (dealer_hand_value < 17) {
            draw_dealer_card();
        }
    } while (player_hand_value < 21 && still_playing);

    if ((player_hand_value == 21 && player_hand_value != dealer_hand_value) || (player_hand_value < 21 && player_hand_value > dealer_hand_value) || (player_hand_value < 21 && dealer_hand_value > 21)) {
        std::cout << "Gratulerer! Du vant!" << std::endl << "Player: " << player_hand_value << std::endl << "Dealer: " << dealer_hand_value << std::endl; 
    } else {
        std::cout << "Du tapte dessverre" << std::endl << "Player: " << player_hand_value << std::endl << "Dealer: " << dealer_hand_value << std::endl;
    }
}