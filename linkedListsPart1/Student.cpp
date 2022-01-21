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

Student::Student(){
  
  fname = new char[80];
  lname = new char[80];

  id = 0;

  gpa = 0.0;
}

Student::~Student(){
  delete[] fname;
  delete[] lname;
}

Student::Student(char* newFname, char* newLname, int newID, float newGPA) {
  fname = new char[80];
  strcpy(fname, newFname);

  fname = new char[80];
  strcpy(fname, newFname);

  id = newID;

  gpa = newGPA;
}

char* Student::getFname() {
 return fname; 
}

char* Student::getLname() {
 return fname; 
}

int Student::getID() {
  return id;
}

double Student::getGPA() {
  return gpa;
}
