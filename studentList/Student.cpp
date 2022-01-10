/*
Author: Bryce Truong
Date Created: 12/9/21
Last Modified: 12/9/21

*/
#include <iostream>
#include <cstring>
#include <stdio.h>
#include <iterator>
#include <map>
#include "Student.h"


using namespace std;

Student::Student(){
  
  desc = new char[500];
  
  roomname = new char[80];

}

Student::~Student(){
  delete[] desc;
  //delete exits; //do i need to delete this?
}

Student::Student(char* newDesc, char* newName) {
  desc = new char[500];
  strcpy(desc, newDesc);
  
  roomname = new char[80];
  strcpy(roomname, newName);
}

char* Student::getDesc() { // gets the description and returns as a char star
  return desc;
}

char* Student::getName() { //same as above
 return roomname; 
}
