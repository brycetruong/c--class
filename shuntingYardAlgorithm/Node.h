#ifndef NODE_H
#define NODE_H

/*
Author: Bryce Truong
Date Created: 2/7/22
Last Modified: 2/7/22
*/

#include <iostream>

using namespace std;

class Node {
 public:
  Node();
  Node(char data);
  ~Node();//destroy the node
  
  void setData(char newData);
  char getData();
  
  void setNext(Node* newNext);
  Node* getNext();

  void setLeft(Node*);
  void setRight(Node*);

  Node * getLeft();
  Node * getRight();
  
 private:

  char data;
  Node* next;

  Node * left;
  Node * right;
    
};

#endif
