#ifndef ROOM_H
#define ROOM_H

/*
Author: Bryce Truong
Date Created: 1/10/21
Last Modified: 1/10/21
*/

#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

class Student {
	public:
	Student();
	~Student();
	Student(char*, char*);
	char* getDesc();
	char* getName();
		
	char* desc;
	char* roomname;
	
};

#endif
