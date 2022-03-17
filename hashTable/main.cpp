
/*
Author: Bryce Truong
Date Created: 3/3/22
Last Modified: 3/9/22
This is a program with a hash function. It places students inside and array index. You can add remove delete print (search) for students.
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

void rehash(Node ** &oldHashTable, int &size);

Node * find(Node * next, char * name, int ID);

int getHashIndex(Node * toHash, int size);

int main() {
  srand(time(NULL));
  
  char firstnames[1912][10]; //set up my files for first names and last names.
  ifstream FirstNames; // I put them all into a big 2D character array, so I can just access the lines like "firstnames[linum]"
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
  Node ** hashTable = new Node * [hashTableSize];
  for(int i = 0; i < hashTableSize; i++) { //since there is already random memory there, clear everything.
    hashTable[i] = NULL;
  }

  while (running) { //main loop
    
    cout << "Enter mode: \n\t-ADD\n\t-DELETE\n\t-PRINT\n\t-RAND\n\t-QUIT" << endl;
    cin.getline(input, 50, '\n');
    if (strcmp(input, "ADD") == 0 || strcmp(input, "a") == 0 || strcmp(input, "add") == 0) {
      Node * temp = new Node(); //makes a new node to add into the hash table.
      
      cout << "Enter Student Firstname: "; //prompt for firstnmaes, ln, ID, and GPA
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

      if (hashTable[getHashIndex(temp, hashTableSize)] == NULL) { //this block handles collisions. I was too lazy to make a function that uses recursion to step thru the LL, and since it's only 3...
	hashTable[getHashIndex(temp, hashTableSize)] = temp;
      } else if (hashTable[getHashIndex(temp, hashTableSize)] -> getNext() == NULL) {
	hashTable[getHashIndex(temp, hashTableSize)] -> setNext(temp);
      } else if (hashTable[getHashIndex(temp, hashTableSize)] -> getNext() -> getNext() == NULL) {
	hashTable[getHashIndex(temp, hashTableSize)] -> getNext() -> setNext(temp);
      } else { //there is three already, time to rehash...
	hashTable[getHashIndex(temp, hashTableSize)] -> getNext() -> getNext() -> setNext(temp);
	rehash(hashTable, hashTableSize);	
      }
      
    } else if (strcmp(input, "DELETE") == 0 || strcmp(input, "d") == 0) {
      Node * temp = new Node();
      cout << "Delete Mode\n" << endl;
      cout << "Enter Student Firstname: ";
      cin.getline(input, 50, '\n');
      temp -> setfname(input);

      cout << "Enter Student ID: ";
      cin.getline(input, 50, '\n');
      temp -> setID(atoi(input));

      if (hashTable[getHashIndex(temp, hashTableSize)] != NULL) {
	int index = getHashIndex(temp, hashTableSize);
	if (hashTable[index] -> getNext() == NULL) {
	  cout << "Purged from existence!" << endl;
	  delete hashTable[index];
	  hashTable[index] = NULL;
	} else { //there is more than one match
	  Node * findTemp = find(hashTable[index], temp -> getfname(), temp -> getID()); //find() basically looks through a LL to find a match.
	  if (findTemp != NULL) {
	    cout << "Purged from existence!" << endl;
	    if (findTemp == hashTable[index]) { //easy, this is the first one and there are linked students ahead!
	      hashTable[index] = hashTable[index] -> getNext();
	      delete findTemp;
	    } else if (findTemp == hashTable[index] -> getNext()) { //if the match is at the second student
	      if (findTemp -> getNext() == NULL) { //if there is only two in the hash table index (the first one and this one which is linked to the next of the first one)
		hashTable[index] -> setNext(NULL); //basically nothing at third
		delete findTemp;
	      } else { //gotta attach the first one to the third one
		hashTable[index] -> setNext(findTemp -> getNext());
		delete findTemp;
	      }
	    } else if (findTemp == hashTable[index] -> getNext() -> getNext()) { //if the match is at the third student
	      hashTable[index] -> getNext() -> setNext(NULL);
	      delete findTemp;
	    }
	  } else {
	    cout << "No student by that name and ID" << endl;
	  }
	}
      } else {
	cout << "No student by that name and ID" << endl;
      }
       
    } else if (strcmp(input, "QUIT") == 0 || strcmp(input, "q") == 0) {
      running = false;
    } else if (strcmp(input, "PRINT") == 0 || strcmp(input, "p") == 0 || strcmp(input, "print") == 0) {
      cout << "Print Mode\n" << endl;
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
	  Node * findTemp = find(hashTable[index], temp -> getfname(), temp -> getID()); //find() basically looks through a LL to find a match.
	  if (findTemp != NULL) {
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
	  } else {
	    cout << "No student by that name and ID" << endl;
	  }
	}
      } else {
	cout << "No student by that name and ID" << endl;
      }
      delete temp;
      
    } else if (strcmp(input, "rand") == 0 || strcmp(input, "RAND") == 0 || strcmp(input, "r") == 0) {
      cout << "Enter # of student to add: ";
      cin.getline(input, 50, '\n');
      for (int i = 0; i < atoi(input); i++) {

	int randLine = rand() % 1912;
	Node * temp = new Node();
      
	temp -> setfname(firstnames[randLine]);
      
	randLine = rand() % 100;
	temp -> setlname(lastnames[randLine]);

	temp -> setID(rand() % 89999 + 10000); //gets a number between 10000 and 99999 (a five digit student ID)

	temp -> setGPA((rand() % 400 + 100)/(float)(100));
      
	cout << "-" << endl;
	cout << temp -> getfname() << endl;
	cout << temp -> getlname() << endl;
	cout << temp -> getID() << endl;
	cout << temp -> getGPA() << endl;
      
      
	if (hashTable[getHashIndex(temp, hashTableSize)] == NULL) {//this big if block handles collisions
	  hashTable[getHashIndex(temp, hashTableSize)] = temp;
	} else if (hashTable[getHashIndex(temp, hashTableSize)] -> getNext() == NULL) {
	  hashTable[getHashIndex(temp, hashTableSize)] -> setNext(temp);
	} else if (hashTable[getHashIndex(temp, hashTableSize)] -> getNext() -> getNext() == NULL) {
	  hashTable[getHashIndex(temp, hashTableSize)] -> getNext() -> setNext(temp);
	} else { //there is three already, time to rehash...
	  hashTable[getHashIndex(temp, hashTableSize)] -> getNext() -> getNext() -> setNext(temp);
	  rehash(hashTable, hashTableSize);
	}
      }
    }
  }
  FirstNames.close(); //closes my files after I'm done with them
  LastNames.close();
}

Node * find(Node * next, char * name, int ID) { //calls itself until it reaches the end (when the next is null)
  if (next != NULL) {
    if (strcmp(next -> getfname(), name) == 0 && next -> getID() == ID) {
      return next;
    } else {
      return find(next -> getNext(), name, ID);
    }
  } else {
    return NULL; //need to do something here, bc this means that there is a hash match for that index, but not a match for the firstname, and the ID
  }
}

void rehash(Node ** &oldHashTable, int &size) {
  cout << "\t REHASHING \t :)" << endl;
  size = size * 2; //double size
  Node ** newHashTable = new Node * [size]; //make a new hashtable
  for(int i = 0; i < size; i++) {
    newHashTable[i] = NULL;
  }

  for (int i = 0; i < size/2; i++) { //loop thru old array
    while(oldHashTable[i]) { //while still stuff here
      Node * student = oldHashTable[i];
      oldHashTable[i] = student -> getNext();
      student -> setNext(NULL);
      
      int newIndex = getHashIndex(student, size);
      if (newHashTable[newIndex] == NULL) { //this big if block handles collisions
        newHashTable[newIndex] = student;
      } else if (newHashTable[newIndex] -> getNext() == NULL) {
        newHashTable[newIndex] -> setNext(student);
      } else if (newHashTable[newIndex] -> getNext() -> getNext() == NULL) {
        newHashTable[newIndex] -> getNext() -> setNext(student);
      } else { //there is three, time to rehash...
	cout << "VERY BAD, YOU GOT 3 COLLISIONS EVEN WHEN U REHASHED U MONKE!" << endl; //idk too lazy to do anything about this.
      }
    }
  }
  delete oldHashTable; //(hopefully) get rid of the old array.
  oldHashTable = newHashTable;
}

int getHashIndex(Node * toHash, int size) {
  char * fname = toHash -> getfname();
  char * lname = toHash -> getlname(); //i was going to also include the lastname in the hash, but then it'd be harder to print (which is basically searching)
  int ID = toHash -> getID();
  
  int index = 0;
  int i = 0;
  //my personal hash algorithim: add together the characters of the firstname, then add the ID and mod table size.
  while(fname[i] != '\0') {
    index += fname[i];
    i++;
  }
  index += ID; //also add the ID to the hash
  //cout << "Returned index: " << index % size << endl;
  return index % size;
}
