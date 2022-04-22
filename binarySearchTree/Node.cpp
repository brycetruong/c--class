#include "Node.h"

Node::Node(){
  data = 0;
  left = NULL;
  right = NULL;
  parent = NULL;
}

Node::Node(int newData){
  data = newData;
  left = NULL;
  right = NULL;
  parent = NULL;
}

Node::~Node(){
  
}

void Node::setData(int newData){
  data = newData;
}
int Node::getData(){
  return data;
}

void Node::setParent(Node * newPar){
  parent = newPar;
}

Node * Node::getParent() {
  return parent;
}

void Node::setLeft(Node * newLeft){
  left = newLeft;
}

void Node::setRight(Node * newRight){
  right = newRight;
}

Node * Node::getLeft(){
  return left;
}

Node * Node::getRight(){
  return right;
}
