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
  Student(char*, char*, int, double); //You are passing in: Firstname, Lastname, StudentID, GPA in that order.

  char* getFname();
  char* getLname();
  int getID();
  double getGPA();
  
private:
  
  char* fname;
  char* lname;
  int id;
  double gpa;
  
};

#endif
