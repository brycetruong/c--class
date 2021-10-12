/*
Author: Bryce Truong
Date Created: 10/5/21
Last Modified: 10/11/21
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
https://www.geeksforgeeks.org/pass-2d-array-parameter-c/ (saved my life, taught me how to pass 2D arrays into functions)

*/
#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <array>
#include <stdio.h>

using namespace std;

//constant ints
const int BLANK = 0;
const int X_MOVE = 1;
const int O_MOVE = 2;
const int X_TURN = 0;
const int O_TURN = 1;

void printBoard(int (*board)[3]);
bool checkWin(int player, int (*board)[3]);
bool checkTie();

int main() {
  int turn = X_TURN;
  int board[3][3] = {{BLANK, BLANK, BLANK}, {BLANK, BLANK, BLANK}, {X_MOVE, O_MOVE, BLANK}};
  bool playing = true;
  while (playing == true) {
    while (checkWin(X_MOVE) == false && checkWin(O_MOVE) == false && checkTie() == false) {
    cout << "Enter a letter followed by a number" << endl;
    //cout << board[0][0] << endl;
    printBoard(board);
    bool test = true;
    cout << checkWin(X_MOVE, board) << endl;





    }
    playing = false;
  }
  
  return 0;
}

 

void printBoard(int (*board)[3]) {
  
  cout << " \t1\t2\t3\n";
  //prints the board, going from left to right, and going down each row and printing from left to right again
	for (int row = 0; row < 3; row++) {
	  cout << (char)('a' + row) << "\t";
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

bool checkWin(int player, int (*board)[3]) { //checks conditions to see whether a player has won yet
		//checks for wins in rows
		if (board[0][0] == player &&
			board[0][1] == player &&
			board[0][2] == player) {
			return true;
		}
		if (board[1][0] == player &&
			board[1][1] == player &&
			board[1][2] == player) {
				return true;
			}
		if (board[1][0] == player &&
			board[1][1] == player &&
			board[1][2] == player) {
				return true;
			}
		//checks for wins in columns
		if (board[0][0] == player &&
			board[1][0] == player &&
			board[2][0] == player) {
				return true;
			}
		if (board[0][1] == player &&
			board[1][1] == player &&
			board[2][1] == player) {
				return true;
			}
		if (board[0][2] == player &&
			board[1][2] == player &&
			board[2][2] == player) {
					return true;
				}
		//checks for wins in diagonals
		if (board[0][0] == player &&
			board[1][1] == player &&
			board[2][2] == player) {
			return true;
		}
		if (board[0][2] == player &&
			board[1][1] == player &&
			board[2][0] == player) {
				return true;
			}
		//if none if the above are true, return false and keep on playing
		return false;
	}
