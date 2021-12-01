#ifndef MUSIC_H
#define MUSIC_H

#include <iostream>
#include <cstring>
#include <stdio.h>
#include "media.h"


class music: public media {
 public:
  music();
  virtual ~music();
  music(char*, int, char*);
 
  char* getPub();
  char* getArt();
  int getDuration();
  
 private:
  
  char* publisher;
  char* artist;
  int duration;
 
};

#endif
