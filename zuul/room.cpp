/*
Author: Bryce Truong
Date Created: 12/9/21
Last Modified: 12/9/21

*/
#include <iostream>
#include <cstring>
#include <stdio.h>
#include "room.h"

using namespace std;

room::room(){
  
  desc = new char[20];

}

room::~room(){
  delete[] desc;
}

room::room(char* newDesc){
  desc = new char[80];
  strcpy(desc, newDesc);
}

char* room::getDesc(){
  return desc;
}
