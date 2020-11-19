#include <iostream>
#include <cstdlib>
#include <limits>
#include "game_manager.h"
#include "print_board.h"
using namespace std;

int main() {
  bool player_start = true;
  int difficulty;
  int play_again = 1;
  while (play_again == 1) {
    print_guide_screen ();
    print_selector_screen (difficulty, player_start);
    game_start (difficulty, player_start);
    cout << endl <<"Do you want to play again?" << endl;
    cout << "1 - Yes" << endl;
    cout << "2 - No" << endl;
    cin >> play_again;
    while (play_again != 1 && play_again != 2) {
      cout << "Please enter again." << endl;
      cin >> play_again;
    }
    system("clear");
    print_session_divider();
  }
  cout << "                Thank you for playing!" << endl;
  print_session_divider();
}
