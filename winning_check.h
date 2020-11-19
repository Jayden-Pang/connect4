//winning_check.h
#ifndef WINNING_CHECK_H
#define WINNING_CHECK_H

bool up_diagonal_check (int starting_position, int moveset[], int turns);
bool down_diagonal_check (int starting_position, int moveset[], int turns);
bool horizontal_check (int starting_position, int moveset[], int turns);
bool vertical_check (int starting_position, int moveset[], int turns);
char winning_check (int moveset[], int turns, bool player_start);

#endif
