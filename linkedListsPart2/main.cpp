/*
Author: Bryce Truong
Date Created: 1/10/22
Last Modified: 1/14/22
*/

#include <iostream>
#include <cstring>
#include <cctype>
#include <stdio.h>
#include <ctype.h>
#include "Student.h"
#include "Node.h"


using namespace std;

void add(Node*& head, Student* newStudent);
void print(Node*& head, Node* next);

int main() {
  
  char input[50];
  bool running = true;
  Node* head = NULL;
  
  /*
  char* tempInput = new char[50];
  Student* testStudent = new Student();
  cin.getline(input, 50, '\n');
  strcpy(tempInput, input);
  testStudent->setStudentfName(temp);

  cout << testStudent->getStudentfName() << endl;
  
  add(head, testStudent);
  print(head, head);
  */
  
  /*
  add(head, 5);
  print(head, head);
  add(head, 7);
  print(head, head);
  add(head, 2);
  print(head, head);
  */
  
  while (running) {
    cout << "Welcome to the menu. Please select one of the following:\nADD\tDELETE\tPRINT\tQUIT" << endl;
    cin.getline(input, 50, '\n');
    if (strcmp(input, "ADD") == 0) {
      
      char* tempInput = new char[50];
      Student* tempSt = new Student();
      cout << "Enter Student Firstname: ";
      cin.getline(input, 50, '\n');
      strcpy(tempInput, input);
      tempSt->setStudentfName(tempInput);

      cout << "Enter Student Lirstname: ";
      cin.getline(input, 50, '\n');
      strcpy(tempInput, input);
      tempSt->setStudentlName(tempInput);

      cout << "Enter Student ID: ";
      cin.getline(input, 50, '\n');
      tempSt->setStudentID(atoi(input));

      cout << "Enter Student GPA: ";
      cin.getline(input, 50, '\n');
      tempSt->setStudentGPA((float)atof(input));

      add(head, tempSt);
      
    } else if (strcmp(input, "QUIT") == 0) {
      cout << "Exiting..." << endl;
      running = false;
    } else if (strcmp(input, "PRINT") == 0) {
      print(head, head);
    }
  }
  
}

void add(Node*& head, Student* newStudent) {
  Node* current = head;
  if (current == NULL) {
    head = new Node();
    head->setStudent(newStudent);
  } else {
    while (current->getNext() != NULL) {
      current = current->getNext();
    }
    current->setNext(new Node());
    current->getNext()->setStudent(newStudent);
  }
  
}


void print(Node*& head, Node* next) {
  if (next == head) {
    cout << "List of Students:\n" << endl;;
  }
  if (next != NULL) {
    cout << endl;
    cout << "-\t-\t-\t-\t-\t-\t-\t-" << endl;
    cout << "Firstname: ";
    cout << next->getStudent()->getStudentfName() << endl;
    cout << "Lastname: ";
    cout << next->getStudent()->getStudentlName() << endl;
    cout << "Student ID: ";
    cout << next->getStudent()->getStudentID() << endl;
    cout << "Student GPA: ";
    cout << next->getStudent()->getStudentGPA() << endl;
    
    print(head, next->getNext());
  }
}
