// save_load.cpp
// Save and load game progress
#include <iostream>
#include <fstream>
#include <string>
#include "save_load.h"
using namespace std;

// Save the game progress into a savefile.txt
// Input: moveset array, number of turns, player start?, difficulty level
void save_file (int moveset[], int turns, bool player_start, int difficulty) {
  ofstream fout;
  fout.open("savefile.txt");
  if (fout.fail()) {
    cout << "Save fail" << endl;
    exit(1);
  }
  fout << turns << " " << player_start << " " << difficulty;
  for (int i = 0; i < turns; i++) {
    fout << " " << moveset[i];
  }
  fout.close();
}

// Check the validity of the savefile.txt when loading
int load_test () {
  string filename = "savefile.txt";
  ifstream fin;
  fin.open(filename);
  if (fin.fail()) {
    cout << "Load fail...." << endl << endl;
    return 0;
  }
  return 1;
  fin.close();
}

// Load the game progress from savefile.txt but checking function is removed
// Input: moveset array, number of turns, player start?, difficulty level
// Output: modifies all inputs based on savefile.txt
void load_file (int * &moveset, int &turns, bool &player_start, int &difficulty) {
  string filename = "savefile.txt";
  ifstream fin;
  fin.open(filename);
  fin >> turns >> player_start >> difficulty;
  int * a = new int[turns];
  for (int i = 0; i < turns; i++) {
    fin >> a[i];
  }
  fin.close();
  delete [] moveset;
  moveset = a;
}
