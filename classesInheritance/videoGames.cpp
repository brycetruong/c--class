
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
  publisher = new char[20];
  rating = 7.7
}

videoGames::videoGames(char* newTitle, int newYear, char* newPub, double newRate){
  title = new char[20];
  strcpy(title, newTitle);
  
  year = newYear;
  
  publisher = new char[20];
  strcpy(publisher, newPub);
  
  rating = newRate;
  
}


char* videoGames::getPub(){
  return publisher;
}

double videoGames::getRate(){
  return rating;
}

