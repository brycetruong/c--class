#ifndef NODE_H
#define NODE_H

/*
Author: Bryce Truong
Date Created: 1/10/21
Last Modified: 1/14/21
*/

#include <iostream>
#include "Student.h"

using namespace std;

class Node {
 public:
  Node();
  Node(Student* newStudent);
  ~Node();//destroy the node
  
  void setStudent(Student* newStudent);
  Student* getStudent();

  /*
  void setValue(int newValue);
  int getValue();
  */
  
  void setNext(Node* newNext);
  Node* getNext();
  
 private:

  Student* student;
  //int value;
  Node* next;
    
};

#endif
