#ifndef ROOM_H
#define ROOM_H

/*
Author: Bryce Truong
Date Created: 12/9/21
Last Modified: 12/9/21


*/
#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

class room {
	public:
	room();
	~room();
	room(char*);
	char* getDesc();
	
	char* desc;

};

#endif
