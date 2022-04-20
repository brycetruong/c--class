/*
Author: Bryce Truong
Date Created: 4/20/22
Last Modified: 4/20/22

This is a binary search tree.
*/
#include <iostream>
#include <cstring>
#include <cctype>
#include <stdio.h>
#include <ctype.h>

#include "Node.h"

void printAsTree(Node * child, int depth);

void insert(Node * & root, Node * current, int data);

int search(Node * root, int searchFor);

using namespace std;

int main() {
  
  char input[50];

  Node * root = NULL;
  while (true) {
    cout << "/na/add/ADD\nf/file/FILE\np/print/PRINT\nr/remove/REMOVE\ns/search/SEARCH\nq/quit/QUIT\n" << endl;
    cin.getline(input, 50, '\n');

    if (strcmp(input, "ADD") == 0 || strcmp(input, "a") == 0 || strcmp(input, "add") == 0) {
      cout << "Insert: ";
      cin.getline(input, 50, '\n');
      insert(root, root, atoi(input));
    } else if (strcmp(input, "FILE") == 0 || strcmp(input, "f") == 0 || strcmp(input, "file") == 0) {

    } else if (strcmp(input, "PRINT") == 0 || strcmp(input, "p") == 0 || strcmp(input, "print") == 0) {
      printAsTree(root, 0);
    } else if (strcmp(input, "REMOVE") == 0 || strcmp(input, "r") == 0 || strcmp(input, "remove") == 0) {

    } else if (strcmp(input, "SEARCH") == 0 || strcmp(input, "s") == 0 || strcmp(input, "search") == 0) {

    } else if (strcmp(input, "QUIT") == 0 || strcmp(input, "q") == 0 || strcmp(input, "quit") == 0) {
      break;
    } else {
      cout << "not recognized..." << endl;
    }
  }
}

int search(Node * root, int searchFor) {
  
}

void insert(Node * & root, Node * current, int data) {
  if (root == NULL) {
    root = new Node(data);
  } else if (current -> getData() > data) {//the node that we want to add is smaller than the current node's data
    if (current -> getLeft() == NULL) { //we have reached the end
      current -> setLeft(new Node(data));
    } else {
      insert(root, current -> getLeft(), data); //put it in the left one
    }
  } else {
    if (current -> getRight() == NULL) {
      current -> setRight(new Node(data));
    } else {
      insert(root, current -> getRight(), data); //if it is greater or == to, then put it in the right.
    }
  }
}

void printAsTree(Node * child, int depth) {
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
}
