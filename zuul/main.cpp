/*
Author: Bryce Truong
Date Created: 12/9/21
Last Modified: 1/5/22

This is a zuul game project.

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

int main() {
  char input[20];
  bool running = true;
  room* roomList[20];
  vector<item*> inventory;
  room* currentRoom;
  
  char* roomDesc = new char[500];
  char* roomName = new char[80];
  char* itemName = new char[80];

  
  /* CREATE ROOMS */
  
  strcpy(roomDesc, "You are standing outside in the forest, a cave lies before you.\nLegend says, there is a secret (not so secret anymore) pirate treasure trove deep within the cave.");
  strcpy(roomName, "entrance");
  room* entrance = new room(roomDesc, roomName);
  
  strcpy(roomDesc, "You are in an ordinary cave junction. You can hear water dripping to the east...");
  strcpy(roomName, "a boring cave");
  room* boringcave1 = new room(roomDesc, roomName);
  strcpy(itemName, "plain rock");
  boringcave1->addItem(new item(itemName));
  
  strcpy(roomDesc, "A long passage extends westward. The cave is very narrow.");
  strcpy(roomName, "narrow cave");
  room* narrowcave = new room(roomDesc, roomName);
  
  strcpy(roomDesc, "This is a very very cramped place. It doesn't look like it goes any further.");
  strcpy(roomName, "claustrophobically narrow cave");
  room* narrowercave = new room(roomDesc, roomName);
  strcpy(itemName, "pirate flag");
  narrowercave->addItem(new item(itemName));
  
  strcpy(roomDesc, "A huge cavern with a mini lake in the middle. (go north to go spelunking)");
  strcpy(roomName, "cavern");
  room* cavern = new room(roomDesc, roomName);
  strcpy(itemName, "WATER!");
  cavern->addItem(new item(itemName));
  
  strcpy(roomDesc, "You are in another ordinary cave.");
  strcpy(roomName, "another boring cave");
  room* boringcave2 = new room(roomDesc, roomName);
  
  strcpy(roomDesc, "Splash! You are underwater in the mini lake from the cavern. Nothing much here except fish and some shiny stuff in the mud.");
  strcpy(roomName, "underwater");
  room* underwater = new room(roomDesc, roomName);
  strcpy(itemName, "gold coin");
  underwater->addItem(new item(itemName));
    
  currentRoom = entrance;
  
  /* SET EXITS */
  
  entrance->setExit(NORTH, boringcave1);
  
  boringcave1->setExit(EAST, cavern);
  boringcave1->setExit(SOUTH, entrance);
  boringcave1->setExit(WEST, narrowcave);
  
  cavern->setExit(NORTH, underwater);
  cavern->setExit(EAST, boringcave2);
  cavern->setExit(WEST, boringcave1);
  
  boringcave2->setExit(WEST, cavern);
  
  underwater->setExit(SOUTH, cavern);
  
  narrowcave->setExit(EAST, boringcave1);
  narrowcave->setExit(WEST, narrowercave);
  
  narrowercave->setExit(EAST, narrowcave);
  
  
  /* ADD ITEMS TO INV*/
   
  strcpy(itemName, "Flashlight");
  inventory.push_back(new item(itemName));
  
  currentRoom->printInfo();
  
  while (running) {

    if (inventory.size() == 6 && strcmp(currentRoom->getName(), "entrance")) {
      cout << "you win!" << endl;
      running = false;
    }
    
    
    /* COMMANDS */
    /* Availible commands:
       north/east/south/waffles
       get
          "item_name"
       drop
          "item_name"
       w/a/s/d (same as moving)
       inv/inventory
       quit
    */
    cin.getline(input, 20, '\n');
    
    if (strcmp(input, "w") == 0 || strcmp(input, "north") == 0) {
      if (currentRoom->getExit(NORTH) != NULL) {
        currentRoom = currentRoom->getExit(NORTH);
        currentRoom->printInfo();
      } else {
       cout << "Sorry, there isn't an exit in that direction" << endl; 
      }
    } else if (strcmp(input, "a") == 0 || strcmp(input, "east") == 0) {
      if (currentRoom->getExit(EAST) != NULL) {
        currentRoom = currentRoom->getExit(EAST);
        currentRoom->printInfo();
      } else {
       cout << "Sorry, there isn't an exit in that direction" << endl; 
      }
    } else if (strcmp(input, "s") == 0 || strcmp(input, "south") == 0) {
      if (currentRoom->getExit(SOUTH) != NULL) {
        currentRoom = currentRoom->getExit(SOUTH);
        currentRoom->printInfo();
      } else {
       cout << "Sorry, there isn't an exit in that direction" << endl; 
      }
    } else if (strcmp(input, "d") == 0 || strcmp(input, "west") == 0) {
      if (currentRoom->getExit(WEST) != NULL) {
        currentRoom = currentRoom->getExit(WEST);
        currentRoom->printInfo();
      } else {
       cout << "Sorry, there isn't an exit in that direction" << endl; 
      }
    } else if (strcmp(input, "quit") == 0) {
      cout << "Byee!" << endl;
      running = false;
    } else if (strcmp(input, "drop") == 0) {
      
      cout << "Enter Item Name: " << endl;
      cin.getline(input, 20, '\n');
      
      for (int i = 0; i < inventory.size(); i++) {
        if (strcmp(input, inventory.at(i)->getName()) == 0) {
          currentRoom->addItem(inventory.at(i));
          inventory.erase(inventory.begin() + i);
          cout << "item dropped\n" << endl;
          break;
        }
      }
      
      currentRoom->printItems();
      cout << "Items in Inventory:" << endl;
      for (int i = 0; i < inventory.size(); i++) {
        cout << inventory.at(i)->getName() << endl;
      }
      
    } else if (strcmp(input, "get") == 0) {
      
      cout << "Enter Item Name: " << endl;
      cin.getline(input, 20, '\n');
      if (currentRoom->remItem(input, false) != NULL) {
        inventory.push_back(currentRoom->remItem(input, true));
        cout << "item picked up\n" << endl;
        currentRoom->printItems();
        cout << "Items in Inventory:" << endl;
        for (int i = 0; i < inventory.size(); i++) {
          cout << inventory.at(i)->getName() << endl;
        }
      } else {
       cout << "No item found!" << endl;
      }
      
    } else if (strcmp(input, "inv") == 0 || strcmp(input, "inventory") == 0) {
      
      cout << "Items in Inventory:" << endl;
      for (int i = 0; i < inventory.size(); i++) {
        cout << inventory.at(i)->getName() << endl;
      }
      
    } else {
     cout << "command not recognized..." << endl;
    }
    
  }
  
  cout << "Thanks for playing, have a nice day!" << endl; 
  
  
}
