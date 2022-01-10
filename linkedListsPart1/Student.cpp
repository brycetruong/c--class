/*
Author: Bryce Truong
Date Created: 1/10/22
Last Modified: 1/10/22

*/
#include <iostream>
#include <cstring>
#include <stdio.h>
#include "Student.h"


using namespace std;

Student:Student(){
  
  fname = new char[80];
  lname = new char[80];
  
}

Student:~Student(){
  delete[] name;
}

Student:Student(char* newFname, char* newLname) {
  fname = new char[80];
  strcpy(fname, newFname);

  fname = new char[80];
  strcpy(fname, newFname);
  
}

char* Student::getFname() {
 return fname; 
}
