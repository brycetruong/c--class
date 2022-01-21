#ifndef STUDENT_H
#define STUDENT_H

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
  ~Student();//destructor
  Student(char*, char*, int, float); //You are passing in: Firstname, Lastname, StudentID, GPA in that order.

  //all of these you will use to get the firstname, lastname, student ID and GPA.
  char* getFname();
  char* getLname();
  int getID();
  double getGPA();
  
private:
  
  char* fname;
  char* lname;
  int id;
  float gpa;
  
};

#endif
