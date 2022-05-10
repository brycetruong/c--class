/*
Author: Bryce Truong
Date Created: 4/20/22
Last Modified: 4/25/22
This is a binary search tree.
*/
#include <iostream>
#include <cstring>
#include <cctype>
#include <stdio.h>
#include <ctype.h>
#include<fstream>
#include<cmath>

#include "Node.h"

void printAsTree(Node * child, int depth);

void insertion(Node * & root, Node * current, int data);

void insertionCases(Node * & root, Node * child);

void case5(Node * & root, Node * child);

Node * search(Node * root, int searchFor);

using namespace std;

int main() {
  
  char input[50];

  Node * root = NULL;
  
  while (true) {
    cout << "\na/add/ADD\nf/file/FILE\np/print/PRINT\nr/remove/REMOVE\ns/search/SEARCH\nq/quit/QUIT\n" << endl;
    cin.getline(input, 50, '\n');
    
    if (strcmp(input, "ADD") == 0 || strcmp(input, "a") == 0 || strcmp(input, "add") == 0) {
      cout << "Insert: ";
      cin.getline(input, 50, '\n');
      insertion(root, root, atoi(input));
    } else if (strcmp(input, "FILE") == 0 || strcmp(input, "f") == 0 || strcmp(input, "file") == 0) {
      int size = 0;
      ifstream Numbers;
      int number;
      Numbers.open("numbers.txt");
      for(int i = 0; i < 100; i++){
	if (!Numbers.eof()) {
	  Numbers >> number;
	  insertion(root, root, number);
	  size++;
	}
      }
      cout << size << endl;
    } else if (strcmp(input, "PRINT") == 0 || strcmp(input, "p") == 0 || strcmp(input, "print") == 0) {
      printAsTree(root, 0);
    } else if (strcmp(input, "REMOVE") == 0 || strcmp(input, "r") == 0 || strcmp(input, "remove") == 0) {
    } else if (strcmp(input, "SEARCH") == 0 || strcmp(input, "s") == 0 || strcmp(input, "search") == 0) {
      
      cin.getline(input, 50, '\n');
      Node * found = search(root, atoi(input));
      if (found == NULL) {
	cout << "Error 404! No Node Found!" << endl;
      } else {
	cout << "Node Found @ \'" << found << "\'\nWith data: \'" << found -> getData() << "\'\nAnd parent @ \'" << found -> getParent() << "\'\nWith data: \'" << found -> getParent() -> getData() << "\'" << endl;
      }
      
    } else if (strcmp(input, "QUIT") == 0 || strcmp(input, "q") == 0 || strcmp(input, "quit") == 0) {
      break;
    } else {
      cout << "not recognized..." << endl;
    }
  }
}

Node * search(Node * root, int searchFor) {
  if (root != NULL) { //if there even is a tree
    if (root -> getData() == searchFor) {
      return root;
    } else if (searchFor < root -> getData() && root -> getLeft() != NULL) { //it is on the left
      return search(root -> getLeft(), searchFor);
    } else if (searchFor > root -> getData() && root -> getRight() != NULL) {
      return search(root -> getRight(), searchFor);
    } else if (root -> getRight() == NULL && root -> getLeft() == NULL) {
      return NULL;
    }
  } else {
    cout << "Tree is emp - tea" << endl;
  }
  return NULL;
}

void insertion(Node * & root, Node * current, int data) {//smaller on left, bigger or =to on the right
  if (root == NULL) {
    root = new Node(data);
    insertionCases(root, root);
    //root -> setColor(black);
  } else if (current -> getData() > data) {//the node that we want to add is smaller than the current node's data (add on left)
    if (current -> getLeft() == NULL) { //we have reached the end
      Node * child = new Node(data);
      child -> setParent(current);
      current -> setLeft(child);
      insertionCases(root, child);
    } else {
      insertion(root, current -> getLeft(), data); //put it in the left one
    }
  } else { //add on right
    if (current -> getRight() == NULL) {
      Node * child = new Node(data);
      child -> setParent(current);
      current -> setRight(child);
      insertionCases(root, child);
    } else {
      insertion(root, current -> getRight(), data); //if it is greater or == to, then put it in the right.
    }
  }
}


