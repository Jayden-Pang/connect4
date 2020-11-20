// input_move.h
#ifndef INPUT_MOVE_H
#define INPUT_MOVE_H

// Converts a column into a position in the moveset array
// Input: moveset array, player move, number of turns
// Output: Corresponding position in the moveset array based on the player move
int column_to_point (int moveset[], int player_move, int turns);
// Adds player move into the moveset array and increase the array size by 1
// Input: moveset array, player move, number of turns
// Output: Modified moveset array and number of turns + 1
void add_moveset (int * &moveset, int player_move, int &turns);

#endif
