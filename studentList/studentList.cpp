/*
Author: Bryce Truong
Date Created: 10/18/21
Last Modified: 10/26/21

This is a program that reads out student lists.


Sources:
https://www.geeksforgeeks.org/vector-in-cpp-stl/
https://www.geeksforgeeks.org/vectorat-vectorswap-c-stl/
https://www.geeksforgeeks.org/vectorbegin-vectorend-c-stl/
https://java2blog.com/vector-of-structs-in-cpp/

Kubir's vast knowledge banks ;)

*/
#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <array>
#include <stdio.h>
#include <vector>
#include <iterator>

using namespace std;

struct Student {
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
      cout << "Add Mode\n--------\nEnter Student Firstname: " << endl;
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
      strcpy(temp -> uid, input);

      cout << "Enter GPA: " << endl;
      cin.getline(input, 10, '\n');
      strcpy(temp -> gpa, input);
      
      myVec.push_back(temp);
      
      //cout << myVec.at(0) -> fname << endl;
    } else if (strcmp(input, "DELETE") == 0) {
      cout << "DELETE" << endl;
    } else if (strcmp(input, "QUIT") == 0) {
      cout << "QUIT" << endl;
      stillRunning = false;
    } else if (strcmp(input, "PRINT") == 0) {
      //cout << "PRINT" << endl;
      for (int i = 0; i < myVec.size(); i++) {
	cout << "Firstname: " << myVec.at(i) -> fname << endl;
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
