#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <array>
#include <stdio.h>
#include <vector>
#include <iterator>
#include "media.h"

using namespace std;

class videoGames: public media{
 public:
  videoGames(char[]);
  char*[] getTitle();
  int* getYear();
  char*[] getPub();
  double* getRate();
 private:
  char title[20];
  int year;
  char publisher[20];
  double rating;
};
 
