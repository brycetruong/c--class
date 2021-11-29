#ifndef VIDEOGAMES_H
#define VIDEOGAMES_H

#include <iostream>
#include <cstring>
#include <stdio.h>
#include "media.h"

const int MEDIA = 0;
const int VG = 1; //videogame
const int MS = 2; //music
const int MV = 3; //movie

class videoGames: public media {
 public:
  videoGames();
  videoGames(char*, int, char*, double);
 
  char* getPub();
  double getRate();
 private:
  
  char* publisher;
  double rating;
 
};

#endif
