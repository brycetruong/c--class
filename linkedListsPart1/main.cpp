/*
Author: Bryce Truong
Date Created: 1/10/22
Last Modified: 1/10/22
*/

#include <iostream>
#include <cstring>
#include <cctype>
//#include "Student.h"
#include "Node.h"


using namespace std;

void add(Node* head, int newValue);
void print(Node* head, Node* next);

int main() {
  
  char input[20];
  bool running = true;
  Node* head = NULL;

  add(head, 5);
  print(head, head);
  add(head, 7);
  add(head, 2);
  print(head, head);
  
  while (running) {
    running = false;
    cin.getline(input, 20, '\n');
    add(head, atoi(input));
    print(head, head);
  }
  
}

void add(Node* head, int newValue) {
  Node* current = head;
  if (current == NULL) {
    head = new Node();
    head->setValue(newValue);
  } else {
    while (current->getNext() != NULL) {
      current = current->getNext();
    }
    current->setNext(new Node());
    current->getNext()->setValue(newValue);
  }
  
}


void print(Node* head, Node* next) {
  if (next == head) {
    cout << "testing: ";
  }
  if (next != NULL) {
    cout << next->getValue() << " ";
    print(head, next->getNext());
  }
}
