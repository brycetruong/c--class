/*
Guessing Game
Author: Bryce Truong
Date: 9/17/2021

This is a guessing game where a number from 1 - 100 is randomly generated and the user has to guess the number
The number of guesses is counted. Good luck!

*/

#include <iostream>
#include <time.h> //includes a magical library from who knows where that inplements time? (i guess...)

using namespace std;

int main()
{
  cout << "This is Guessing Game? (probably) Insert a guess to start" << endl;;
  srand (time(NULL));
  int randomNum = rand() % 100 +1; //random number generator
  int userInput = 0;
  int guesses = 0;
  bool playAgain = true;
  //cout << randomNum << endl;
  
  while (playAgain == true)
    {
      
      cin >> userInput;
      guesses++;
      //cout << "Your input number was " << userInput << endl;
      if (userInput > randomNum) { //user input was higher than random
	cout << "Your input number was " << userInput << ", and it was HIGHER" << endl;
      } else if (userInput < randomNum){//user input was lower than random
	cout << "Your input number was " << userInput << ", and it was LOWER" << endl;
      } else { //random num must = input right?
	cout << "Your input number was CORRECT! " << "You used: " << guesses << " guesses.  " << "Would you like to play again? 1 -> play again, 0 -> end game" << endl; //too lazy so just used a 1 for yes and 0 for no
	  cin >> userInput;
	if (userInput == 1) { //reset all vars and numbers
	    playAgain = true;
	    randomNum = rand() % 100 + 1;
	    guesses = 0;
	    cout << "This is Guessing Game? (probably) Insert a guess to start" << endl;;
	} else { //exit the game
	    playAgain = false;
	  }
      }
      
    }
  
  return 0;
}
