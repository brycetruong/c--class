/*
Author: Bryce Truong
Date Created: 1/10/22
Last Modified: 1/14/22
*/

#include <iostream>
#include <cstring>
#include <cctype>
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
  
  running = true;
  while (running) {
    
    char* tempInput = new char[50];
    Student* tempSt = new Student();
    cout << "Enter Student Firstname: ";
    cin.getline(input, 20, '\n');
    cout << input << endl;
    
    
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
    cout << "testing: ";
  }
  if (next != NULL) {
    cout << next->getStudent()->getStudentfName() << " ";
    print(head, next->getNext());
  }
}
