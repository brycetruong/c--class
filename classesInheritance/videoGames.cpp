
#include <iostream>
#include <cstring>
#include <stdio.h>
#include "media.h"
#include "videoGames.h"

using namespace std;


videoGames::videoGames(){
  //strcpy(title, newTitle);
  title = new char[20];
  year = 2000;
}

videoGames::videoGames(char* newTitle){
  title = new char[20];
  strcpy(title, newTitle);
  year = 2000;
  
}


char* videoGames::getPub(){
  return publisher;
}

videoGames::double getRate(){
  return rating;
}

