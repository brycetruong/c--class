/*
Author: Bryce Truong
Date Created: 2/7/22
Last Modified: 2/27/22

This is a program that first uses the Shunting Yard Algorithm to convert infix notation to postfix notation,
and then contructs a binary expression tree with all the operands and operators.

Afterwards, it will prompt the user what type of notation they would like the output in.
You can enter "infix", "prefix", or "postfix"

This program uses two ADTs; a singly linear linked list stack, and a singly linear linked list queue.
Respective functions were made to pop, push, peek, queue and dequeue Node classes into and out of the lists.

No global variables were used in the making of this program.
No strings were used in this project, only character arrays.

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

void enqueue(Node * & head, char data); // First version of enqueue, that just makes a new node with an inputed character
void enqueue(Node * & head, Node * toAdd); //a second version of enqueue that that takes in an already existing node ptr
//instead of creating a new one from scratch

void push(Node * & head, char data); //basically the same as 'enqueue' so I didn't add another function for it
void push(Node * & head, Node * toAdd);

Node * pop(Node * & head);

char peek(Node * head); //looks at the top of the stack (literally the simplest function in the entire program)

Node * dequeue(Node * & head, Node * current); //takes from the back of the queue

void print(Node * next); //prints starting from the head and going back

int main() {
  
  char input[50];
  bool running = true;

  Node * shead = new Node();
  
  Node * qhead = new Node();
  
  cin.getline(input, 50, '\n');

  /* SHUNTING YARD ALGORITHIM */
  
  int i = 0;
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

  /* - - - - - - - - - - */
  
  /*
  cout << endl;
  cout << "queue (remember its backwards rn)" << endl;
  print(qhead);
  cout << endl;
  cout << "stack" << endl;
  print(shead);
  */
  
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
      beTree -> setRight(pop(shead)); //set the right one before the left one
      beTree -> setLeft(pop(shead));
      push(shead, beTree);
    } else if (beTree -> getData() == '\0') { //if it is the last one (which means it's empty)
      beTree = pop(shead);
      qEmpty = true;
    }
    
  }

  /* - - - - - - - - - - */
  
  while (true) {
    cout << "Enter: \"infix\", \"postfix\", \"prefix\", \"quit\"" << endl;
    cin.getline(input, 50, '\n');  
    if (strcmp(input, "infix") == 0) {
      infix(beTree);
      cout << endl;
    } else if (strcmp(input, "postfix") == 0) {
      postfix(beTree);
      cout << endl;
    } else if (strcmp(input, "prefix") == 0) {
      prefix(beTree);
      cout << endl;
    } else if (strcmp(input, "quit") == 0) {
      break;
    } else {
      cout << "input not recognized" << endl;
    }
  }
  
  
  
}

/* TRAVERSAL FUNCTIONS */

void infix (Node * tree) {
  if (tree != NULL) {
    if (tree -> getData() == '+'
	|| tree -> getData() == '-'
	|| tree -> getData() == '/'
	|| tree -> getData() == '*'
	|| tree -> getData() == '^') { //any operators get their own pair of parenthesis
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
  if (tree != NULL) {
    postfix(tree -> getLeft());
    postfix(tree -> getRight());
    cout << tree -> getData();
  }
}

void prefix (Node * tree) {
  if (tree != NULL) {
    cout << tree -> getData();
    prefix(tree -> getLeft());
    prefix(tree -> getRight());
  }
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

/* PUSHING FUNCTIONS */

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
    head -> setData(toAdd -> getData()); //copying over the data from toAdd over to head
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

/* - - - - - - - - - - - - - */

/* POPPING AND DEQUEUE */

Node * pop(Node * & head) {
  if (head -> getData() != '\0') {
    Node * temp = new Node();
    //makes a new node, grabs all of head's data, then deletes the ptr to head while returning a new node
    temp -> setData(head -> getData());
    temp -> setLeft(head -> getLeft());
    temp -> setRight(head -> getRight());
    
    if (head -> getNext() != NULL) { //makes sure I dont accidentally turn head into NULL, which would be bad because I call functions to get head's data with pop.
      Node * tempDel = head;
      head = head -> getNext();
      delete tempDel;
    } else {
      head -> setData('\0'); //clear the head by just reseting its data.
    }
    return temp;
  } else {
    return head;
    //if you try and pop when the stack is empty, then it just returns a blank node (which should have '\0' as the data)
  }
}

Node * dequeue(Node * & head, Node * current) {
  if (current -> getNext() != NULL) {//makes sure there isn't only one node in the list
    if (current -> getNext() -> getNext() == NULL) {//if the next node is the last one in the list.
      Node * temp = current -> getNext();
      current -> setNext(NULL);
      return temp;
    } else {
      return dequeue(head, current -> getNext()); //recursion to get all the way until the end of the LL queue
      //then returns all the way back through the function.
    }
  } else {
    Node * temp = new Node();
    temp -> setData(head -> getData());
    
    head -> setData('\0');
    
    return temp;
  }
}

/* - - - - - - - - - - - - - */

char peek(Node * head) { //why do I even exist... :(
  return head -> getData();
}
