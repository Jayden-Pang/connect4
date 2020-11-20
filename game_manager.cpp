// game_manager.cpp
// This program manages all stages of the game flow
#include <iostream>
#include "game_manager.h"
#include "print_board.h"
#include "winning_check.h"
#include "input_move.h"
#include "ai_move.h"
#include "save_load.h"
using namespace std;

// Prints the game rules and instructions
void print_guide_screen () {
  system("clear");
  print_session_divider();
  cout << "                   Welcome to Connect 4" << endl;
  print_session_divider();
  cout << "Game Guide:" << endl;
  cout << "1) The game starts with an empty 7x6 board." << endl;
  cout << "2) You are given the \'O\' marker and the computer has the \'X\' marker." << endl;
  cout << "3) Each turn, you get to choose a column to place your marker." << endl;
  cout << "4) The marker will occupy the bottomest available spot in that column." << endl;
  cout << "5) Connect 4 markers in a row (horizontal, vertical, diagonal) to win!" << endl;
  print_session_divider();
}

// Allows the player to choose difficulty level and starting order
// Input: difficulty level, player start?
// Output: modify the inputs
 void print_selector_screen (int &difficulty, bool &player_start) {
   int sequence;
   cout << "Please select your difficulty:" << endl;
   cout << "1 - Easy" << endl;
   cout << "2 - Medium" << endl;
   cout << "3 - Hard" << endl;
   cout << "4 - Challenging" << endl;
   cout << "Difficulty? ";
   cin >> difficulty;
   while (difficulty != 1 && difficulty != 2 && difficulty != 3 && difficulty != 4) {
     cout << "Difficulty? ";
     cin >> difficulty;
   }
   cout << endl << "Do you want to go first?" << endl;
   cout << "1 - Yes" << endl;
   cout << "2 - No" << endl;
   cout << "Go first? ";
   cin >> sequence;
   while (sequence != 1 && sequence != 2) {
     cout << "Go first? ";
     cin >> sequence;
   }
   if (sequence == 1) {
     player_start = true;
   }
   else {
     player_start = false;
   }
   system("clear");
 }

// Manages the flow of the game
// Receive player inputs and outputs the current state of the game
// Input: difficulty level, player start?, load indicator, save indicator
// Output: Continuously take inputs and prints the board after each turn
void game_start (int difficulty, bool player_start, int load, int &save) {
  int *moveset = new int[1];
  int player_move = 0, opponent_move = 0, move_check = 0, opponent_last_move, turns = 0, quit;
  char winner = 'C';
  if (load == 1) {
    load_file (moveset, turns, player_start, difficulty);
    load = 0;
  }
  while (winner == 'C') {
    // Runs during the player's turn
    if ((player_start == true && turns%2 == 0) || (player_start == false && turns%2 != 0)) {
      print_board(moveset, turns, player_start);
      if (turns != 0) {
        opponent_last_move = moveset[turns-1]%7;
        if (opponent_last_move == 0) {
          opponent_last_move = 7;
        }
        cout << "Opponent's Last Move : " << opponent_last_move << endl;
      }
      cout << "What's your next move? (Select 1 to 7) [Select 0 to save and quit]" << endl;
      cin >> player_move;
      // If player selects 0, save and exit the game
      if (player_move == 0) {
        cout << endl << "Are you sure you want to quit?" << endl;
        cout << "1 - Yes" << endl;
        cout << "2 - No" << endl;
        cout << "Exit the game? ";
        cin >> quit;
        while (quit != 1 && quit != 2) {
          cout << "Exit the game? ";
          cin >> quit;
        }
        cout << endl;
        if (quit == 1) {
          cout << "Do you want to save the game?" << endl;
          cout << "1 - Yes" << endl;
          cout << "2 - No" << endl;
          cout << "Save and exit? ";
          cin >> quit;
          while (quit != 1 && quit != 2) {
            cout << "Save and exit? ";
            cin >> quit;
          }
          if (quit == 1) {
            save_file (moveset, turns, player_start, difficulty);
          }
          save = 1;
          break;
        }
      }
      // Checks the validity of the move
      move_check = column_to_point(moveset, player_move, turns);
      while (move_check == 0) {
        cout << "What's your next move? (Select 1 to 7)" << endl;
        cin >> player_move;
        move_check = column_to_point(moveset, player_move, turns);
      }
      // Adds the valid move into the moveset array
      add_moveset (moveset, player_move, turns);
      // Checks for any winning move
      winner = winning_check (moveset, turns, player_start);
      if ( winner == 'O') {
        system ("clear");
        print_board(moveset, turns, player_start);
        cout << "Opponent's Last Move : " << opponent_last_move << endl;
        cout << "You win!" << endl;
        break;
      }
      else if (winner == 'T') {
        system ("clear");
        print_board(moveset, turns, player_start);
        cout << "Opponent's Last Move : " << opponent_last_move << endl;
        cout << "It's a tie!" << endl;
        break;
      }
    }
    else {
      // Runs during computer's turn
      system("clear");
      opponent_move = ai_move (moveset, turns, player_start, difficulty);
      // Adds the computer's move into the moveset array
      add_moveset (moveset, opponent_move, turns);
      // Checks for any winning move
      winner = winning_check (moveset, turns, player_start);
      if (winner == 'X') {
        opponent_last_move = moveset[turns-1]%7;
        if (opponent_last_move == 0) {
          opponent_last_move = 7;
        }
        print_board(moveset, turns, player_start);
        cout << "Opponent's Last Move : " << opponent_last_move << endl;
        cout << "You lose...." << endl;
        break;
      }
      else if (winner == 'T') {
        opponent_last_move = moveset[turns-1]%7;
        if (opponent_last_move == 0) {
          opponent_last_move = 7;
        }
        print_board(moveset, turns, player_start);
        cout << "Opponent's Last Move : " << opponent_last_move << endl;
        cout << "It's a tie!" << endl;
        break;
      }
    }
  }
  delete [] moveset;
  moveset = NULL;
}
