/*
Author: Bryce Truong
Date Created: 10/5/21
Last Modified: 10/5/21
ticTacToe game!
This is a TicTacToe Game. It reads input and creates a 3x3 board to play the game on.
It checks for wins, ties, and calculates how many wins X has and how many wins O has.
It also checks to make sure you aren't cheating by placing your piece over your opponents piece.

Sources:
https://www.geeksforgeeks.org/multidimensional-arrays-c-cpp/
https://www.cplusplus.com/reference/cstring/?kw=cstring
https://www.jdoodle.com/online-java-compiler/
https://beta.openai.com/playground?model=davinci-codex
https://www.geeksforgeeks.org/constants-in-c-cpp/
https://www.geeksforgeeks.org/endl-vs-n-in-cpp/

*/
#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <array>

using namespace std;

//constant ints
const int BLANK = 0;
const int X_MOVE = 1;
const int O_MOVE = 2;
const int X_TURN = 0;
const int O_TURN = 1;

void printBoard(int *board);
bool checkWin(int player);
bool checkTie();

int main() {
  int turn = X_TURN;
  int board[3][3] = {0};
  bool playing = true;
  while (playing == true) {
    cout << board[0][0] << endl;
    printBoard(board);


    playing = false;
  }
  
  return 0;
}

void printBoard(int board[][]) {
  cout << " \t1\t2\t3\n";
  //prints the board, going from left to right, and going down each row and printing from left to right again
	for (int row = 0; row < 3; row++) {
	  //abc rows for
		for (int column = 0; column < 3; column++) {
			if (board[row][column] == BLANK) {
			  cout << " \t";
			} else if (board[row][column] == X_MOVE) {
			  cout << "X\t";
			} else if (board[row][column] == O_MOVE) {
			  cout << "O\t";
			}
		}
		cout << endl;
		
	}
}
