#include <iostream>
#include <cstring>
#include <stdio.h>
#include "videoGames.h"

using namespace std;

videoGames::videoGames(char newTitle){
  strcpy(title, newTitle);

}

char videoGames::getTitle(){
  return title;
}

int videoGames::getYear(){
  return year;
}

char videoGames::getPub(){
  return publisher;
}

double getRate(){
  return rating;
}
