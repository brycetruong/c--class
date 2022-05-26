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

void deletion(Node * & root, Node * found);
void leafRemove(Node * found);
void oneChildRemove(Node * & root, Node * found);
void twoChildRemove(Node * & root, Node * original, Node * current);
void deletionCases(Node * & root, Node * child);
void case3del(Node * & root, Node * child);

void insertion(Node * & root, Node * current, int data);
void insertionCases(Node * & root, Node * child);
void case4(Node * child); //tree rotation around parent
void case5(Node * & root, Node * child); //tree rotation around grandparent.

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
      int size = -1;
      ifstream Numbers;
      int number;
      Numbers.open("testFile.txt");
      for(int i = 0; i < 100; i++){
	if (!Numbers.eof()) {
	  Numbers >> number;
	  insertion(root, root, number);
	  size++;
	} else {
	  break;
	}
      }
      cout << size << endl;
    } else if (strcmp(input, "PRINT") == 0 || strcmp(input, "p") == 0 || strcmp(input, "print") == 0) {
      printAsTree(root, 0);
    } else if (strcmp(input, "REMOVE") == 0 || strcmp(input, "r") == 0 || strcmp(input, "remove") == 0) {
      cin.getline(input, 50, '\n');
      Node * found = search(root, atoi(input));
      if (found == NULL) {
	cout << "Error 404! No Node Found!" << endl;
      } else {
	deletion(root, root);
      }
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

void deletion(Node * & root, Node * found) {
  cout << "Node Found @ \'" << found << "\'\nWith data: \'" << found -> getData() << "\'\nAnd parent @ \'" << found -> getParent() << "\'" << endl;
  if (found == root) { //this is the root!
    //do something here
  } else if (found -> getLeft() == NULL && found -> getRight() == NULL) { //this is a leaf! no children
    leafRemove(found);
  } else if (found -> getRight() != NULL && found -> getLeft() != NULL) { //there are two children!
    twoChildRemove(root, found, found -> getRight());
  } else if (found -> getRight() != NULL || found -> getLeft() != NULL) {//if there is at least 1 child. and this is not the root
    oneChildRemove(root, found);
  }
}

void leafRemove(Node * found) {
  //fixing parent ptrs
  if (found -> getParent() -> getLeft() == found) { //comparing ptrs, this is a left child
    found -> getParent() -> setLeft(NULL);
  } else { //this has gotta be a right child
    found -> getParent() -> setRight(NULL);
  }

  delete found;
}

void oneChildRemove(Node * & root, Node * found) {
  // Deals with nodes with a single child, and repairs parent pointers
  if (found != root) {//root has a special case for removing
    
    Node * child = NULL;

    //parent ptr repair
    if (found -> getLeft() != NULL && found -> getRight() == NULL) { //if there is a single left child
      child = found -> getLeft();
      
      if (found -> getParent() -> getLeft() == found) { //comparing ptrs, this is a left child
	found -> getParent() -> setLeft(found -> getLeft()); //set my parents left to my child
	found -> getLeft() -> setParent(found -> getParent()); //set my childs parent to my parent
      } else { //this has gotta be a right child
	found -> getParent() -> setRight(found -> getLeft());
	found -> getLeft() -> setParent(found -> getParent()); //set my childs parent to my parent
      }
      
    } else if (found -> getRight() != NULL && found -> getLeft() == NULL) { //if there is a single right child
      child = found -> getRight();
      
      if (found -> getParent() -> getLeft() == found) { //comparing ptrs, this is a left child
	found -> getParent() -> setLeft(found -> getRight());
	found -> getRight() -> setParent(found -> getParent()); //set my childs parent to my parent
      } else { //this has gotta be a right child
	found -> getParent() -> setRight(found -> getRight());
	found -> getRight() -> setParent(found -> getParent()); //set my childs parent to my parent
      }

    }
    
    //recoloring
    Color myColor = found -> getColor();
    Color childColor = child -> getColor();
    if (myColor == red && childColor == black) {
      delete found;
    } else if (myColor == black && childColor == red) {
      child -> setColor(black);
      delete found;
    } else if (myColor == black && childColor == black) {
      deletionCases(root, child);
    }
    
  } else { //deleting root!
    
    Node * child = NULL;
    
    if (found -> getLeft() != NULL && found -> getRight() == NULL) { //if there is a single left child
      child = found -> getLeft();
      root = found -> getLeft();
      found -> getLeft() -> setParent(NULL);
    } else if (found -> getRight() != NULL && found -> getLeft() == NULL) { //if there is a single right child
      found = found -> getRight();
      root = found -> getRight();
      found -> getRight() -> setParent(NULL);
    }

    //recoloring
    Color myColor = found -> getColor();
    Color childColor = child -> getColor();
    if (myColor == red && childColor == black) {
      delete found;
    } else if (myColor == black && childColor == red) {
      child -> setColor(black);
      delete found;
    } else if (myColor == black && childColor == black) {
      delete found;
      deletionCases(root, child);
    }
    
  }
}

void deletionCases(Node * & root, Node * child) {  
  
  //case 1
  if (child == root) { //N is new root
    //done
    return;
  } //case 2
  else if (child -> getSibling() -> getColor() == red) {
    //tree rotation around parent
    case4(child);
    //call case 3
    case3del(root, child);
    
  } //case 3
  else if (child -> getSibling() -> getColor() == black) {
    case3del(root, child);
    
  } //case 4
  else if (child -> getParent() -> getColor() == red
	   && child -> getSibling() -> getColor() == black
	   && (child -> getSLC() -> getColor() == black || child -> getSLC() == NULL)
	   && (child -> getSRC() -> getColor() == black || child -> getSRC() == NULL)) {
    child -> getParent() -> setColor(black);
    child -> getSibling() -> setColor(red);
    
  } //case 5
  else if ( (child -> getSibling() -> getColor() == black //sibling is black
	     && child -> getSLC() -> getColor() == black //sibling left child is black
	     && child -> getSRC() -> getColor() == red //sibling right child is red
	     && child -> getParent() -> getRight() == child) //node is right
	    ||
	    (child -> getSibling() -> getColor() == black
	     && child -> getSRC() -> getColor() == black
	     && child -> getSLC() -> getColor() == red
	     && child -> getParent() -> getLeft() == child) ) {
    
    //rotate through sibling
    Node * sibling = child -> getSibling();
    sibling -> setColor(red);
    Node * src = child -> getSRC();
    Node * slc = child -> getSLC();
    if (child -> getParent() -> getRight() == child) { //node is a right (implies SRC == red)
      Node * c3 = src -> getLeft();
      
      child -> getParent() -> setLeft(src);
      src -> setParent(child -> getParent());

      src -> setLeft(sibling);
      sibling -> setParent(src);

      sibling -> setRight(c3);
      if (c3) c3 -> setParent(sibling);
            
    } else { //node is left (implies SLC == red)
      Node * c4 = slc -> getLeft();
      
      child -> getParent() -> setRight(slc);
      slc -> setParent(child -> getParent());

      slc -> setRight(sibling);
      sibling -> setParent(slc);
      
    }
    
  } //case 6
  else if ( (child -> getSibling() -> getColor() == black
	     && child -> getSLC() -> getColor() == red
	     && child -> getParent() -> getRight() == child)
	    ||
	    (child -> getSibling() -> getColor() == black
	     && child -> getSRC() -> getColor() == red
	     && child -> getParent() -> getLeft() == child) ) {
    //rotate through parent
    
  }
  
}

void case3del(Node * & root, Node * child) {
  child -> getSibling() -> setColor(red);
  deletionCases(root, child -> getParent()); //only call if parent is already black (kubirs advice)
  
}

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
    Node * parent = child -> getParent();
    case4(child);
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

void case4(Node * child) {
  cout << "\ttree rotation thru parent" << endl;
  //tree rotation through parent
  Node * parent = child -> getParent();
  Node * grand = child -> getGrand();
  if (child -> getParent() -> getRight() == child) { //this is a right, which implies that parent is a left (but only in insertion case 4)
    Node * c1 = parent -> getLeft();
    Node * c2 = child -> getLeft();
    Node * c3 = child -> getRight();
    
    if (grand) grand -> setLeft(child);
    child -> setParent(grand);
    
    child -> setLeft(parent);
    parent -> setParent(child);
    
    child -> setRight(c3); //useless
    if (c3) c3 -> setParent(child);
      
    parent -> setLeft(c1); //useless
    if (c1) c1 -> setParent(parent);
      
    parent -> setRight(c2);
    if (c2) c2 -> setParent(parent);
      
  } else { //this is a left, which implies that parent is a right (again only when we are inserting)
    Node * c3 = child -> getLeft();
    Node * c4 = child -> getRight();
    Node * c5 = parent -> getRight();

    if (grand) grand -> setRight(child);
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
}

void case5(Node * & root, Node * child) {
  //rotate through grandparent
  
  Node * parent = child -> getParent();
  Node * grand = child -> getGrand();
  

  if (grand != root) {
    cout << "\trotate thru g (not root)" << endl;
    Node * great = child -> getGrand() -> getParent();
    
    if (child -> getParent() -> getLeft() == child) { //this is a left, which implies that parent is a left too.
      Node * c3 = parent -> getRight();
      
      if (great -> getLeft() == grand) { //grandparent is a left
	grand -> getParent() -> setLeft(parent);
      } else {
	grand -> getParent() -> setRight(parent);
      }
      parent -> setParent(great);
      
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
      parent -> setParent(great);

      parent -> setLeft(grand);
      grand -> setParent(parent);

      grand -> setRight(c3);
      if (c3) c3 -> setParent(grand);

      parent -> setColor(black);
 
      grand -> setColor(red);
      
    }
  } else {
    cout << "\trotate thru g (root)" << endl;
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
    root -> setParent(NULL);
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
    //if (child -> getParent()) cout << child -> getParent() -> getData();
    cout << endl;
    if (child -> getLeft() != NULL) { //left
      printAsTree(child -> getLeft(), depth + 1);
    }
  } else {
    cout << "Tree is emp - tea" << endl;
  }
}
