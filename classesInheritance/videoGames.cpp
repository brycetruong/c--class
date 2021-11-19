
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

videoGames::videoGames(char* newTitle, int newYear, char* newPub){
  title = new char[20];
  strcpy(title, newTitle);
  publisher = new char[20];
  strcpy(publisher, newPub);
  year = newYear;
  
}


char* videoGames::getPub(){
  return publisher;
}

double videoGames::getRate(){
  return rating;
}

