/*
Author: Bryce Truong
Date Created: 3/28/22
Last Modified: 3/28/22

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

void insert(int * heap, int currentIndex);

void printAsArray(int * heap);

int main() {

  char input[50];
  
  int numbers[50]; //sets up my array with a file full of numbers
  for(int i = 0; i < 50; i++){
    numbers[i] = -1;
  }
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
  } else if (strcmp(input, "FILE") == 0 || strcmp(input, "f") == 0 || strcmp(input, "file") == 0) {
    ifstream Numbers;
    Numbers.open("numbers.txt");
    for(int i = 0; i < 50; i++){
      Numbers >> numbers[i];
    }
  }
  
  int size = 0;
  while (numbers[size] != -1) {
    cout << numbers[size] << endl;
    size++;
  }
  
  int * heap = new int[51];

  heap[1] = 1;
  insert(heap, 1); 
  /*
  heap[2] = 10;
  insert(heap, 2);

  insert(heap, 3);

  insert(heap, 1);

  insert(heap, 1);

  insert(heap, 1);
  */
  
}

void insert(int * heap, int currentIndex) {
  if (heap[currentIndex] != ROOT) {
    if (heap[currentIndex] > ((int)floor(currentIndex/2))) { //if this is bigger than it's parent, switch places
      int childVal = heap[currentIndex]; //this is our current value that we are trying to add in.
      int parVal = heap[((int)floor(currentIndex/2))];
      heap[((int)floor(currentIndex/2))] = heap[currentIndex];
      heap[currentIndex] = parVal;
      insert(heap, ((int)floor(currentIndex/2)));
      return;
    }
  } else {
    return;
  }
}

void printAsArray(int * heap) {
  int i = 0;
  cout << "[";
  while (heap[i] != -1) {
    cout << heap[i] <<  ", ";
    i++;
  }
  cout << "]" << endl;
}
