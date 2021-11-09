/*
Author: Bryce Truong
Date Created: 11/5/21
Last Modified: 11/8/21
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
  char input[10];
  bool stillRunning = true;
  
  vector<media*> myVec;
  while (stillRunning == true) {
    cin.getline(input, 10, '\n');
    if (strcmp(input, "ADD") == 0) {

    } else if (strcmp(input, "DELETE") == 0) {

    } else if (strcmp(input, "QUIT") == 0) {
      cout << "Exiting..." << endl;
      stillRunning = false;
    } else if (strcmp(input, "S") == 0) {
      for (int i = 0; i < myVec.size(); i++) {
        cout << myVec.at(i) -> getTitle() << endl;
      }
    } else {
      cout << "Input not recognized..." << endl;
    }
  }

}
