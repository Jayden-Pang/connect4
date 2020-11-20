// ai_move.h
#ifndef AI_MOVE_H
#define AI_MOVE_H

// Determines the computer's next move based on the difficulty
// Input: moveset array, number of turns, player start?, difficulty level
// Output: an integer corresponding to the best move
int ai_move (int moveset[], int turns, bool player_start, int difficulty);

#endif
