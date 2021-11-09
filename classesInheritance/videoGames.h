
#include <iostream>
#include <cstring>
#include <stdio.h>
#include "media.h"


class videoGames: public media{
 public:
  videoGames(char);
  char getTitle();
  int getYear();
  char getPub();
  double getRate();
 private:
  char title[20];
  int year;
  char publisher[20];
  double rating;
 
};
 
