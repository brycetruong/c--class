/*
Author: Bryce Truong
Date Created: 2/8/22
Last Modified: 2/8/22
*/

#include "Node.h"
Node::Node(){
  data = '\0';
  next = NULL;
  left = NULL;
  right = NULL;
}
Node::~Node(){
  
}
void Node::setNext(Node* newNext){
  next = newNext;
}
Node * Node::getNext(){
  return next;
}
void Node::setData(char newData){
  data = newData;
}
char Node::getData(){
  return data;
}

void Node::setLeft(Node* newLeft){
  left = newLeft;
}

void Node::setRight(Node* newRight){
  right = newRight;
}

Node * Node::getLeft(){
  return left;
}

Node * Node::getRight(){
  return right;
}
