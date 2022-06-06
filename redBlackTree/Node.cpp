#include "Node.h"

Node::Node() {
  data = 0;
  left = NULL;
  right = NULL;
  parent = NULL;
  color = red;
}

Node::Node(int newData) {
  data = newData;
  left = NULL;
  right = NULL;
  parent = NULL;
  color = red;
}

Node::~Node(){
  
}

void Node::setColor(Color newColor) {
  color = newColor;
}
Color Node::getColor() {
  return color;
}
void Node::coutColorASCII() {
  if (color == red) {
    cout << "\033[1;31m" << "r" << "\033[0m";
  } else { //color is black
    cout << "b";
  }
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
    return parent -> getParent();
  }
  return NULL;
}

Node * Node::getAunt() {
  if (parent) {
    return parent -> getSibling();
  }
  return NULL;
}

Node * Node::getSibling() {
  if (parent) {
    if (parent -> getLeft() == this) { //I am the left child
      return parent -> getRight();
    } else { // I am the right child
      return parent -> getLeft();
    }
  }
  return NULL;
}

Node * Node::getSLC() {
  if (getSibling()) {
    return getSibling() -> getLeft();
  }
  return NULL;
}

Node * Node::getSRC() {
  if (getSibling()) {
    return getSibling() -> getRight();
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
