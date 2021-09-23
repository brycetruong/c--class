/*
Author: Bryce Truong
Date Created: 9/22/21
Last Modified: 9/22/21
Palindrome Assignment


*/
#include <iostream>
#include <cstring>

using namespace std;

int main() {
	
	char input[80];
	char reverseInput[20];
	cin.get(input, 80); 
	
	cout << input << endl;
	int count = 0;







	
	if (strcmp(input, reverseInput) == 0) { //this means that they are equal
	cout << "Palindrome" << endl;




	} else { //not equal
	  cout << "Not A Palindrome" << endl; 

	}
	/*for (int i = 0; i < 20; i++) {
	  if (str[i] != '\0'){
	    str2[count] = str[i];
	    count++;
	  }


	  }*/
	
	
	return 0;
}

