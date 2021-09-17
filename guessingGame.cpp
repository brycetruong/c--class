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
  cout << "This is Guessing Game? (probably)" << endl;;
  srand (time(NULL));
  int randomNum = rand() % 100 +1; //random number generator
  int userInput = 0;
  int guesses = 1;
  bool playAgain = false;
  //cout << randomNum << endl;
  /*cin >> userInput;
  while (userInput != randomNum)
    {
      guesses++;
      cin >> userInput;
      cout << "Your input number was " << userInput << endl;

    }
  */
  return 0;
}
