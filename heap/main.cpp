/*
Author: Bryce Truong
Date Created: 3/28/22
Last Modified: Sometime April, idk

This program creates a heap in the form of an array. You can add a number, or use the file filled with up to 100 numbers (mine only has 50).

Here is a heap visualization that I found helpful: https://www.cs.usfca.edu/~galles/visualization/Heap.html

*/

#include <iostream>
#include <cstring>
#include <cctype>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include<fstream>
#include<cmath>

using namespace std;

const int ROOT = 1;

const int MAX_SIZE = 100;

void insert(int * heap, int currentIndex);

void printAsArray(int * heap, int size);

void printAsTree(int * heap, int index, int depth, int size);

void remove(int * heap, int currentIndex, int size);

void bubbleSort(int * heap, int &size);

int main() {

  char input[50];

  int size = 0;
  int numbers[100]; //sets up my array with a file full of numbers
  for(int i = 0; i < 100; i++){
    numbers[i] = -1;
  }
  cout << "a/add/ADD or f/file/FILE" << endl;
  cin.getline(input, 50, '\n');
  if (strcmp(input, "ADD") == 0 || strcmp(input, "a") == 0 || strcmp(input, "add") == 0) {
    cout << "Input Numbers, enter \'done\' when you are done" << endl;
    int i = 0;
    while (strcmp(input, "done")) {
      cin.getline(input, 50, '\n');
      if (strcmp(input, "done") == 0) {
	break;
      }
      numbers[i] = atoi(input);
      i++;
    }
    size = i;
  } else if (strcmp(input, "FILE") == 0 || strcmp(input, "f") == 0 || strcmp(input, "file") == 0) {
    ifstream Numbers;
    Numbers.open("numbers.txt");
    for(int i = 0; i < 100; i++){
      if (!Numbers.eof()) {
      Numbers >> numbers[i];
      size++;
      }
    }
    size--;
  }
  cout << "size: "<< size << endl;
  
  for (int i = 0; i < size; i++) {
    //cout << "index:" << i << endl;
    //cout << numbers[i] << endl;
  }
  
  int * heap = new int[size];
  
  for (int i = 0; i < size; i++) {
    heap[i+1] = numbers[i];
    insert(heap, i + 1);
  }
  
  printAsArray(heap, size);
  printAsTree(heap, 1, 0, size);
  bubbleSort(heap, size);
  //printAsArray(heap, size);
}

void insert(int * heap, int currentIndex) {
  if (heap[currentIndex] != ROOT && heap[currentIndex] != 0) {
    if (heap[currentIndex] > heap[((int)floor(currentIndex/2))] && ((int)floor(currentIndex/2)) > 0) { //if this is bigger than it's parent, switch places, also make sure it is above 0
      int childVal = heap[currentIndex]; //this is our current value that we are trying to add in.
      int parVal = heap[((int)floor(currentIndex/2))];
      heap[((int)floor(currentIndex/2))] = heap[currentIndex]; //swap places parent-child
      heap[currentIndex] = parVal;
      insert(heap, ((int)floor(currentIndex/2)));
      return;
    } else {
      return;
    }
  } else {
    return;
  }
}

void remove(int * heap, int currentIndex, int &size) {
  /*if (currentIndex <= size) { //make sure we aren't running off of the end.
    cout << heap[currentIndex]; //remove (print out) the root
    heap[currentIndex] = heap[size]; //set the root to the last one
    size--;
  }
  //if violates heap property
  if (heap[currentIndex] < heap[currentIndex * 2 + 1]) { //right child is bigger, swap places 
    
  } else if (heap[currentIndex] < heap[currentIndex * 2]) { //left child is bigger, swap

  }*/
}

void bubbleSort(int * heap, int &size) {
  int currentIndex = 1;
  bool swap = true;
  while (true) {
    swap = false;
    for (int i = 1; i <= size; i++) {
      if (heap[i] < heap[i+1]) {
	int temp = heap[i];
	heap[i] = heap[i+1];
	heap[i+1] = temp;
	swap = true;
      }
    }
    if (swap == false) {
      break;
    }
  }
  for (int i = 1; i <= size; i++) {
    cout << heap[i] << ", ";
    heap[i] = -1;
  }
  size = 0;
}

void printAsArray(int * heap, int size) {
  int i = 1;
  cout << "[";
  while (i <= size) {
    cout << heap[i] <<  ", ";
    i++;
  }
  cout << "]" << endl;
}

void printAsTree(int * heap, int index, int depth, int size) { //shamelessly stolen from Mr. Galbraith's whiteboard
  if (index * 2 + 1 <= size && heap[index * 2 + 1] != 0) { //right
    printAsTree(heap, index * 2 + 1, depth + 1, size); //recursivly call the function on the right side (until it reaches the end in which the index > size and increase the depth each time we go down a level)
  }
  for (int a = 0; a < depth; a++) { //increases the number of tabs
    cout << "\t";
  }
  cout << heap[index] << endl;
  if (index * 2 <= size && heap[index * 2] != 0) { //left
    printAsTree(heap, index * 2, depth + 1, size);
  }
}
