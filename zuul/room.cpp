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
  
  desc = new char[20];

}

room::~room(){
  delete[] desc;
  //delete exits; //do i need to delete this?
}

room::room(char* newDesc, char* newName) {
  desc = new char[80];
  strcpy(desc, newDesc);
  
  name = new char[80];
  strcpy(name, newName);
}

char* room::getDesc() {
  return desc;
}

void room::setExit(int direction, room* newExit) {
  exits.insert(pair<int, room*>(direction, newExit));
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
 for (int i = 0; i < roomInv.size(); i++) {
   cout << roomInv.at(i)->getName() << endl;
 }
}
