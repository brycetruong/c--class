/*
Author: Bryce Truong
Date Created: 12/9/21
Last Modified: 12/9/21

*/
#include <iostream>
#include <cstring>
#include <stdio.h>
#include <vector>
#include <iterator>
#include <map>
#include "room.h"


using namespace std;

room::room(){
  
  desc = new char[80];
  
  roomname = new char[80];

}

room::~room(){
  delete[] desc;
  //delete exits; //do i need to delete this?
}

room::room(char* newDesc, char* newName) {
  desc = new char[80];
  strcpy(desc, newDesc);
  
  roomname = new char[80];
  strcpy(roomname, newName);
}

char* room::getDesc() {
  return desc;
}

char* room::getName() {
 return roomname; 
}

void room::printInfo() {
 cout << "You are in the " << roomname << endl;
 cout << "\t-\t-\t-" << endl;
 cout << desc << endl;
 cout << "\t-\t-\t-" << endl;
  cout << "Available exits:" << endl;
 for (itr = exits.begin(); itr != exits.end(); ++itr) {
   if(itr->first == NORTH) {
     cout << "North: " << itr->second->getName() << endl;
   } else if (itr->first == EAST) {
     cout << "East: " << itr->second->getName() << endl;
   } else if (itr->first == SOUTH) {
     cout << "South: " << itr->second->getName() << endl;
   } else {
     cout << "West: " << itr->second->getName() << endl;
   }
 }
 //also prints the items
 cout << "Items in room:" << endl;
 for (int i = 0; i < roomInv.size(); i++) {
   cout << roomInv.at(i)->getName() << endl;
 }
}

void room::setExit(int direction, room* newExit) {
  exits.insert(pair<int, room*>(direction, newExit));
}

room* room::getExit(int direction) {
 for (itr = exits.begin(); itr != exits.end(); ++itr) {
   if(itr->first == direction) {
     return itr->second;
   }
 }
 return NULL;
}

void room::addItem(item* newItem) {
  roomInv.push_back(newItem);
}

item* room::remItem(char* itemName) {
  for (int i = 0; i < roomInv.size(); i++) {
   if (strcmp(roomInv.at(i)->getName(), itemName) == 0) {
     item* temp = roomInv.at(i);
     roomInv.erase(roomInv.begin() + i);
     return temp;
   }
 }
 return NULL;
}

void room::printItems() {
 cout << "Items in room:" << endl;
 for (int i = 0; i < roomInv.size(); i++) {
   cout << roomInv.at(i)->getName() << endl;
 }
}
