# connect4

Group Members:
1) Pang Po Hean (3035444243)
2) Nicholas Tjandra Ariel (3035557973)

Game Name: Connect4
Game Rules:
1) The game starts with an empty 7 x 6 grid (7 columns and 6 rows).
2) 2 players are required to play the game. One player is given the mark 'X' wheareas the other player is given mark 'O'.
3) Each player takes turn to select a column (1-7).
4) Players then place their assigned mark on the bottom-most unoccupied row in that column and end the turn.
5) The first player to get 4 marks in a row (vertical, horizontal or diagonal) wins the game.
6) When all 42 spaces are filled, the game ends. If no player has 4 marks in a row, it is a draw.

Available Features:
1) Generation of random game sets or events
- There are 3 difficulties available (Easy, Medium, Hard).
- The computer moves will be random depending on the difficulty selected.
- Higher difficulty will force the computer to place a mark nearer to the player's mark, given that the player is not one move away from winning.

2) Data structure for storing game status
- There will be a 2D array with 7 columns and 6 rows.
- The elements in the array can store char data types, and the char 'E' is stored initially.
- Int data types will be used to store the number of turns.
- Char data types will be used to store difficulty chosen.

3) Dynamic memory management
- Each move will change the corresponding element in the 2D array into either 'X' or 'O'.
- Number of turns will be stored using an int data type, and increases by 1 every turn.
- Player turns will be stored using a boolean data type, 'TRUE' means player goes next and 'FALSE' means computer goes next, updates every turn by using 'NOT' function.
- When the game ends or player stops the game, All variables above will revert to their starting values.

4) File input/output
- When the player quits the game, the elements of the array will be printed row by row into a line of 42 characters, followed by
the difficulty chosen, who gets the next turn, and finally number of turns into a txt file.
- When the player re-enters the game, the game status can be restored by reading the txt file.

5) Program codes in multiple files
- The whole program can be divided into multiple functions.
- Functions include the main function, checking for winning condition, determining the computer moves, and drawing the interface.
- Each function can be stored in a separate file.
