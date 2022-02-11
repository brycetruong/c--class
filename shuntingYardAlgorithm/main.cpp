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

void enqueue(Node * & head, char data); //basically the same as 'push' so I didn't add another function for it

void push(Node * & head, char data);

Node * pop(Node * & head);

char peek(Node * head);

Node * dequeue(Node * & head, Node * current);

void print(Node * next);

int main() {
  
  char input[50];
  bool running = true;

  Node * shead = new Node();
  
  Node * qhead = new Node();
  
  //print(qhead);

  enqueue(qhead, 'a');

  enqueue(qhead, 'b');

  enqueue(qhead, 'c');

  print(qhead);
  
  cout << dequeue(qhead, qhead)->getData() << endl;

  cout << dequeue(qhead, qhead)->getData() << endl;

  cout << dequeue(qhead, qhead)->getData() << endl;
  
  print(qhead);

  push(shead, 'a');

  push(shead, 'b');

  push(shead, 'c');

  print(shead);

  cout << pop(shead)->getData() << endl;

  cout << pop(shead)->getData() << endl;

  cout << pop(shead)->getData() << endl;

  cout << pop(shead)->getData() << endl;
}

void print(Node * next) { //calls itself until it reaches the end (when the next is null)
  if (next != NULL) {
    cout << "-\t-\t-" << endl;
    cout << "Contained char: ";
    cout << next -> getData() << endl;
    
    print(next -> getNext());
    
  }
}

void enqueue(Node * & head, char data) {
  if(head -> getData() == '\0') {
    head -> setData(data);
  } else {
    Node * temp = new Node();
    temp -> setData(data);
    temp -> setNext(head);
    head = temp;
  }
}

void push(Node * & head, char data) {
  enqueue(head, data);
}

Node * pop(Node * & head) {
  Node * temp = new Node();
  temp -> setData(head -> getData());
  
  if (head -> getNext() != NULL) { //makes sure I dont accidentally turn head into NULL, which would be bad because I call functions to get head's data with pop.
    Node * tempDel = head;
    head = head -> getNext();
    delete tempDel;
  } else {
    head -> setData('\0'); //clear the head
  }
  return temp;
}

Node * dequeue(Node * & head, Node * current) {
  if (current -> getNext() != NULL) {//makes sure there isn't only one node in the list
    if (current -> getNext() -> getNext() == NULL) {//if the next node is the last one in the list.
      Node * temp = current -> getNext();
      current -> setNext(NULL);
      temp -> setNext(NULL);
      return temp;
    } else {
      return dequeue(head, current -> getNext());
    }
  } else {
    Node * temp = new Node();
    temp -> setData(head -> getData());
    
    head -> setData('\0');
    
    return temp;
  }
}

char peek(Node * head) {
  return head -> getData();
}
