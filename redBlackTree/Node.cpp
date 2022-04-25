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

Node * Node::getGrand() {
  if (parent) {
    if (parent -> getParent()) {
      return parent -> getParent();
    }
  }
  return NULL;
}

Node * Node::getAunt() {
  if (parent) {
    if (parent -> getSibling()) {
      return parent -> getParent();
    }
  }
  return NULL;
}

Node * Node::getSibling() {
  if (parent) {
    if (parent -> getLeft()) {
      return parent -> getParent();
    }
  }
  return NULL;
}

void Node::setLeft(Node * newLeft){
  left = newLeft;
}
Node * Node::getLeft(){
  return left;
}

void Node::setRight(Node * newRight){
  right = newRight;
}
Node * Node::getRight(){
  return right;
}
