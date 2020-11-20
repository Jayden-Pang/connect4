// winning_check.cpp
// This program checks the current status of the game
#include <iostream>
#include "winning_check.h"
using namespace std;

// Checks the existence of 4-in-a-row markets in a positive slope diagonal
// Input: Initial marker position, moveset array, number of turns
// Output: True if 4-in-a-row exists. false otherwise
bool up_diagonal_check (int starting_position, int moveset[], int turns) {
  int count = 0, search_start = 0;
  if (turns%2 == 0) {
    search_start = 1;
  }
  for (int i = search_start; i < turns; i += 2) {
    for (int k = 1; k < 4; k++) {
      if (moveset[i] == moveset[starting_position]+8*k) {
        count += 1;
      }
    }
  }
  if (count == 3) {
    return true;
  }
  else {
    return false;
  }
}

// Checks the existence of 4-in-a-row markers in a negative slope diagonal
// Input: Initial marker position, moveset array, number of turns
// Output: True if 4-in-a-row exists. false otherwise
bool down_diagonal_check (int starting_position, int moveset[], int turns) {
  int count = 0, search_start = 0;
  if (turns%2 == 0) {
    search_start = 1;
  }
  for (int i = search_start; i < turns; i += 2) {
    for (int k = 1; k < 4; k++) {
      if (moveset[i] == moveset[starting_position]-6*k) {
        count += 1;
      }
    }
  }
  if (count == 3) {
    return true;
  }
  else {
    return false;
  }
}

// Checks the existence of 4-in-a-row markers in a horizontal line
// Input: Initial marker position, moveset array, number of turns
// Output: True if 4-in-a-row exists. false otherwise
bool horizontal_check (int starting_position, int moveset[], int turns) {
  int count = 0, search_start = 0;
  if (turns%2 == 0) {
    search_start = 1;
  }
  for (int i = search_start; i < turns; i += 2) {
    for (int k = 1; k < 4; k++) {
      if (moveset[i] == moveset[starting_position]+k) {
        count += 1;
      }
    }
  }
  if (count == 3) {
    return true;
  }
  else {
    return false;
  }
}

// Checks the existence of 4-in-a-row markers in a vertical line
// Input: Initial marker position, moveset array, number of turns
// Output: True if 4-in-a-row exists. false otherwise
bool vertical_check (int starting_position, int moveset[], int turns) {
  int count = 0, search_start = 0;
  if (turns%2 == 0) {
    search_start = 1;
  }
  for (int i = search_start; i < turns; i += 2) {
    for (int k = 1; k < 4; k++) {
      if (moveset[i] == moveset[starting_position]+7*k) {
        count += 1;
      }
    }
  }
  if (count == 3) {
    return true;
  }
  else {
    return false;
  }
}

// Checks the existence of a winning move
// Input: Initial marker position, moveset array, number of turns
// Output: 'X' if computer wins, 'O' if player wins, 'T' if tie, 'C' if none
char winning_check (int moveset[], int turns, bool player_start) {
  int count = 0, search_start = 0;
  if (turns%2 == 0) {
    search_start = 1;
  }
  if (turns < 7) {
    return 'C';
  }
  else {
    for (int i = search_start; i < turns; i += 2) {
      if ((moveset[i] >= 1 && moveset[i] <= 4) || (moveset[i] >= 8 && moveset[i] <= 11) || (moveset[i] >= 15 && moveset[i] <= 18)) {
        if (horizontal_check(i,moveset,turns) || vertical_check(i,moveset,turns) || up_diagonal_check(i,moveset,turns)) {
          if ((player_start == true && search_start == 0) || (player_start == false && search_start == 1)) {
            return 'O';
          }
          else {
            return 'X';
          }
        }
      }
      else if (moveset[i] <= 21) {
        if (vertical_check(i,moveset,turns)) {
          if ((player_start == true && search_start == 0) || (player_start == false && search_start == 1)) {
            return 'O';
          }
          else {
            return 'X';
          }
        }
      }
      else if ((moveset[i] >= 22 && moveset[i] <= 25) || (moveset[i] >= 29 && moveset[i] <= 32) || (moveset[i] >= 36 && moveset[i] <= 39)) {
        if (horizontal_check(i,moveset,turns) || down_diagonal_check(i,moveset,turns)) {
          if ((player_start == true && search_start == 0) || (player_start == false && search_start == 1)) {
            return 'O';
          }
          else {
            return 'X';
          }
        }
      }
    }
  }
  if (turns == 42) {
    return 'T';
  }
  else {
    return 'C';
  }
}
