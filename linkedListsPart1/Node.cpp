/*
Author: Bryce Truong
Date Created: 1/10/22
Last Modified: 1/14/22

*/
#include <iostream>
#include <cstring>
#include <stdio.h>
#include "Node.h"
#include "Student.h"

using namespace std;

Node::Node(){
  student = NULL;
  next = NULL;
}

Node::Node(Student* newStudent){
  student = newStudent;
  next = NULL;
}

Node::~Node(){
  delete student;
}

void Node::setStudent(Student* newStudent) {
  student = newStudent;
}

Student* Node::getStudent() {
  return student;
}

/*
void Node::setValue(int newValue) {
  value = newValue;
}

int Node::getValue() {
  return value;
}
*/

void Node::setNext(Node* newNext) {
  next = newNext;
}

Node* Node::getNext() {
  return next;
}
