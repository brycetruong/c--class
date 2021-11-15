/*
Author: Bryce Truong
Date Created: 11/5/21
Last Modified: 11/5/21



*/
#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

class media {
	public:
	media();
	media(char*);
	char* getTitle();
 	int getYear();
	
	private:
	int year;
	char* title;

};
