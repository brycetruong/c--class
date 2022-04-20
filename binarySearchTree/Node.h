#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;

class Node {
 public:
  Node();
  Node(int data);
  ~Node();//destroy the node
  
  void setData(int newData);
  int getData();

  void setLeft(Node * newLeft);
  void setRight(Node * newRight);

  Node * getLeft();
  Node * getRight();
  
 private:

  int data;

  Node * left;
  Node * right;
    
};

#endif
