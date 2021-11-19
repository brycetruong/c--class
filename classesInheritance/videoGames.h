#ifndef VIDEOGAMES_H
#define VIDEOGAMES_H

#include <iostream>
#include <cstring>
#include <stdio.h>
#include "media.h"


class videoGames: public media {
 public:
  videoGames();
  videoGames(char*, int, char*);
 
  char* getPub();
  double getRate();
 private:
  
  char* publisher;
  double rating;
 
};

#endif
