/*
Author: Bryce Truong
Date Created: 12/9/21
Last Modified: 12/9/21

Sources:
https://www.quantstart.com/articles/C-Virtual-Destructors-How-to-Avoid-Memory-Leaks/
https://www.geeksforgeeks.org/destructors-c/
https://www.learncpp.com/cpp-tutorial/header-guards/
https://www.geeksforgeeks.org/stack-vs-heap-memory-allocation/
https://www.cplusplus.com/reference/vector/vector/erase/
https://www.tutorialspoint.com/how-do-i-find-the-length-of-an-array-in-c-cplusplus
https://www.cplusplus.com/reference/vector/vector/crbegin/
https://www.udacity.com/blog/2020/03/c-maps-explained.html
*/

#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <array>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iterator>
#include <map>
#include "room.h"
#include "item.h"

using namespace std;

void printCurrentRoom(room* currentRoom);

int main() {
  char input[20];
  bool running = true;
  room* roomList[20];
  vector<item*> inventory;
  room* currentRoom;

  while (running) {
    bool playing = true;
    /* CREATE ROOMS */
    room* testRoom1 = new Room("testRoom1 desc?", "testRoom1");
    room* testRoom2 = new Room("pls work...", "TR2");
    
    
    testRoom1->setExit(NORTH, testRoom2*);
    
    currentRoom = testRoom1;
    /* COMMAND PARSER */
    /* Availible commands:
       go north/east/south/waffles
       get "item_name"
       w,a,s,d (same as go)
       quit
    */
    cin.getline(input, 20, '\n');
    
    cin.getline(input, 20, '\n');


    
  }
  
  cout << "Thanks for playing, have a nice day!" << endl; 
  
  
}

void printCurrentRoom(room* currentRoom) {
  
  
  return;
}
