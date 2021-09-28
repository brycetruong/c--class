/*
Author: Bryce Truong
Date Created: 9/22/21
Last Modified: 9/22/21
Palindrome Assignment

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
//has been adapted to remove all non letter characters
// An efficient C++ program to remove all spaces
// from a string
#include <iostream>
using namespace std;
 
// Function to remove all spaces from a given string
void removeSpaces(char *str)
{
    // To keep track of non-space character count
    int count = 0;
 
    // Traverse the given string. If current character
    // is not space, then place it at index 'count++'
    for (int i = 0; str[i]; i++)
      if (str[i] > 'A' || str[i] < 'Z')
            str[count++] = str[i]; // here count is
                                   // incremented
    str[count] = '\0';
}


int main() {

  
	char input[81]; //reads in 80 characters
	char reverseInput[81];
	cin.getline(input, 81, '\n'); 
	
	cout << "You entered: " << input << endl;
	cout << "It has a length of " << strlen(input) << endl;
	int inputLength = strlen(input);
	for (int i = 0; i < inputLength; i++) {
	  char ch = input[i];
	  input[i] = toupper(ch);


	}
	removeSpaces(input);
	cout << input << endl;
        




	
	if (strcmp(input, reverseInput) == 0) { //this means that they are equal
	cout << "Palindrome" << endl;




	} else { //not equal
	  cout << "Not A Palindrome" << endl; 

	}
	
	
	return 0;
}

