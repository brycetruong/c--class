/*
Author: Bryce Truong
Date Created: 2/8/22
Last Modified: 2/8/22
*/

#include "Node.h"
Node::Node(){
  data = '\0';
  next = NULL;
}
Node::~Node(){
  
}
void Node::setNext(Node* newNext){
  next=newNext;
}
Node*  Node::getNext(){
  return next;
}
void Node::setData(char newData){
  data = newData;
}
char  Node::getData(){
  return data;
}
