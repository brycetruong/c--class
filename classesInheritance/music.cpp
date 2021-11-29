
#include <iostream>
#include <cstring>
#include <stdio.h>
#include "media.h"
#include "music.h"

using namespace std;

const int MEDIA = 0;
const int VG = 1; //videogame
const int MS = 2; //music
const int MV = 3; //movie

music::music(){
  //strcpy(title, newTitle);
  title = new char[20];
  year = 2000;
  publisher = new char[20];
  artist = new char[20];
}

music::music(char* newTitle, int newYear, char* newPub){
  title = new char[20];
  strcpy(title, newTitle);
  
  year = newYear;
  
  publisher = new char[20];
  strcpy(publisher, newPub);
  
  type = MS;
}


char* music::getPub(){
  return publisher;
}

char* music::getArt(){
  return artist;
}

int music::getDuration(){
  return duration;
}
