//input_move.cpp
//this program converts the player move and appends it to the moveset array
#include <iostream>
#include "input_move.h"
using namespace std;

//converts a column into a position in the moveset array
int column_to_point (int moveset[], int player_move, int turns) {
  int count = 0, row_counter = 0;
  if (player_move >= 1 && player_move <= 7) {
    for (int i = 0; i < turns; i++) {
      if (moveset[i] == (player_move + row_counter*7)) {
        row_counter += 1;
        count += 1;
      }
    }
    if (player_move+count*7 <= 42) {
      return player_move+count*7;
    }
    else {
      return 0;
    }
  }
  else {
    return 0;
  }
}

//adds player move into the moveset array
void add_moveset (int * &moveset, int player_move, int &turns) {
  if (turns == 0) {
    moveset[0] = player_move;
    turns += 1;
  }
  else {
    int turns_temp = turns;
    int * a = new int[turns_temp + 1];
    for (int i = 0; i < turns_temp; i++) {
      a[i] = moveset[i];
    }
    a[turns_temp] = column_to_point(moveset, player_move, turns);
    delete moveset;
    moveset = a;
    turns += 1;
  }
}
