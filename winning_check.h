// winning_check.h
#ifndef WINNING_CHECK_H
#define WINNING_CHECK_H

// Checks the existence of a winning move
// Input: Initial marker position, moveset array, number of turns
// Output: 'X' if computer wins, 'O' if player wins, 'T' if tie, 'C' if none
char winning_check (int moveset[], int turns, bool player_start);

#endif
