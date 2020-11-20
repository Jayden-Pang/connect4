// save_load.h
#ifndef SAVE_LOAD_H
#define SAVE_LOAD_H

// Save the game progress into a savefile.txt
// Input: moveset array, number of turns, player start?, difficulty level
void save_file (int moveset[], int turns, bool player_start, int difficulty);
// Check the validity of the savefile.txt when loading
int load_test ();
// Modifies all inputs based on savefile.txt
// Input: moveset array, number of turns, player start?, difficulty level
void load_file (int * &moveset, int &turns, bool &player_start, int &difficulty);


#endif
