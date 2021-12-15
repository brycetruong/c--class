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
#include <vector>
#include <iterator>
#include "item.h"

using namespace std;

class room {
	public:
	room();
	~room();
	room(char*);
	char* getDesc();
	addItem();
	remItem();
	printItems();
	
	char* desc;
	vector<item*> roomInv;

};

#endif
