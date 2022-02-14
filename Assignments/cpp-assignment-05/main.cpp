#include "utilities.h"
#include "card.h"
#include "card_deck.h"
#include "blackjack.h"

using namespace std;

int main() {
    srand(unsigned(time(nullptr)));

    Blackjack blackjack;
    blackjack.play_game();
}