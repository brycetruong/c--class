/*
Author: Bryce Truong
Date Created: 2/7/22
Last Modified: 2/17/22

This is a program that first uses the Shunting Yard Algorithm to convert infix notation to postfix notation,
and then contructs an expression tree
*/

#include <iostream>
#include <cstring>
#include <cctype>
#include <stdio.h>
#include <ctype.h>

#include "Node.h"

using namespace std;

void infix (Node * tree);
void postfix (Node * tree);
void prefix (Node * tree);

int getPrecedence(char oper); //finds the precedence of the operator (nothing in there is 0, +- is 1, */ is 2, and ^ is 3)

int getAsso(char oper); // 0 is left associativity, and 1 is right

void enqueue(Node * & head, char data); //basically the same as 'push' so I didn't add another function for it
void enqueue(Node * & head, Node * toAdd);

void push(Node * & head, char data);
void push(Node * & head, Node * toAdd);

Node * pop(Node * & head);

char peek(Node * head);

Node * dequeue(Node * & head, Node * current);

void print(Node * next);

int main() {
  
  char input[50];
  bool running = true;

  Node * shead = new Node();
  
  Node * qhead = new Node();
  
  cin.getline(input, 50, '\n');

  int i = 0;
  int j = 0;
  char output[50];
  while (input[i] != '\0') { //loop through the entire character array.
    if (input[i] == ' ') {
      i++;
    } else {
      if (input[i] >= '0' && input[i] <= '9') { //if it is a number enqueue it into the output queue
	enqueue(qhead, input[i]);
	i++;
      } else if (input[i] == '+'
		 || input[i] == '-'
		 || input[i] == '/'
		 || input[i] == '*'
		 || input[i] == '^') { //if it's an operator
	while (peek(shead) != '\0'
	       && ((getPrecedence(peek(shead)) > getPrecedence(input[i])) //while there's an operator on the top of the stack with greater precedence
		   || (getPrecedence(peek(shead)) == getPrecedence(input[i])//they have the same precedence
		       && (getAsso(peek(shead)) == 0 && getAsso(input[i]) == 0)//both left associative
		       )
		   )
	       ) {
	  enqueue(qhead, pop(shead)); //Pop operators from the stack and enqueue onto the output queue
	}
	push(shead, input[i]); //push the current op onto the stack
	i++;
      } else if (input[i] == '(') { //if left bracket, push to stack
	push(shead, input[i]);
	i++;
      } else if (input[i] == ')') {
	while (peek(shead) != '(') { //While there's not a left bracket at the top of the stack
	  if (peek(shead) != '\0') {
	    enqueue(qhead, pop(shead)); //Pop operators from the stack and enqueue onto the output queue
	  } else { //if you get to the end without finding the matching parenthesis...
	    cout << "Mismatching Parenthesis!" << endl;
	    break;
	  }
	}
	delete pop(shead); //discard the left parenthesis
	i++;
      } else {
	cout << "Probably a bad input (note: you shouldn't ever see this message...)" << endl;
      }
    }
  }
  while (peek(shead) != '\0') { //While there are operators on the stack, pop them to the queue
    	    enqueue(qhead, pop(shead)); //Pop operators from the stack and enqueue onto the output queue
  }

  cout << endl;
  cout << "queue (remember its backwards rn)" << endl;
  print(qhead);
  cout << endl;
  cout << "stack" << endl;
  print(shead);
  
  /* BINARY EXPRESSION TREE CREATION */

  
  bool qEmpty = false;
  Node * beTree = NULL;
  while (qEmpty == false) {
    
    beTree = dequeue(qhead, qhead);
    if(beTree -> getData() >= '0' && beTree -> getData() <= '9') { // if number, push it onto the stack
      push(shead, beTree);
    } else if (beTree -> getData() == '+'
	       || beTree -> getData() == '-'
	       || beTree -> getData() == '/'
	       || beTree -> getData() == '*'
	       || beTree -> getData() == '^') { //if it is an op, set the right and then the left, then push it back into the stack
      beTree -> setRight(pop(shead));
      beTree -> setLeft(pop(shead));
      push(shead, beTree);
    } else if (beTree -> getData() == '\0') { //if it is the last one (which means it's empty)
      beTree = pop(shead);
      qEmpty = true;
    }
    
  }
  
  
  infix(beTree);

  
  /*
  push(shead, 'a');

  push(shead, 'b');

  push(shead, 'c');

  print(shead);

  enqueue(qhead, pop(shead));
  
  enqueue(qhead, pop(shead));

  enqueue(qhead, pop(shead));

  print(qhead);
  
  
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
  */
}

/* TRAVERSAL FUNCTIONS */

void infix (Node * tree) {
  if (tree != NULL) {
    if (tree -> getData() == '+'
	|| tree -> getData() == '-'
	|| tree -> getData() == '/'
	|| tree -> getData() == '*'
	|| tree -> getData() == '^') {
      cout << '(';
    }
    infix(tree -> getLeft());
    
    cout << tree -> getData();
    
    infix(tree -> getRight());
    
    if (tree -> getData() == '+'
	|| tree -> getData() == '-'
	|| tree -> getData() == '/'
	|| tree -> getData() == '*'
	|| tree -> getData() == '^') {
      cout << ')';
    }
  }
}

void postfix (Node * tree) {

}

void prefix (Node * tree) {

}

/* - - - - - - - - - - */

/* PRECEDENCE AND ASSOCIATIVITY */

int getPrecedence(char oper) { //finds the precedence of the operator (nothing in there is 0, +- is 1, */ is 2, and ^ is 3)
  if (oper == '+' || oper == '-') {
    return 1;
  } else if (oper == '*' || oper == '/') {
    return 2;
  } else if (oper == '^') {
    return 3;
  } else if (oper == '\0') { //if the stack is empty
    return 0;
  } else {
    //probably a parenthesis or some other thing
    return 0;
  }
}

int getAsso(char oper) { // 0 is left associativity, and 1 is right
  if (oper == '^') {
    return 1;
  } else {
    return 0;
  }
  
}

/* - - - - - - - - - - - - - */


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

void enqueue(Node * & head, Node * toAdd) {
  if (head -> getData() == '\0') {
    head -> setData(toAdd -> getData());
    head -> setLeft(toAdd -> getLeft());
    head -> setRight(toAdd -> getRight());
    delete toAdd;
  } else {
    toAdd -> setNext(head);
    head = toAdd;
  }
}

void push(Node * & head, char data) {
  enqueue(head, data);
}

void push(Node * & head, Node * toAdd) {
  enqueue(head, toAdd);
}

Node * pop(Node * & head) {
  if (head -> getData() != '\0') {
    Node * temp = new Node();
    temp -> setData(head -> getData());
    temp -> setLeft(head -> getLeft());
    temp -> setRight(head -> getRight());
    
    if (head -> getNext() != NULL) { //makes sure I dont accidentally turn head into NULL, which would be bad because I call functions to get head's data with pop.
      Node * tempDel = head;
      head = head -> getNext();
      delete tempDel;
    } else {
      head -> setData('\0'); //clear the head
    }
    return temp;
  } else {
    return head;
  }
}

Node * dequeue(Node * & head, Node * current) {
  if (current -> getNext() != NULL) {//makes sure there isn't only one node in the list
    if (current -> getNext() -> getNext() == NULL) {//if the next node is the last one in the list.
      Node * temp = current -> getNext();
      current -> setNext(NULL);
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
