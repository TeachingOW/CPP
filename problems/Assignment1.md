### **Assignment I Tic Tac Toe**

**Task:**
You are tasked with modifying the Tic-Tac-Toe program to work with binary representations for the boards. Additionally, you need to create a program that reads these binary representations, checks the status of the game, and outputs the result in a file.

### **Steps to Follow:**

1. **Modify the Tic-Tac-Toe Program to Write Boards in Binary:**
    - Convert the game board (3x3 grid) to a binary representation, code is
    [here](/codesnippets/tictactoe.cpp). You can check out the code to work with files from [here](/file.md).
    - You are free to choose any format.
    - Write the binary representations of the boards to a file.

2. **Create a Program to Check the Board Status:**
    - The new program should read the binary board representations from the file.
    - The program must check the status of each board and determine one of the following results:
        - **X wins**: If 'X' has three marks in a row, column, or diagonal.
        - **O wins**: If 'O' has three marks in a row, column, or diagonal.
        - **Draw**: If the board is complete and neither player has won.
        - **In progress**: If the game is valid, but the game is still ongoing (there are empty spaces and no winner yet).
        - **Invalid**: If the board is in an impossible state (e.g., the number of `O`'s exceeds `X`'s, or there are other issues with the board setup).
  

**Expected Output:**
- A text file that lists the status of each Tic-Tac-Toe board in order:
    - `X wins`, `O wins`, `Draw`, `In progress`, or `Invalid`.

