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

room::room(){ //default constructor (i never use it)
  
  desc = new char[500];
  
  roomname = new char[80];

}

room::~room(){
  delete[] desc;
  //delete exits; //do i need to delete this?
}

room::room(char* newDesc, char* newName) {
  desc = new char[500];
  strcpy(desc, newDesc);
  
  roomname = new char[80];
  strcpy(roomname, newName);
}

char* room::getDesc() { // gets the description and returns as a char star
  return desc;
}

char* room::getName() { //same as above
 return roomname; 
}

void room::printInfo() { // prints all the info about the room.
 cout << "\t-\t-\t-\t-\t-\t-\t-\t-\t-" << endl;
 cout << "You are in the " << roomname << endl;
 cout << "\t-\t-\t-" << endl;
 cout << desc << endl;
 cout << "\t-\t-\t-" << endl;
  cout << "Available exits:" << endl;
 for (itr = exits.begin(); itr != exits.end(); ++itr) { // uses an iterator to print all of the avail exits by finding the room ptr, dereferencing it, and calling getName() on it
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
 //also prints the items by looping thru the vector and calling getName() from the item class.
 cout << "Items in room:" << endl;
 for (int i = 0; i < roomInv.size(); i++) {
   cout << roomInv.at(i)->getName() << endl;
 }
 cout << "\t-\t-\t-\t-\t-\t-\t-\t-\t-" << endl;
}

void room::setExit(int direction, room* newExit) { //uses a map to pair a direction and a room ptr. I actually use int constants for my direction
  exits.insert(pair<int, room*>(direction, newExit));
}

room* room::getExit(int direction) { // returns the room ptr for the exit in a specific direction
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

item* room::remItem(char* itemName, bool rem) { //removes the item from a room. The bool rem is because I also used this method to even check if the item actually exists (!= NULL), so I want to make sure that the item isn't removed twice
  for (int i = 0; i < roomInv.size(); i++) {
   if (strcmp(roomInv.at(i)->getName(), itemName) == 0) {
     item* temp = roomInv.at(i);
     if (rem == true) { //I spent about an HOUR getting a segmentation fault bc this was  "if (rem = true)"
     roomInv.erase(roomInv.begin() + i);
     }
     return temp;
   }
 }
 return NULL; //makes sure to return null so i know that the item isn' there, or they mispelled it.
}

void room::printItems() { //loops thru the vector of item ptrs and prints everything
 cout << "Items in room:" << endl;
 for (int i = 0; i < roomInv.size(); i++) {
   cout << roomInv.at(i)->getName() << endl;
 }
}
