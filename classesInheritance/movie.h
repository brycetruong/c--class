#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <cstring>
#include <stdio.h>
#include "media.h"


class movie: public media {
 public:
  movie();
  virtual ~movie();
  movie(char*, int, char*, double, int);//title, year, director, rating, duration
 
  char* getDir();
  double getRate();
  int getDuration();
  
 private:
  
  char* director;
  double rating;
  int duration;
 
};

#endif
