#include <iostream>
#include "game_manager.h"
#include "print_board.h"
#include "save_load.h"
using namespace std;

int main() {
  bool player_start = true;
  int difficulty, load = 0, save = 0, load_temp = 0;
  int play_again = 1;
  while (play_again == 1) {
    // Prints the game rules and instructions
    print_guide_screen ();
    // Ask the user whether to load save file or not
    // Only ask one time hence the load_temp variable
    if (load_temp == 0) {
      cout << "Do you want to load the save file? " << endl;
      cout << "1 - Yes" << endl;
      cout << "2 - No" << endl;
      cout << "Load save file? ";
      cin >> load;
      while (load != 1 && load != 2) {
        cout << "Load save file? ";
        cin >> load;
      }
      load_temp = 1;
      if (load == 1) {
        load = load_test();
        if (load == 1) {
          system("clear");
        }
      }
      else {
        cout << endl;
      }
    }
    // Allows the player to choose difficulty and starting order
    // Only runs if save file is not loaded
    if (load != 1) {
      print_selector_screen (difficulty, player_start);
    }
    // Starts the main part of the game
    game_start (difficulty, player_start, load, save);
    load = 2;
    // Ask whether the user wants to play again
    // If user saves and quit in the game_start function, exit immediately
    if (save != 1) {
      cout << endl << "Do you want to play again?" << endl;
      cout << "1 - Yes" << endl;
      cout << "2 - No" << endl;
      cout << "Play again? ";
      cin >> play_again;
      while (play_again != 1 && play_again != 2) {
        cout << "Play again? ";
        cin >> play_again;
      }
    }
    else {
      play_again = 2;
    }
    system("clear");
  }

  // Prints the ending screen
  print_session_divider();
  cout << "                Thank you for playing!" << endl;
  print_session_divider();
}
