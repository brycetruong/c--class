
#include <iostream>
#include <cstring>
#include <stdio.h>
#include "media.h"
#include "videoGames.h"

using namespace std;

const int MEDIA = 0;
const int VG = 1; //videogame
const int MS = 2; //music
const int MV = 3; //movie

videoGames::videoGames(){ //default constructor if you don't put anything in
  //strcpy(title, newTitle);
  title = new char[20];
  year = 2000;
  publisher = new char[20];
  rating = 7.7;
}

videoGames::~videoGames(){ //destructor
  delete[] publisher;
}

videoGames::videoGames(char* newTitle, int newYear, char* newPub, double newRate){
  title = new char[20];
  strcpy(title, newTitle);
  
  year = newYear;
  
  publisher = new char[20];
  strcpy(publisher, newPub);
  
  rating = newRate;
  
  type = VG;
}


char* videoGames::getPub(){
  return publisher;
}

double videoGames::getRate(){
  return rating;
}

