#include "Student.h"

//Author: Tom
//Co Author: Bryce

Student::Student(){

}
Student::~Student(){

}

Student::Student(char* newFname, char* newLname, int newID, double newGPA) {
  fname = new char[80];
  strcpy(fname, newFname);

  fname = new char[80];
  strcpy(fname, newFname);

  ID = newID;

  GPA = newGPA;
}

void Student::setStudentfName(char* newfName){
  fname = new char[50];
  strcpy(fname, newfName);
}

char* Student::getStudentfName(){
  return fname;
}

void Student::setStudentlName(char* newlName){
  lname = new char[50];
  strcpy(lname, newlName);
}

char* Student::getStudentlName(){
  return lname;
}

void Student::setStudentID(int newID){
  ID = newID;
}
int Student::getStudentID(){
  return ID;
}
void Student::setStudentGPA(float newGPA){
  GPA = newGPA;
}
float Student::getStudentGPA(){
  return GPA;
}
