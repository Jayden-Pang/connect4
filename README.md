# connect4

**Game Name**
- Connect4

**Game Rules**
1) The game starts with an empty 7 x 6 grid (7 columns and 6 rows).
2) The player is given the mark 'O' wheareas the computer is given mark 'X'.
3) Each side takes turn to select a column (1-7).
4) Players then place their assigned mark on the bottom-most unoccupied row in that column and end the turn.
5) The first player to get 4 marks in a row (vertical, horizontal or diagonal) wins the game.
6) When all 42 spaces are filled, the game ends. If no player has 4 marks in a row, it is a draw.

**Available Features**
1) Generation of random game sets or events
- There are 4 difficulties available (Easy, Medium, Hard, Challenging).
- The computer moves will be random depending on the difficulty selected.
- For easy difficulty, computer's move is completely random.
- For medium difficulty, computer's move is random but within one column away from the player's last move, it also chooses a winning move if available.
- For hard difficulty, computer's move is based on minimax algorithm with depth = 3.
- For challenging difficulty, computer's move is based on minimax algorithm with depth = 4.

2) Data structure for storing game status
- Dynamic array is used to store user moves and computer moves in a sequence.
- Int data types is used to store the number of turns, which also indicates the number of elements in the array.
- Boolean data types is used to store whether the player starts first or not.
- Int data types is used to store difficulty chosen.

3) Dynamic memory management
- Dynamic arrays are used to store user moves and computer moves.
- A function is implemented to increase the size of the array as the number of turns increases.

4) File input/output
- When the player quits the game, the current game status will be printed into a line of integers separated by spaces and stored in savefile.txt.
- When the player re-enters the game, the game status can be restored by reading the savefile.txt file.

5) Program codes in multiple files
- The whole program is divided into multiple functions and stored in different files.
- Programs include main program, checking for winning condition, determining the computer moves, drawing the interface, save and load files, control the game flow, and inputting moves into a new dynamic array.
- Makefile is used to generate the program from all the files.

**Compilation and Execution**
- Place all source files and the Makefile into a single folder. The commands are:
1) Compilation: make connect4
2) Execution: ./connect4
3) Removal: make clean
