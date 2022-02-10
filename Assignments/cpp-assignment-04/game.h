#pragma once
#include "libs.h"

/**
 * @brief Function that runs the game Mastermind.
 * 
 */
void play_mastermind();

/**
 * @brief Function that returns the amount of correctly guessed letters.
 * 
 * @param code The correct code to be guessed
 * @param guess The guessed code passed by the user
 * @return int
 */
int check_characters_and_position(string &code, string &guess);

/**
 * @brief Function that returns the amount of guessed letters that consists in the correct code.
 * 
 * @param code The correct code to be guessed
 * @param guess The guessed code passed by the user
 * @return int 
 */
int check_characters(string &code, string &guess);