/*
Author: Bryce Truong
Date Created: 12/9/21
Last Modified: 1/5/22

This is a zuul game project.

LINK TO MAP: https://docs.google.com/drawings/d/1NzrsL1TfH7Zb5IX9UAK4qNpRSBTWV5TDfGNslR-FCiE/edit

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
  
  /*
  This is where i create my rooms. I pass in the room description and the room name.
  When I add an item, I use my method that i created in room that will add the new item to the vector of item ptrs inside the object.
  
  */
  
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
  
  strcpy(roomDesc, "A huge cavern with a mini lake in the middle. (go north to go spelunking) There is also a waterfall to the south.");
  strcpy(roomName, "cavern");
  room* cavern = new room(roomDesc, roomName);
  strcpy(itemName, "WATER!");
  cavern->addItem(new item(itemName));
  
  strcpy(roomDesc, "The roaring sound of water drowns out all other sounds. It looks like this is a deadend?");
  strcpy(roomName, "waterfall");
  room* waterfall = new room(roomDesc, roomName);
  
  strcpy(roomDesc, "A damp, dark and musty alcove. A stream trickles through the cave.");
  strcpy(roomName, "a secret cave behind the waterfall.");
  room* secretwaterfall = new room(roomDesc, roomName);
  
  strcpy(roomDesc, "Glittering jewels line the cave walls. They are embedded inside the rock so you cant take them out :(");
  strcpy(roomName, "diamond tunnel");
  room* diamondcave = new room(roomDesc, roomName);
  strcpy(itemName, "diamond necklace");
  diamondcave->addItem(new item(itemName));
  
  strcpy(roomDesc, "The room glows yellow as the light reflects off of the mountains of gold!");
  strcpy(roomName, "Treasure Stash");
  room* treasurestash = new room(roomDesc, roomName);
  strcpy(itemName, "gold chest");
  treasurestash->addItem(new item(itemName));
  
  
  strcpy(roomDesc, "A secret exit that will lead back to the entrance (one way)");
  strcpy(roomName, "Secret Exit 1");
  room* secretexit1 = new room(roomDesc, roomName);
  
  strcpy(roomDesc, "A secret exit that will lead back to the entrance (one way)");
  strcpy(roomName, "Secret Exit 2");
  room* secretexit2 = new room(roomDesc, roomName);
  
  strcpy(roomDesc, "A secret exit that will lead back to the entrance (one way)");
  strcpy(roomName, "Secret Exit 3");
  room* secretexit3 = new room(roomDesc, roomName);
  
  strcpy(roomDesc, "You are in another ordinary cave. It looks like a deadend");
  strcpy(roomName, "another boring cave");
  room* boringcave2 = new room(roomDesc, roomName);
  
  strcpy(roomDesc, "Splash! You are underwater in the mini lake from the cavern. Nothing much here except fish and some shiny stuff in the mud.");
  strcpy(roomName, "underwater");
  room* underwater = new room(roomDesc, roomName);
  strcpy(itemName, "gold coin");
  underwater->addItem(new item(itemName));
    
  currentRoom = entrance;
  
  /* SET EXITS */
  //I make all of my exits here using a method in my room.
  
  entrance->setExit(NORTH, boringcave1);
  
  boringcave1->setExit(EAST, cavern);
  boringcave1->setExit(SOUTH, entrance);
  boringcave1->setExit(WEST, narrowcave);
  
  cavern->setExit(NORTH, underwater);
  cavern->setExit(EAST, boringcave2);
  cavern->setExit(WEST, boringcave1);
  cavern->setExit(SOUTH, waterfall);
  
  waterfall->setExit(NORTH, cavern);
  waterfall->setExit(SOUTH, secretwaterfall);
  
  secretwaterfall->setExit(NORTH, waterfall);
  secretwaterfall->setExit(SOUTH, diamondcave);
  
  diamondcave->setExit(NORTH, secretwaterfall);
  diamondcave->setExit(SOUTH, treasurestash);
  
  treasurestash->setExit(NORTH, diamondcave);
  treasurestash->setExit(WEST, secretexit1);
  
  secretexit1->setExit(NORTH, secretexit2);
  
  secretexit2->setExit(NORTH, secretexit3);
  
  secretexit3->setExit(NORTH, entrance);
  
  boringcave2->setExit(WEST, cavern);
  
  underwater->setExit(SOUTH, cavern);
  
  narrowcave->setExit(EAST, boringcave1);
  narrowcave->setExit(WEST, narrowercave);
  
  narrowercave->setExit(EAST, narrowcave);
  
  
  /* ADD ITEMS TO INV*/
   
  strcpy(itemName, "Flashlight");
  inventory.push_back(new item(itemName));
  
  cout << "Find all of the items and return to the entrance to win. Good luck!\n" << endl;
  
  
    /* AVAILABLE COMMANDS:
       north/east/south/waffles
       get
          "item name"
       drop
          "item name"
       w/a/s/d (same as moving)
       inv/inventory
       quit
    */
  
  currentRoom->printInfo();
  
  while (running) {

    if (inventory.size() == 7 && strcmp(currentRoom->getName(), "entrance") == 0) {
      cout << "you win!" << endl;
      running = false;
    }
    
    
    
    cin.getline(input, 20, '\n');
    
    if (strcmp(input, "w") == 0 || strcmp(input, "north") == 0) {
      if (currentRoom->getExit(NORTH) != NULL) {
        currentRoom = currentRoom->getExit(NORTH);
        currentRoom->printInfo();
      } else {
       cout << "Sorry, there isn't an exit in that direction" << endl; 
      }
    } else if (strcmp(input, "d") == 0 || strcmp(input, "east") == 0) {
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
    } else if (strcmp(input, "a") == 0 || strcmp(input, "west") == 0) {
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
      if (currentRoom->remItem(input, false) != NULL) { // I used the remove item from room also as a check to make sure it isn't null. the 'false' makes sure that the method doesnt actually try and remove said item.
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
