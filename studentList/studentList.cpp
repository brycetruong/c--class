/*
Author: Bryce Truong
Date Created: 10/18/21
Last Modified: 10/18/21



*/
#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <array>
#include <stdio.h>
#include <vector>

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
    cin.getline(input, 10, '\n');
    if (strcmp(input, "ADD") == 0) {
      cout << "Add Mode\n--------\nEnter Student Name: " << endl;
      cin.getline(input, 10, '\n');
      myVec.push_back(new Student());
      myVec[0]->fname = input;
      cout << myVec[0]->fname << endl;
    } else if (strcmp(input, "DELETE") == 0) {
      cout << "DELETE" << endl;
    } else if (strcmp(input, "QUIT") == 0) {
      cout << "QUIT" << endl;
      stillRunning = false;
    } else if (strcmp(input, "PRINT") == 0) {
    cout << "PRINT" << endl;
    } else {
      cout << "Plese entr a vald imkapoot" << endl;
    }
  }
  
  return 0;
}
