/*
Author: Bryce Truong
Date Created: 2/7/22
Last Modified: 2/8/22
*/

#include <iostream>
#include <cstring>
#include <cctype>
#include <stdio.h>
#include <ctype.h>

#include "Node.h"

using namespace std;

void add(Node * & head, char newData);

char peek(Node * head);

Node * dequeue(Node * head);

void print(Node * next);

int main() {
  
  char input[50];
  bool running = true;

  Node * shead = new Node();
  
  Node * qhead = new Node();
  print(qhead);
}

void print(Node * next) { //calls itself until it reaches the end (when the next is null)
  if (next != NULL) {
    cout << endl;
    cout << "-\t-\t-" << endl;
    cout << "Contained char: ";
    cout << next -> getData();

    print(next -> getNext());

  }
}
