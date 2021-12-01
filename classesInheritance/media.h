#ifndef MEDIA_H
#define MEDIA_H

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
	virtual ~media();
	media(char*, int);
	char* getTitle();
 	int getYear();
	int getType();
	
	protected:
	int year;
	char* title;
	int type;

};

#endif
