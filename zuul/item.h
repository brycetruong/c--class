#ifndef ITEM_H
#define ITEM_H

/*
Author: Bryce Truong
Date Created: 12/13/21
Last Modified: 12/13/21


*/
#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

class item {
	public:
	item();
	~item();
	item(char*);
	char* getName();
	
	char* name;

};

#endif