void insertionCases(Node * & root, Node * child) { //fixes the colors, and other stuff

  if (child == root) { //its gotta be the root
    cout << "\troot" << endl;
    child -> setColor(black);
  } else if (child -> getParent() &&
      child -> getParent() -> getColor() == black) { //parent black
    cout << "\tparentBlack" << endl;
    return;
  } else if (child -> getParent() && child -> getAunt() &&//having an uncle/aunt implies there is a grandparent
	     child -> getParent() -> getColor() == red && child -> getAunt() -> getColor() == red) { //if the parent is red, and the aunt is red
    cout << "\tp+u=b\tg=r" << endl;
    //change parent and uncle to black
    child -> getParent() -> setColor(black);
    child -> getAunt() -> setColor(black);
    //change the grandparent to red
    child -> getGrand() -> setColor(red);
    //recursively call on grandparent
    insertionCases(root, child -> getGrand());
  } else if (child -> getParent() && child -> getGrand() &&
	     (child -> getAunt() == NULL || child -> getAunt() -> getColor() == black) && //because black is the same as a null node
	     ( (child -> getParent() -> getRight() == child && child -> getGrand() -> getLeft() == child -> getParent()) || //this is right and the parent is a left
	       (child -> getParent() -> getLeft() == child && child -> getGrand() -> getRight() == child -> getParent()) //this is left and parent is a right
	       ) ) {
    cout << "\ttree rotation thru parent" << endl;
    //tree rotation through parent
    Node * parent = child -> getParent();
    Node * grand = child -> getGrand();
    if (child -> getParent() -> getRight() == child) { //this is a right, which implies that parent is a left
      Node * c1 = parent -> getLeft();
      Node * c2 = child -> getLeft();
      Node * c3 = child -> getRight();

      grand -> setLeft(child);
      child -> setParent(grand);
      
      child -> setLeft(parent);
      parent -> setParent(child);

      child -> setRight(c3); //useless
      if (c3) c3 -> setParent(child);

      parent -> setLeft(c1); //useless
      if (c1) c1 -> setParent(parent);

      parent -> setRight(c2);
      if (c2) c2 -> setParent(parent);
      
    } else { //this is a left, which implies that parent is a right
      Node * c3 = child -> getLeft();
      Node * c4 = child -> getRight();
      Node * c5 = parent -> getRight();

      grand -> setRight(child);
      child -> setParent(grand);

      child -> setRight(parent);
      parent -> setParent(child);

      child -> setLeft(c3); //useless
      if (c3) c3 -> setParent(child);
      
      parent -> setLeft(c4);
      if (c4) c4 -> setParent(parent);

      parent -> setRight(c5); //useless
      if (c5) c5 -> setParent(parent);
      
    }
    //CALL CASE 5 ON PARENT
    case5(root, parent);
  } else if (child -> getParent() && child -> getGrand() &&
	     (child -> getAunt() == NULL || child -> getAunt() -> getColor() == black) &&
	     ( (child -> getParent() -> getRight() == child && child -> getGrand() -> getRight() == child -> getParent()) || //this is right and the parent is a right
	       (child -> getParent() -> getLeft() == child && child -> getGrand() -> getLeft() == child -> getParent()) //this is left and parent is a left
	      )
	     ) { //case 5
    case5(root, child);
  }
}

void case5(Node * & root, Node * child) {
  //rotate through grandparent
  cout << "\trotate thru g" << endl;
  Node * parent = child -> getParent();
  Node * grand = child -> getGrand();
  

  if (grand != root) {
    Node * great = child -> getGrand() -> getParent();
    
    if (child -> getParent() -> getLeft() == child) { //this is a left, which implies that parent is a left too.
      Node * c3 = parent -> getRight();
      
      if (great -> getLeft() == grand) { //grandparent is a left
	grand -> getParent() -> setLeft(parent);
      } else {
	grand -> getParent() -> setRight(parent);
      }
      
      parent -> setRight(grand);
      grand -> setParent(parent);

      grand -> setLeft(c3);
      if (c3) c3 -> setParent(grand);

      parent -> setColor(black);

      grand -> setColor(red);
      
    } else {//this is a right, which implies parent is a right
      Node * c3 = parent -> getLeft();

      if (great -> getLeft() == grand) { //grandparent is a left
	grand -> getParent() -> setLeft(parent);
      } else {
	grand -> getParent() -> setRight(parent);
      }

      parent -> setLeft(grand);
      grand -> setParent(parent);

      grand -> setRight(c3);
      if (c3) c3 -> setParent(grand);

      parent -> setColor(black);
 
      grand -> setColor(red);
      
    }
  } else {
    if (child -> getParent() -> getLeft() == child) { //this is a left, which implies that parent is a left too.
      Node * c3 = parent -> getRight();
      
      parent -> setRight(grand);
      grand -> setParent(parent);

      grand -> setLeft(c3);
      if (c3) c3 -> setParent(grand);

      parent -> setColor(black);

      grand -> setColor(red);

      root = parent;
      
    } else {//this is a right, which implies parent is a right
      Node * c3 = parent -> getLeft();
      
      parent -> setLeft(grand);
      grand -> setParent(parent);

      grand -> setRight(c3);
      if (c3) c3 -> setParent(grand);

      parent -> setColor(black);
 
      grand -> setColor(red);

      root = parent;
      
    }
  }
}



void printAsTree(Node * child, int depth) {
  if (child != NULL) {
    if (child -> getRight() != NULL) { //right
      printAsTree(child -> getRight(), depth + 1); //recursivly call the function on the right side (until it reaches the end in which the index > size and increase the depth each time we go down a level)
    }
    for (int i = 0; i < depth; i++) { //increases the number of tabs
      cout << "      ";
    }
    cout << "|--- " << child -> getData();
    child -> coutColorASCII();
    cout << endl;
    if (child -> getLeft() != NULL) { //left
      printAsTree(child -> getLeft(), depth + 1);
    }
  } else {
    cout << "Tree is emp - tea" << endl;
  }
}
