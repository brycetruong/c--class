/*
Author: Bryce Truong
Date Created: 11/5/21
Last Modified: 11/5/21



*/
#include <iostream>
#include <cstring>
#include <stdio.h>
#include "media.h"


using namespace std;

media::media(){
  //strcpy(title, newTitle);
  title = new char[20];
  year = 2000;
}

media::media(char* newTitle, int newYear){
  title = new char[20];
  strcpy(title, newTitle);
  year = newYear;
}

char* media::getTitle(){
  return title;
}

int media::getYear(){
  return year;
}
