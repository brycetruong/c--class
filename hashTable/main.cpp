
/*
Author: Bryce Truong
Date Created: 3/3/22
Last Modified: 3/9/22
This is a program.
*/

#include <iostream>
#include <cstring>
#include <cctype>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include<fstream>

#include "Node.h"

using namespace std;

Node * find(Node * next, char * name, int ID);

int getHashIndex(Node * toHash, int size);

int main() {
  srand(time(NULL));

  char firstnames[1912][10];
  ifstream FirstNames;
  FirstNames.open("firstnames.txt");
  int rows = 0;
  while (rows < 1912) {
    FirstNames >> firstnames[rows];
    rows++;
  }

  char lastnames[100][10];
  ifstream LastNames;
  LastNames.open("lastnames.txt");
  rows = 0;
  while (rows < 100) {
    LastNames >> lastnames[rows];
    rows++;
  }
  
  bool running = true;
  
  char input[50];
  
  int hashTableSize = 100;
  Node * hashTable[hashTableSize];
  for(int i = 0; i < hashTableSize; i++) {
    hashTable[i] = NULL;
  }

  while (running) {
    
    cout << "Enter mode: \n\t-ADD\n\t-DELETE\n\t-PRINT\n\t-RAND\n\t-QUIT" << endl;
    cin.getline(input, 50, '\n');
    if (strcmp(input, "ADD") == 0 || strcmp(input, "a") == 0) {
      Node * temp = new Node();

      cout << "Enter Student Firstname: ";
      cin.getline(input, 50, '\n');
      temp -> setfname(input);
      
      cout << "Enter Student Lastname: ";
      cin.getline(input, 50, '\n');
      temp -> setlname(input);
	
      cout << "Enter Student ID: ";
      cin.getline(input, 50, '\n');
      temp -> setID(atoi(input)); 
      
      cout << "Enter Student GPA: ";
      cin.getline(input, 50, '\n');
      temp -> setGPA(atof(input));

      if (hashTable[getHashIndex(temp, hashTableSize)] == NULL) {
      hashTable[getHashIndex(temp, hashTableSize)] = temp;
      } else if (hashTable[getHashIndex(temp, hashTableSize)] -> getNext() == NULL) {
	hashTable[getHashIndex(temp, hashTableSize)] -> setNext(temp);
      } else if (hashTable[getHashIndex(temp, hashTableSize)] -> getNext() -> getNext() == NULL) {
	hashTable[getHashIndex(temp, hashTableSize)] -> getNext() -> setNext(temp);
      } else { //there is three, time to rehash...
	
      }
      
    } else if (strcmp(input, "DELETE") == 0) {
      
    } else if (strcmp(input, "QUIT") == 0 || strcmp(input, "q") == 0) {
      running = false;
    } else if (strcmp(input, "PRINT") == 0 || strcmp(input, "p") == 0) {

      Node * temp = new Node();

      cout << "Enter Student Firstname: ";
      cin.getline(input, 50, '\n');
      temp -> setfname(input);

      cout << "Enter Student ID: ";
      cin.getline(input, 50, '\n');
      temp -> setID(atoi(input));

      if (hashTable[getHashIndex(temp, hashTableSize)] != NULL) {
	int index = getHashIndex(temp, hashTableSize);
	if (hashTable[index] -> getNext() == NULL) {
	  cout << "-\t-\t-\t-\t-\t-\t-\t-" << endl;
	  cout << "Firstname: ";
	  cout << hashTable[index] -> getfname() << endl;
	  cout << "Lastname: ";
	  cout << hashTable[index] -> getlname() << endl;
	  cout << "Student ID: ";
	  cout << hashTable[index] -> getID() << endl;
	  cout << "Student GPA: ";
	  cout << hashTable[index] -> getGPA() << endl;
	  cout << "-\t-\t-\t-\t-\t-\t-\t-" << endl;
	} else { //there is more than one match
	  Node * findTemp = find(hashTable[index], temp -> getfname(), temp -> getID());
	  cout << "-\t-\t-\t-\t-\t-\t-\t-" << endl;
	  cout << "Firstname: ";
	  cout << findTemp -> getfname() << endl;
	  cout << "Lastname: ";
	  cout << findTemp -> getlname() << endl;
	  cout << "Student ID: ";
	  cout << findTemp -> getID() << endl;
	  cout << "Student GPA: ";
	  cout << findTemp -> getGPA() << endl;
	  cout << "-\t-\t-\t-\t-\t-\t-\t-" << endl;
	}
      } else {
	cout << "No student by that name and ID" << endl;
      }
      delete temp;
      
    } else if (strcmp(input, "rand") == 0 || strcmp(input, "RAND") == 0) {
      int randLine = rand() % 1912;
      Node * temp = new Node();
      
      temp -> setfname(firstnames[randLine]);
      
      randLine = rand() % 100;
      temp -> setlname(lastnames[randLine]);

      temp -> setID(rand() % 89999 + 10000);

      cout << temp -> getfname() << endl;
      cout << temp -> getlname() << endl;
      cout << temp -> getID() << endl;
      
      if (hashTable[getHashIndex(temp, hashTableSize)] == NULL) {
      hashTable[getHashIndex(temp, hashTableSize)] = temp;
      } else if (hashTable[getHashIndex(temp, hashTableSize)] -> getNext() == NULL) {
	hashTable[getHashIndex(temp, hashTableSize)] -> setNext(temp);
      } else if (hashTable[getHashIndex(temp, hashTableSize)] -> getNext() -> getNext() == NULL) {
	hashTable[getHashIndex(temp, hashTableSize)] -> getNext() -> setNext(temp);
      } else { //there is three, time to rehash...
	
      }
      
    }
  }
  FirstNames.close();
  LastNames.close();
}

Node * find(Node * next, char * name, int ID) { //calls itself until it reaches the end (when the next is null)
  if (next != NULL) {
    if (strcmp(next -> getfname(), name) == 0 && next -> getID() == ID) {
      return next;
    }
    find(next -> getNext(), name, ID);
  }
  return NULL;
}

int getHashIndex(Node * toHash, int size) {
  char * fname = toHash -> getfname();
  char * lname = toHash -> getlname();
  int ID = toHash -> getID();
  
  int index = 0;
  
  int i = 0;
  while(fname[i] != '\0') {
    index += fname[i];
    i++;
  }
  index += ID;
  //cout << "Placed in index: " << index % size << endl;
  return index % size;
}
