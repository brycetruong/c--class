/*
Author: Bryce Truong
Date Created: 9/22/21
Last Modified: 9/22/21
Palindrome Assignment
This project take a user input, removes all the spaces, removes all the misc chars (anything not a letter) 
and then converts it to a capital letter. Then it reverses it and checks to see if it's a palindrome. If so it says "palindrome", if not, then it says "not a palindrome"

Sources:
https://www.geeksforgeeks.org/cin-get-in-c-with-examples/
http://www.cplusplus.com/reference/cstring/strlen/
https://www.asciitable.com/
https://www.programiz.com/cpp-programming/library-function/cctype/toupper
https://www.geeksforgeeks.org/remove-spaces-from-a-given-string/


*/
#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;
//TAKEN FROM: https://www.geeksforgeeks.org/remove-spaces-from-a-given-string/
//has been adapted to remove all non letter characters, and to return an integer instead of void.
// An efficient C++ program to remove all spaces
// from a string
#include <iostream>
using namespace std;
 
// Function to remove all spaces from a given string
int removeSpaces(char *str)
{
    // To keep track of non-space character count
    int count = 0;
 
    // Traverse the given string. If current character
    // is not space, then place it at index 'count++'
    for (int i = 0; str[i]; i++)
      if (str[i] > 'A' && str[i] < 'Z')
            str[count++] = str[i]; // here count is
                                   // incremented
    //str[count] = '\0'; //I have commented out the carridge return because when reversing, it does funky stuff
    return count;
}

char[] reverseInput(char *pointyPointer) { //my own homegrown 100% organic non-gmo function
  char newArray[81];
  int index = 0;
  for (int i = strlen(pointyPointer) - 1; i != 0; i--) { //starts at the end of input adds everything in
    newArray[index] = pointyPointer[i];
    index++;

  }
  newArray[strlen(pointyPointer)] = '\0'; //adds that return carridge at the end.
  return newArray;


}


int main() {

  
	char input[81]; //reads in 80 characters
	char reverseInput[81];
	cin.getline(input, 81, '\n'); 
	
	cout << "You entered: " << input << endl;
	cout << "It has a length of " << strlen(input) << endl;
	int inputLength = strlen(input);
	for (int i = 0; i < inputLength; i++) { //uses the toupper(char) and goes thru entire input, have a temp 'ch' to store the input, then change it to an uppercase, and then plop it back into it's spot in the char array.
	  char ch = input[i];
	  input[i] = toupper(ch);
	}
	int newLength = removeSpaces(input);//a function that was modified from the interwebs
	cout << newLength << input << endl;
	reverseInput = reverseInput(input);


	
	if (strcmp(input, reverseInput) == 0) { //this means that they are equal
	cout << "Palindrome" << endl;




	} else { //not equal
	  cout << "Not A Palindrome" << endl; 

	}
	
	
	return 0;
}

