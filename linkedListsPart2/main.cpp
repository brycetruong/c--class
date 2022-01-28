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
#include <iomanip> //this is for setprecision()
#include "Student.h"
#include "Node.h"


using namespace std;

void add(Node*& head, Student* newStudent);
void print(Node* next);
void addGPA(Node* current, float& GPA);
void deleteNode(Node*& head, Node* current, int id);

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
    cout << "Welcome to the menu. Please select one of the following:\nADD\tDELETE\tPRINT\tAVERAGE\tQUIT" << endl;
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
      print(head);
    } else if (strcmp(input, "DELETE") == 0) {
      //delete
			cout << "Enter Student ID: ";
			cin.getline(input, 50, '\n');
      deleteNode(head, head, atoi(input));
    } else if (strcmp(input, "AVERAGE") == 0) {
      float temp = 0.0;
			addGPA(head, temp);
    } else {
      cout << "Input not recognized..." << endl;
    }
  }
  
}

void add(Node*& head, Student* newStudent) {
  Node* current = head;
  if (current == NULL) {
    head = new Node();
    head->setStudent(newStudent);
  } else {
    while (current->getNext() != NULL) {//go to the end of the list
      current = current->getNext();
    }
    current->setNext(new Node());
    current->getNext()->setStudent(newStudent);
  }
  
}


void print(Node* next) {
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
    cout << setprecision(3) << next->getStudent()->getStudentGPA() << endl;
    
    print(next->getNext());
    
  }
}

void addGPA(Node* current, float& GPA) {
	if (current != NULL) {
		GPA += current->getStudent()->getStudentGPA();
		addGPA(current->getNext(), GPA);
	} else {
		cout << GPA << endl;
	}
}

void deleteNode(Node*& head, Node* current, int id) {
  if (current != NULL) {
    if (false/*current->getStudent()->getStudentID() == id*/) {
      Node* temp = current;
      if (current->getNext() != NULL) {
	      current->setNext(current->getNext());
        
      } else {
	      current->setNext(NULL);
      }
      delete temp;
    } else if (current->getNext() != NULL && current->getNext()->getStudent()->getStudentID() == id) {
      
      Node* temp = current->getNext();
      if (current->getNext()->getNext() != NULL) { //if two spaces forwards is not null
        current->setNext(current->getNext()->getNext()); //repair the link
        
      } else { //if two nodes forwards IS null
       current->setNext(NULL);
      }
      
      delete temp;
    } else {
      deleteNode(head, current->getNext(), id);
      
    }
  } else {
		cout << "No student by that ID found" << endl;
	}
}

