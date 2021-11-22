
#include <iostream>
#include <cstring>
#include <stdio.h>
#include "media.h"
#include "music.h"

using namespace std;


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
