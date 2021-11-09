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

media::media(char newTitle){
  //strcpy(title, newTitle);
  year = 1;
}

char media::getTitle(){
  return title;
}

int media::getYear(){
  return year;
}
