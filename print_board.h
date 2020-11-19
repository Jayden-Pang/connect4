//print_board.h
#ifndef PRINT_BOARD_H
#define PRINT_BOARD_H

void print_column();
void print_divider();
void print_middle_border();
void print_top_border();
void print_marker(int moveset[], int turns, bool player_start, int row_number);
void print_session_divider();
void print_board (int moveset[], int turns, bool player_start);

#endif
