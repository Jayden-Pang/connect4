//ai_move.h
#ifndef AI_MOVE_H
#define AI_MOVE_H

int count_middle (int moveset[], int turns, bool player_start);
int count_horizontal (int moveset[], int turns, bool player_start, int combo);
int count_vertical (int moveset[], int turns, bool player_start, int combo);
int count_positive_diagonal (int moveset[], int turns, bool player_start, int combo);
int count_negative_diagonal (int moveset[], int turns, bool player_start, int combo);
int position_score (int moveset[], int turns, bool player_start);
int minimax (int moveset[], int turns, int depth, bool player_start, int alpha, int beta, bool is_maximising);
int ai_move (int moveset[], int turns, bool player_start, int difficulty);

#endif
