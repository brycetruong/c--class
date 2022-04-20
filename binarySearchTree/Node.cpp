#include "Node.h"

Node::Node(){
  data = 0;
  left = NULL;
  right = NULL;
}

Node::Node(int newData){
  data = newData;
  left = NULL;
  right = NULL;
}

Node::~Node(){
  
}

void Node::setData(int newData){
  data = newData;
}
int Node::getData(){
  return data;
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
