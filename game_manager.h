// game_manager.h
#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

// Prints the game rules and instructions
void print_guide_screen ();
// Allows the player to choose difficulty level and starting order
// Stores them into the inputted variables using pass-by-reference
void print_selector_screen (int &difficulty, bool &player_start);
// Runs the game based on the difficulty and starting order selected
// Input: difficulty level, player start?, load indicator, save indicator
// Output: Continuously take inputs and prints the board after each turn
void game_start (int difficulty, bool player_start, int load, int &save);

#endif
