/*
Author: Bryce Truong
Date Created: 1/10/22
Last Modified: 1/10/22

*/
#include <iostream>
#include <cstring>
#include <stdio.h>
#include "Node.h"


using namespace std;

Node::Node(){
  value = 0;
  next = NULL;
}

Node::~Node(){
  delete &value;
  next = NULL;
}

void Node::setValue(int newValue) {
  value = newValue;
}

int Node::getValue() {
  return value;
}

void Node::setNext(Node* newNext) {
  next = newNext;
}

Node* Node::getNext() {
  return next;
}
