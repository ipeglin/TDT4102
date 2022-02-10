#include "utilities.h"
#include "tests.h"
#include "libs.h"
#include "game.h"

using namespace std;

// Oppgave 1a
/*
    v0 blir printet som 5, men result blir 25
*/


// Oppgave 2e
/*
    '#pragma once' mangler i headerfilen. Derfor kjøres denne definisjonen to ganger
*/



int main() {
    srand(unsigned(time(nullptr)));

    play_mastermind();
}