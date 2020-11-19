//ai_move.cpp
//this program determines the moves of the computer
#include <iostream>
#include <cstdlib>
#include <limits>
#include "winning_check.h"
#include "ai_move.h"
#include "input_move.h"
using namespace std;

//counts the number of markers in the middle 3x2 border
int count_middle (int moveset[], int turns, bool player_start) {
  int count = 0;
  if (player_start == true) {
    for (int row = 0; row < 2; row++) {
      for (int column = 3; column < 6; column++) {
        for (int i = 1; i < turns; i++) {
          if (column+7*row == moveset[i]) {
            if (i%2 != 0) {
              count += 1;
            }
          }
        }
      }
    }
  }
  else {
    for (int row = 0; row < 2; row++) {
      for (int column = 3; column < 6; column++) {
        for (int i = 1; i < turns; i++) {
          if (column+7*row == moveset[i]) {
            if (i%2 == 0) {
              count += 1;
            }
          }
        }
      }
    }
  }
  return count;
}

//counts the number of horizontal patterns with (combo)-in-a-row markers
int count_horizontal (int moveset[], int turns, bool player_start, int combo) {
  int piece_count = 0, occupied_count = 0, count = 0;
  if (player_start == true) {
    for (int row = 0; row < 6; row++) {
      for (int column = 1; column < 5; column++) {
        for (int j = 0; j < 4; j++) {
          for (int i = 1; i < turns; i++) {
            if (row*7+column+j == moveset[i]) {
              if (i%2 != 0) {
                piece_count += 1;
              }
              else {
                occupied_count += 1;
              }
            }
          }
        }
        if (piece_count == combo && occupied_count == 0) {
          count += 1;
        }
        piece_count = 0;
        occupied_count = 0;
      }
    }
  }

  else {
    for (int row = 0; row < 6; row++) {
      for (int column = 1; column < 5; column++) {
        for (int j = 0; j < 4; j++) {
          for (int i = 1; i < turns; i++) {
            if (row*7+column+j == moveset[i]) {
              if (i%2 == 0) {
                piece_count += 1;
              }
              else {
                occupied_count += 1;
              }
            }
          }
        }
        if (piece_count == combo && occupied_count == 0) {
        count += 1;
        }
        piece_count = 0;
        occupied_count = 0;
      }
    }
  }
  return count;
}

//counts the number of vertical patterns with (combo)-in-a-row markers
int count_vertical (int moveset[], int turns, bool player_start, int combo) {
  int piece_count = 0, occupied_count = 0, count = 0;
  if (player_start == true) {
    for (int position = 0; position < 21; position++) {
       for (int j = 0; j < 4; j++) {
        for (int i = 1; i < turns; i++) {
          if (position + j*7 == moveset[i]) {
            if (i%2 != 0) {
              piece_count += 1;
            }
            else {
              occupied_count += 1;
            }
          }
        }
      }
      if (piece_count == combo && occupied_count == 0) {
        count += 1;
      }
      piece_count = 0;
      occupied_count = 0;
    }
  }

  else {
    for (int position = 0; position < 21; position++) {
      for (int j = 0; j < 4; j++) {
       for (int i = 1; i < turns; i++) {
          if (position + j*7 == moveset[i]) {
            if (i%2 == 0) {
              piece_count += 1;
            }
            else {
              occupied_count += 1;
            }
          }
        }
      }
      if (piece_count == combo && occupied_count == 0) {
        count += 1;
      }
      piece_count = 0;
      occupied_count = 0;
    }
  }
  return count;
}

//counts the number of positive slope diagonal patterns with (combo)-in-a-row markers
int count_positive_diagonal (int moveset[], int turns, bool player_start, int combo) {
  int piece_count = 0, occupied_count = 0, count = 0;
  if (player_start == true) {
    for (int row = 0; row < 4; row++) {
      for (int column = 1; column < 5; column++) {
         for (int j = 0; j < 4; j++) {
           for (int i = 1; i < turns; i++) {
            if (row*7+column+8*j == moveset[i]) {
              if (i%2 != 0) {
                piece_count += 1;
              }
              else {
                occupied_count += 1;
              }
            }
          }
        }
        if (piece_count == combo && occupied_count == 0) {
          count += 1;
        }
        piece_count = 0;
        occupied_count = 0;
      }
    }
  }

  else {
    for (int row = 0; row < 4; row++) {
      for (int column = 1; column < 5; column++) {
        for (int j = 0; j < 4; j++) {
          for (int i = 1; i < turns; i++) {
            if (row*7+column+8*j == moveset[i]) {
              if (i%2 == 0) {
                piece_count += 1;
              }
              else {
                occupied_count += 1;
              }
            }
          }
        }
        if (piece_count == combo && occupied_count == 0) {
          count += 1;
        }
        piece_count = 0;
        occupied_count = 0;
      }
    }
  }
  return count;
}

//counts the number of negative slope diagonal patterns with (combo)-in-a-row markers
int count_negative_diagonal (int moveset[], int turns, bool player_start, int combo) {
  int piece_count = 0, occupied_count = 0, count = 0;
  if (player_start == true) {
    for (int row = 0; row < 3; row++) {
      for (int column = 36; column < 40; column++) {
        for (int j = 0; j < 4; j++)  {
          for (int i = 1; i < turns; i++) {
            if (column-7*row-6*j == moveset[i]) {
              if (i%2 != 0) {
                piece_count += 1;
              }
              else {
                occupied_count += 1;
              }
            }
          }
        }
        if (piece_count == combo && occupied_count == 0) {
          count += 1;
        }
        piece_count = 0;
        occupied_count = 0;
      }
    }
  }

  else {
    for (int row = 0; row < 3; row++) {
      for (int column = 36; column < 40; column++) {
        for (int j = 0; j < 4; j++)  {
          for (int i = 1; i < turns; i++) {
            if (column-7*row-6*j == moveset[i]) {
              if (i%2 == 0) {
                piece_count += 1;
              }
              else {
                occupied_count += 1;
              }
            }
          }
        }
        if (piece_count == combo && occupied_count == 0) {
          count += 1;
        }
        piece_count = 0;
        occupied_count = 0;
      }
    }
  }
  return count;
}

