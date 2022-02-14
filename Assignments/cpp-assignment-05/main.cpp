#include "utilities.h"
#include "card.h"
#include "card_deck.h"
#include "blackjack.h"

using namespace std;

int main() {
    srand(unsigned(time(nullptr)));

    // Card c1{Suit::HEARTS, Rank::EIGHT};
    // Card c2{Suit::SPADES, Rank::ACE};
    // cout << c1.to_string() << endl;
    // cout << c2.to_string() << endl;

    Blackjack blackjack;
    blackjack.play_game();
}