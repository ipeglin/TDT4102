#include "utilities.h"
#include "card.h"

Card::Card(Suit new_suit, Rank new_rank) : suit{new_suit}, rank{new_rank} {};
Card::Card() = default;

void Card::set_suit(Suit new_suit) {
    suit = new_suit;
}

Suit Card::get_suit() {
    return suit;
}

void Card::set_rank(Rank new_rank) {
    rank = new_rank;
}

Rank Card::get_rank() { 
    return rank;
}

std::string Card::to_string() {
    return rank_to_string(rank) + " of " + suit_to_string(suit);
}


std::string suit_to_string(Suit card_suit) {
    std::string suit;
    switch (card_suit) {
        case Suit::SPADES:
            suit = "Spades";
            break;
        case Suit::CLUBS:
            suit = "Clubs";
            break;
        case Suit::HEARTS:
            suit = "Hearts";
            break;
        case Suit::DIAMONDS:
            suit = "Diamonds";
            break;
        default:
            suit = "SUIT not set";
            break;
    }

    return suit;
}

std::string rank_to_string(Rank card_rank) {
    std::string rank;
    switch (card_rank) {
        case Rank::TWO:
            rank = "Two";
            break;
        case Rank::THREE:
            rank = "Three";
            break;
        case Rank::FOUR:
            rank = "Four";
            break;
        case Rank::FIVE:
            rank = "Five";
            break;
        case Rank::SIX:
            rank = "Six";
            break;
        case Rank::SEVEN:
            rank = "Seven";
            break;
        case Rank::EIGHT:
            rank = "Eight";
            break;
        case Rank::NINE:
            rank = "Nine";
            break;
        case Rank::TEN:
            rank = "Ten";
            break;
        case Rank::JACK:
            rank = "Jack";
            break;
        case Rank::QUEEN:
            rank = "Queen";
            break;
        case Rank::KING:
            rank = "King";
            break;
        case Rank::ACE:
            rank = "Ace";
            break;
        default:
            rank = "RANK not set";
            break;
    }

    return rank;
}