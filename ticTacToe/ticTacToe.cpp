/*
Author: Bryce Truong
Date Created: 10/5/21
Last Modified: 10/13/21
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

//all of my functions pass the 2D array board into them. 
void printBoard(int (*board)[3]);
bool checkWin(int player, int (*board)[3]);
bool checkTie(int (*board)[3]);

int main() {
  int turn = X_TURN;
  int xWins = 0;
  int oWins = 0;
  char input[10];
  int board[3][3] = {0};
  //int board[3][3] = {{X_MOVE, O_MOVE, BLANK}, {X_MOVE, BLANK, BLANK}, {X_MOVE, O_MOVE, BLANK}};
  bool playing = true;
  while (playing == true) {
    while (checkWin(X_MOVE, board) == false && checkWin(O_MOVE, board) == false && checkTie(board) == false) {
      cout << "Enter a letter followed by a number" << endl;
      //cout << board[0][0] << endl;
      printBoard(board);
      //cout << checkWin(X_MOVE, board) << endl;
      cin.getline(input, 10, '\n');
      
      //cout << input[0] << "," << input[1] << endl;

      int row = input[0] - 'a';
      int column = input[1] - '1';
      if (board[row][column] == BLANK) {
	if (turn == X_TURN) {
	  board[row][column] = X_MOVE;
	  turn = O_TURN;
	} else { //o turn
	  board[row][column] = O_MOVE;
	  turn = X_TURN;
	}
      } else {
	cout << "Sorry there's already something there!" << endl;
      }
    }

      
    
    if (checkWin(X_MOVE, board) == true) {
      cout << "X wins by a landslide!" << endl;;
      printBoard(board);
      xWins++;
    } else if (checkWin(O_MOVE, board) == true) {
      cout << "O wins by a landslide!" << endl;
      printBoard(board);
      oWins++;
    } else if (checkTie(board) == true) {
      cout << "It is a tie!" << endl;;
      printBoard(board);
    }
    
    cout << "X has won: " << xWins << " times" << endl;
    cout << "O has won: " << oWins << " times" << endl;
    cout << "Do you want to play again?" << endl;
    
    //need to clear input right here
    for (int i = 0; i < 10; i++) {
      input[i] = '\0';
    }
    cin.getline(input, 10, '\n');
    if (strcmp(input, "yes") == 0 || strcmp(input, "Yes") == 0 || strcmp(input, "y") == 0) {
      //this resets the board by going through every slot in the array and placing a blank into them
      for (int row = 0; row < 3; row++) {
	for (int column = 0; column < 3; column++) {
	  board[row][column] = BLANK;
	}
      }
      turn = X_TURN;
    } else {
      cout << "thanks for playing, cya!" << endl;
      playing = false;
    }
  }
  
  return 0;
}

 

void printBoard(int (*board)[3]) {
  
  cout << " \t|1|\t|2|\t|3|\n";
  //prints the board, going from left to right, and going down each row and printing from left to right again
	for (int row = 0; row < 3; row++) {
	  cout << (char)('a' + row) << "\t";
		for (int column = 0; column < 3; column++) {
			if (board[row][column] == BLANK) {
			  cout << "| |\t";
			} else if (board[row][column] == X_MOVE) {
			  cout << "|X|\t";
			} else if (board[row][column] == O_MOVE) {
			  cout << "|O|\t";
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
//function for checking ties!
bool checkTie(int (*board)[3]) {
		//checks for ties by seeing if the entire board is all filled up
		for (int row = 0; row < 3; row++) {
			for (int column = 0; column < 3; column++) {
				if (board[row][column] == BLANK) {
					return false;
				}
			}
		}
		return true;
	}
