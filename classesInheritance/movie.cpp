
#include <iostream>
#include <cstring>
#include <stdio.h>
#include "media.h"
#include "movie.h"

using namespace std;

const int MEDIA = 0;
const int VG = 1; //videogame
const int MS = 2; //music
const int MV = 3; //movie

movie::movie(){
  //strcpy(title, newTitle);
  title = new char[20];
  year = 2000;
  
  director = new char[20];

  rating = 7.7;
  
  duration = 2000; //in minutes
}

movie::~movie(){
  delete[] director;
}

movie::movie(char* newTitle, int newYear, char* newDir, double newRate, int newDur){
  title = new char[20];
  strcpy(title, newTitle);
  
  year = newYear;
  
  director = new char[20];
  strcpy(director, newDir);
  
  rating = newRate;
  
  duration = newDur;
  
  type = MV;
}


char* movie::getDir(){
  return director;
}

double movie::getRate(){
  return rating;
}

int movie::getDuration(){
  return duration;
}
