//game_manager.cpp
//this program manages the all stages of the game flow
#include <iostream>
#include "game_manager.h"
#include "print_board.h"
#include "winning_check.h"
#include "input_move.h"
#include "ai_move.h"
using namespace std;

//prints the game rules and instructions
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

//allows the player to choose difficulty level and starting order
 void print_selector_screen (int &difficulty, bool &player_start) {
   int sequence;
   cout << "Please select your difficulty:" << endl;
   cout << "1 - Easy" << endl;
   cout << "2 - Medium" << endl;
   cout << "3 - Hard" << endl;
   cout << "4 - Challenging" << endl;
   cout << "Difficulty: ";
   cin >> difficulty;
   while (difficulty != 1 && difficulty != 2 && difficulty != 3 && difficulty != 4) {
     cout << "Please select your difficulty again: " ;
     cin >> difficulty;
   }
   cout << endl << "Do you want to go first?" << endl;
   cout << "1 - Yes" << endl;
   cout << "2 - No" << endl;
   cout << "Your Starting Turn: ";
   cin >> sequence;
   while (sequence != 1 && sequence != 2) {
     cout << "Please select your starting turn again: ";
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

//manages the flow of the game
//receive player inputs and outputs the current state of the game
void game_start (int difficulty, bool player_start) {
  int * moveset = new int[1];
  int turns = 0, input = 0, ai = 0, move_check;
  char winner = 'C';
  if (player_start == true) {
    while (winner == 'C') {
      if (turns == 0) {
        print_board(moveset, turns, player_start);
      }
      cout << "What's your next move? (Select 1 to 7)" << endl;
      cin >> input;
      move_check = column_to_point(moveset, input, turns);
      while (move_check == 0) {
        cout << "Try again. (Select 1 to 7)" << endl;
        cin >> input;
        move_check = column_to_point(moveset, input, turns);
      }
      system("clear");
      add_moveset (moveset, input, turns);
      winner = winning_check (moveset, turns, player_start);
      if (winner == 'X') {
        print_board(moveset, turns, player_start);
        cout << "Opponent's Last Move : " << ai << endl;
        cout << "You lose..." << endl;
        break;
      }
      else if (winner == 'O') {
        print_board(moveset, turns, player_start);
        cout << "Opponent's Last Move : " << ai << endl;
        cout << "You win!" << endl;
        break;
      }
      else if (winner == 'T') {
        print_board(moveset, turns, player_start);
        cout << "Opponent's Last Move : " << ai << endl;
        cout << "It's a tie!" << endl;
        break;
      }
      else {
        system("clear");
        ai = ai_move (moveset, turns, player_start, difficulty);
        add_moveset (moveset, ai, turns);
        print_board(moveset, turns, player_start);
        cout << "Opponent's Last Move : " << ai << endl;
        winner = winning_check (moveset, turns, player_start);
        if (winner == 'X') {
          cout << "You lose..." << endl;
          break;
        }
        else if (winner == 'O') {
          cout << "You win!" << endl;
          break;
        }
        else if (winner == 'T') {
          cout << "It's a tie" << endl;
          break;
        }
      }
    }
  }
  else {
    while (winner == 'C') {
      system("clear");
      ai = ai_move (moveset, turns, player_start, difficulty);
      system("clear");
      add_moveset (moveset, ai, turns);
      print_board(moveset, turns, player_start);
      cout << "Opponent's Last Move : " << ai << endl;
      winner = winning_check (moveset, turns, player_start);
      if (winner == 'X') {
        cout << "You lose..." << endl;
        break;
      }
      else if (winner == 'O') {
        cout << "You win!" << endl;
        break;
      }
      else if (winner == 'T') {
        cout << "It's a tie!" << endl;
        break;
      }
      else {
        cout << "What's your next move? (Select 1 to 7)" << endl;
        cin >> input;
        move_check = column_to_point(moveset, input, turns);
        while (move_check == 0) {
          cout << "Try again. (Select 1 to 7)" << endl;
          cin >> input;
          move_check = column_to_point(moveset, input, turns);
        }
        system("clear");
        add_moveset (moveset, input, turns);
        print_board(moveset, turns, player_start);
        winner = winning_check (moveset, turns, player_start);
        if (winner == 'X') {
          cout << "Opponent's Last Move : " << ai << endl;
          cout << "You lose..." << endl;
          break;
        }
        else if (winner == 'O') {
          cout << "Opponent's Last Move : " << ai << endl;
          cout << "You win!" << endl;
          break;
        }
        else if (winner == 'T') {
          cout << "Opponent's Last Move : " << ai << endl;
          cout << "It's a tie!" << endl;
          break;
        }
      }
    }
  }
  delete [] moveset;
}