//calculates the heuristic score of a given board
int position_score (int moveset[], int turns, bool player_start) {
  int total = 0;

  total += count_middle(moveset,turns,player_start)*10;

  total += count_horizontal(moveset,turns,player_start,4)*100;
  total += count_vertical(moveset,turns,player_start,4)*100;
  total += count_negative_diagonal(moveset,turns,player_start,4)*100;
  total += count_positive_diagonal(moveset,turns,player_start,4)*100;

  total += count_horizontal(moveset,turns,player_start,3)*50;
  total += count_vertical(moveset,turns,player_start,3)*50;
  total += count_negative_diagonal(moveset,turns,player_start,3)*50;
  total += count_positive_diagonal(moveset,turns,player_start,3)*50;

  total -= count_horizontal(moveset,turns,!player_start,3)*150;
  total -= count_vertical(moveset,turns,!player_start,3)*150;
  total -= count_negative_diagonal(moveset,turns,!player_start,3)*150;
  total -= count_positive_diagonal(moveset,turns,!player_start,3)*150;

  return total;
}

//minimax algorithm with alpha-beta pruning
int minimax (int moveset[], int turns, int depth, bool player_start, int alpha, int beta, bool is_maximising) {
  int point = 0, best_score, score = 0;
  char winner;
  winner = winning_check (moveset, turns, player_start);
  if (winner != 'C' or depth == 0) {
    if (winner == 'O') {
      return numeric_limits<int>::min();
    }
    else if (winner == 'X') {
      return numeric_limits<int>::max();
    }
    else if (winner == 'T') {
      return 0;
    }
    else {
      return position_score(moveset, turns, player_start);
    }
  }

  else {
    int *temp_moveset = new int[turns+1];
    for (int i = 0; i < turns; i++) {
      temp_moveset[i] = moveset[i];
    }
    if (is_maximising) {
      best_score = numeric_limits<int>::min();
      for (int i = 1; i < 8; i++) {
        point = column_to_point(moveset, i, turns);
        if (point != 0) {
          temp_moveset[turns] = point;
          score = minimax(temp_moveset, turns+1, depth-1, player_start, alpha, beta, false);
          if (score > best_score) {
            best_score = score;
          }
          if (score > alpha) {
            alpha = score;
          }
          if (beta < alpha) {
            break;
          }
        }
      }
    }
    else {
      best_score = numeric_limits<int>::max();
      for (int i = 1; i < 8; i++) {
        point = column_to_point(moveset, i, turns);
        if (point != 0) {
          temp_moveset[turns] = point;
          score = minimax (temp_moveset, turns+1, depth-1, player_start, alpha, beta, true);
          if (score < best_score) {
            best_score = score;
          }
          if (score < beta) {
            beta = score;
          }
          if (beta < alpha) {
            break;
          }
        }
      }
    }
    delete [] temp_moveset;
  }
  return best_score;
}

//determines the computer's next move
int ai_move (int moveset[], int turns, bool player_start, int difficulty) {
  if (turns < 3) {
    srand(time(NULL));
    return rand()%3 + 3;
  }
  else {
    int best_move = 0, best_move_temp, point = 0;
    if (difficulty == 1) {
      best_move = 0;
    }
    else if (difficulty == 2) {
      int opponent_last_move;
      int *temp_moveset = new int[turns+2];
      for (int i = 0; i < turns; i++) {
        temp_moveset[i] = moveset[i];
      }
      for (int i = 1; i < 8; i++) {
        point = column_to_point(moveset, i, turns);
        if (point != 0) {
          temp_moveset[turns] = point;
          if (winning_check(temp_moveset, turns+1, player_start) == 'X') {
            return i;
          }
        }
      }
      opponent_last_move = moveset[turns-1]%7;
      srand(time(NULL));
      if (opponent_last_move >= 2 && opponent_last_move <= 6) {
        best_move = rand()%3 + opponent_last_move - 1;
      }
      else if (opponent_last_move == 0) {
        best_move = rand()%2 + 6;
      }
      else {
        best_move = rand()%2 + 1;
      }
    }
    else {
      int best_score = numeric_limits<int>::min(), score = 0, ai_depth = 2;
      if (difficulty == 4) {
        ai_depth = 4;
      }
      int *temp_moveset = new int[turns+1];
      for (int i = 0; i < turns; i++) {
        temp_moveset[i] = moveset[i];
      }
      for (int i = 1; i < 8; i++) {
        point = column_to_point(moveset, i, turns);
        if (point != 0) {
          temp_moveset[turns] = point;
          if (winning_check(temp_moveset, turns+1, player_start) == 'X') {
            return i;
          }
          score = minimax(temp_moveset, turns+1, ai_depth, player_start, numeric_limits<int>::min(), numeric_limits<int>::max(), false);
          if (score > best_score) {
            best_score = score;
            best_move = i;
          }
        }
      }
      delete [] temp_moveset;
    }
    best_move_temp = best_move;
    while (best_move_temp == 0) {
      srand(time(NULL));
      best_move = rand()%7 + 1;
      best_move_temp = column_to_point(moveset, rand()%7 + 1, turns);
    }
    return best_move;
  }
}
