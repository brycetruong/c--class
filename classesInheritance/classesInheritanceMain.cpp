/*
Author: Bryce Truong
Date Created: 11/5/21
Last Modified: 11/15/21
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
//#include "videoGames.h"
#include "media.h"

using namespace std;


int main() {
  char input[20];
  bool stillRunning = true;
  
  media* mediaList[20];
  
  vector<media*> myVec;
  char* testTitle = new char[20];
  strcpy(testTitle, "myFirst");
  media[0] = new media(testTitle);
  myVec.push_back(mediaList[0]);
  cout << mediaList[0]->firstMedia.getTitle() << endl;
  
  
  while (stillRunning == true) {
    cin.getline(input, 20, '\n');
    if (strcmp(input, "ADD") == 0) {
      cout << "What kind of media would you like to add? \nVIDEOGAMES\tMUSIC\tMOVIES" << endl;
      cin.getline(input, 20, '\n');
      if (strcmp(input, "VIDEOGAMES") == 0) {
        
      } else if (strcmp(input, "MUSIC") == 0) {
        
      } else if (strcmp(input, "MOVIES") == 0) {
        
      } else {
        cout << "Returning to menu..." << endl;
      }
    } else if (strcmp(input, "DELETE") == 0) {

    } else if (strcmp(input, "QUIT") == 0) {
      cout << "Exiting..." << endl;
      stillRunning = false;
    } else if (strcmp(input, "SEARCH") == 0) {
      /*
      for (int i = 0; i < myVec.size(); i++) {
        cout << myVec.at(i) -> getTitle() << endl;
      }
      */
    } else {
      cout << "Input not recognized..." << endl;
    }
  }

}
