// print_board.cpp
// This program prints the board
#include <iostream>
#include "print_board.h"
using namespace std;

// Prints the ascending order from 1 to 7
void print_column() {
  cout << " ";
  for (int i = 1; i < 8; i++) {
    cout << "   " << i << "    ";
  }
  cout << endl;
}

// Prints the vertical border
void print_divider() {
  cout << "|";
  for (int i = 0; i < 7; i++ ) {
    cout << "       |";
  }
  cout << endl;
}

// Prints the middle horizontal border
void print_middle_border() {
  cout << "|";
  for (int i = 0; i < 6; i++) {
    cout << "-------+";
  }
  cout << "-------|" << endl;
}

// Prints the top horizontal border
void print_top_border() {
  for (int i = 0; i < 57; i++) {
    cout << "-";
  }
  cout << endl;
}

// Prints the row and the player's marker
// Input: moveset array, number of turns, player start?, current row row_number
void print_marker(int moveset[], int turns, bool player_start, int row_number) {
  char player_marker = 'O', computer_marker = 'X';
  bool appear;
  cout << "|";
  for (int j = 1; j < 8; j++) {
    appear = false;
    cout << "   ";
    for (int k = 0; k < turns; k++) {
      if (moveset[k] == (row_number-1)*7 + j) {
        appear = true;
        if ((player_start && k%2 == 0) || (!player_start && k%2 !=0)) {
          cout << player_marker;
        }
        else {
          cout << computer_marker;
        }
      }
    }
    if (!appear) {
      cout << " ";
    }
    cout << "   |";
  }
    cout << endl;
}

// Prints a horizontal divider
void print_session_divider() {
  for (int i = 0; i < 57; i++ ) {
    cout << "=";
  }
  cout << endl;
}

// Prints the board
// Input: moveset array, number of turns, player start?
void print_board (int moveset[], int turns, bool player_start) {
  print_session_divider();
  cout << endl;
  print_column();
  print_top_border();
  for (int i = 6; i > 1; i--) {
    print_divider();
    print_marker(moveset,turns,player_start,i);
    print_divider();
    print_middle_border();
  }
  print_divider();
  print_marker(moveset,turns,player_start,1);
  print_divider();
  print_top_border();
  cout << endl;
}
