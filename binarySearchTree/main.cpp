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

void twoChildRemove(Node * & root, Node * original, Node * current);

void oneChildRemove(Node * & root, Node * found);

void printAsTree(Node * child, int depth);

void insert(Node * & root, Node * current, int data);

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
      insert(root, root, atoi(input));
    } else if (strcmp(input, "FILE") == 0 || strcmp(input, "f") == 0 || strcmp(input, "file") == 0) {
      ifstream Numbers;
      int number;
      Numbers.open("numbers.txt");
      for(int i = 0; i < 100; i++){
	if (!Numbers.eof()) {
	  Numbers >> number;
	  insert(root, root, number);
	}
      }      
    } else if (strcmp(input, "PRINT") == 0 || strcmp(input, "p") == 0 || strcmp(input, "print") == 0) {
      printAsTree(root, 0);
    } else if (strcmp(input, "REMOVE") == 0 || strcmp(input, "r") == 0 || strcmp(input, "remove") == 0) {
      cin.getline(input, 50, '\n');
      Node * found = search(root, atoi(input));
      if (found == NULL) {
	cout << "Error 404! No Node Found!" << endl;
      } else {
	cout << "Node Found @ \'" << found << "\'\nWith data: \'" << found -> getData() << "\'\nAnd parent @ \'" << found -> getParent() << "\'" << endl;
	if (found -> getParent() == NULL) { //this is the root!
	  if (found -> getRight() != NULL && found -> getLeft() != NULL) { //if there are two children
	    twoChildRemove(root, found, found -> getRight());
	  } else if (found -> getRight() != NULL || found -> getLeft() != NULL) {//if there is at least 1 child.
	    oneChildRemove(root, found);
	  } else { //there are no children!
	    delete found;
	    root = NULL;
	  }
	} else if (found -> getLeft() == NULL && found -> getRight() == NULL) { //this is a leaf! no children
	  if (found -> getParent() -> getLeft() == found) { //comparing ptrs, this is a left child
	    found -> getParent() -> setLeft(NULL);
	    delete found;
	  } else { //this has gotta be a right child
	    found -> getParent() -> setRight(NULL);
	    delete found;
	  }
	} else if (found -> getRight() != NULL && found -> getLeft() != NULL) { //there are two children!
	  twoChildRemove(root, found, found -> getRight());
	} else if (found -> getRight() != NULL || found -> getLeft() != NULL) {//if there is at least 1 child. and this is not the root
	  oneChildRemove(root, found);
	}
      }

    } else if (strcmp(input, "SEARCH") == 0 || strcmp(input, "s") == 0 || strcmp(input, "search") == 0) {
      cin.getline(input, 50, '\n');
      Node * found = search(root, atoi(input));
      if (found == NULL) {
	cout << "Error 404! No Node Found!" << endl;
      } else {
	cout << "Node Found @ \'" << found << "\'\nWith data: \'" << found -> getData() << "\'\nAnd parent @ \'" << found -> getParent() << "\'" << endl;
      }
      
    } else if (strcmp(input, "QUIT") == 0 || strcmp(input, "q") == 0 || strcmp(input, "quit") == 0) {
      break;
    } else {
      cout << "not recognized..." << endl;
    }
  }
}

//special function for removing a node with two children
void twoChildRemove(Node * & root, Node * original, Node * current) { //IMPORTANT: YOU PASS IN original's RIGHT CHILD as "current" to start off!
  if (current -> getParent() == original && current -> getLeft() == NULL) {//special case where there is nothing to the left and this is the first one
    original -> setData(current -> getData());
    oneChildRemove(root, current);
  } else {
    if (current -> getLeft() != NULL) {
      twoChildRemove(root, original, current -> getLeft());
    } else { //we have reached the far left
      original -> setData(current -> getData());
      oneChildRemove(root, current);
    }
  }
}

void oneChildRemove(Node * & root, Node * found) {
  /* Deals with single children, and repairs parent pointers


   */
  if (found != root) {//root has a special case for removing
    if (found -> getLeft() != NULL && found -> getRight() == NULL) { //if there is a single left child
      if (found -> getParent() -> getLeft() == found) { //comparing ptrs, this is a left child
	found -> getParent() -> setLeft(found -> getLeft()); //set my parents left to my child
	found -> getLeft() -> setParent(found -> getParent()); //set my childs parent to my parent
	delete found;
      } else { //this has gotta be a right child
	found -> getParent() -> setRight(found -> getLeft());
	found -> getLeft() -> setParent(found -> getParent()); //set my childs parent to my parent
	delete found;
      }
    } else if (found -> getRight() != NULL && found -> getLeft() == NULL) { //if there is a single right child
      if (found -> getParent() -> getLeft() == found) { //comparing ptrs, this is a left child
	found -> getParent() -> setLeft(found -> getRight());
	found -> getRight() -> setParent(found -> getParent()); //set my childs parent to my parent
	delete found;
      } else { //this has gotta be a right child
	found -> getParent() -> setRight(found -> getRight());
	found -> getRight() -> setParent(found -> getParent()); //set my childs parent to my parent
	delete found;
      }
    } else { //it has to be a leaf
      if (found -> getParent() -> getLeft() == found) { //comparing ptrs, this is a left child
	found -> getParent() -> setLeft(NULL);
	delete found;
      } else { //this has gotta be a right child
	found -> getParent() -> setRight(NULL);
	delete found;
      }
    }
  } else {
    if (found -> getLeft() != NULL && found -> getRight() == NULL) { //if there is a single left child
      root = found -> getLeft();
      found -> getLeft() -> setParent(NULL);
      delete found;
    } else if (found -> getRight() != NULL && found -> getLeft() == NULL) { //if there is a single right child
      root = found -> getRight();
      found -> getRight() -> setParent(NULL);
      delete found;
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

void insert(Node * & root, Node * current, int data) { //smaller on left, bigger or =to on the right
  if (root == NULL) {
    root = new Node(data);
  } else if (current -> getData() > data) {//the node that we want to add is smaller than the current node's data
    if (current -> getLeft() == NULL) { //we have reached the end
      Node * child = new Node(data);
      child -> setParent(current);
      current -> setLeft(child);
    } else {
      insert(root, current -> getLeft(), data); //put it in the left one
    }
  } else {
    if (current -> getRight() == NULL) {
      Node * child = new Node(data);
      child -> setParent(current);
      current -> setRight(child);
    } else {
      insert(root, current -> getRight(), data); //if it is greater or == to, then put it in the right.
    }
  }
}

void printAsTree(Node * child, int depth) {
  if (child != NULL) {
    if (child -> getRight() != NULL) { //right
      printAsTree(child -> getRight(), depth + 1); //recursivly call the function on the right side (until it reaches the end in which the index > size and increase the depth each time we go down a level)
    }
    for (int i = 0; i < depth; i++) { //increases the number of tabs
      cout << "\t";
    }
    cout << child -> getData() << endl;
    if (child -> getLeft() != NULL) { //left
      printAsTree(child -> getLeft(), depth + 1);
    }
  } else {
    cout << "Tree is emp - tea" << endl;
  }
}
