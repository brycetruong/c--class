/*
Author: Bryce Truong
Date Created: 10/18/21
Last Modified: 10/27/21

This is a program that reads out student lists.


Sources:
https://www.geeksforgeeks.org/vector-in-cpp-stl/
https://www.geeksforgeeks.org/vectorat-vectorswap-c-stl/
https://www.geeksforgeeks.org/vectorbegin-vectorend-c-stl/
https://java2blog.com/vector-of-structs-in-cpp/
https://www.cplusplus.com/reference/cstdlib/atoi/
https://www.cplusplus.com/reference/cstdlib/atof/
https://www.geeksforgeeks.org/vector-erase-and-clear-in-cpp/
https://www.geeksforgeeks.org/vectoroperator-vectoroperator-c-stl/


Kubir's vast c++ knowledge;)

*/
#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <array>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iterator>

using namespace std;

struct Student { // initializes my struct with 2 char arrays, an int and, a float
  char fname[10];
  char lname[10];
  int uid;
  float gpa;


};

int main() {
  char input[10];
  bool stillRunning = true;
  
  vector<Student*> myVec;
  while (stillRunning == true) {
    cout << "Enter mode: \n\t-ADD\n\t-DELETE\n\t-PRINT\n\t-QUIT" << endl;
    cin.getline(input, 10, '\n');
    if (strcmp(input, "ADD") == 0) {
      cout << "Add Mode\n--------" << endl;
      Student* temp = new Student();
      
      cout << "Enter Student Firstname: " << endl;
      cin.getline(input, 10, '\n');
      strcpy(temp -> fname, input);

      cout << "Enter Student Lastname: " << endl;
      cin.getline(input, 10, '\n');
      strcpy(temp -> lname, input);
      
      //cout << temp.uid << endl;

      cout << "Enter StudentID: " << endl;
      cin.getline(input, 10, '\n');
      temp -> uid = atoi(input);

      cout << "Enter GPA: " << endl;
      cin.getline(input, 10, '\n');
      temp -> gpa = atof(input);
      
      myVec.push_back(temp);
      
      //cout << myVec.at(0) -> fname << endl;
    } else if (strcmp(input, "DELETE") == 0) {
      //cout << "DELETE" << endl;
      cout << "Delete Mode\n--------" << endl;
      
      cout << "Enter StudentID to PURGE FROM EXISTENCE: " << endl;
      cin.getline(input, 10, '\n');
      for (vector<Student*>::iterator i = myVec.begin(); i != myVec.end(); i++) {
	if((*i) -> uid == atoi(input)) {
	  myVec.erase(i);
	  break;
	}
      }
    } else if (strcmp(input, "QUIT") == 0) {
      cout << "Exiting..." << endl;
      stillRunning = false;
    } else if (strcmp(input, "PRINT") == 0) {
      //cout << "PRINT" << endl;
      for (int i = 0; i < myVec.size(); i++) {
	cout << "\tFirstname: " << myVec.at(i) -> fname << endl;
	cout << "\tLirstname: " << myVec.at(i) -> lname << endl;
	cout << "\tStudentID: " << myVec.at(i) -> uid << endl;
	cout << "\tGPA: " << myVec.at(i) -> gpa << endl;
	cout << endl;
      }

    } else {
      cout << "Plese entr a vald impoot" << endl;
    }
  }
  
  return 0;
}
