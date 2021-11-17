#ifndef VIEDOGAMES_H
#define VIEDOGAMES_H

#include <iostream>
#include <cstring>
#include <stdio.h>
#include "media.h"


class videoGames: public media{
 public:
  videoGames();
  videoGames(char*);
 
  char* getPub();
  double getRate();
 private:
  
  char* publisher[20];
  double rating;
 
};

#endif
