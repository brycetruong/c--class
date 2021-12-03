/*
Author: Bryce Truong
Date Created: 11/5/21
Last Modified: 12/1/21
*/
#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <array>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iterator>
#include "videoGames.h"
#include "music.h"
#include "movie.h"
#include "media.h"

using namespace std;

const int MEDIA = 0;
const int VG = 1; //videogame
const int MS = 2; //music
const int MV = 3; //movie

int main() {
  char input[20];
  bool stillRunning = true;
  
  media* mediaList[20]; //useless I never used an array except in my testing phase
  
  vector<media*> myVec;
  
  while (stillRunning == true) {
    cout << "Welcome to the menu. Please select one of the following:\nADD\tDELETE\tSEARCH\tQUIT" << endl;
    cin.getline(input, 20, '\n');
    if (strcmp(input, "ADD") == 0) {
      cout << "What kind of media would you like to add? \nVIDEOGAMES (VG)\tMUSIC (MS)\tMOVIES (MV)" << endl;
      cin.getline(input, 20, '\n');
      if (strcmp(input, "VIDEOGAMES") == 0 || strcmp(input, "VG") == 0) {
        //VIDEOGAMES 
        char* tempTitle = new char[20];
        int tempYear = 0;
        char* tempPub = new char[20];
        double tempRate = 0.0;
        
        cout << "Input title:" << endl;
        cin.getline(input, 20, '\n');
        strcpy(tempTitle, input);
        
        cout << "Input year:" << endl;
        cin.getline(input, 20, '\n');
        tempYear = atoi(input);
        
        cout << "Input publisher:" << endl;
        cin.getline(input, 20, '\n');
        strcpy(tempPub, input);
        
        cout << "Input rating:" << endl;
        cin.getline(input, 20, '\n');
        tempRate = atof(input);
          
        myVec.push_back(new videoGames(tempTitle, tempYear, tempPub, tempRate));
        
        /*double intuit = 0.0; // just me testing how cin works
        cin >> intuit;
        cout << intuit << endl;
        cin.ignore(80,'\n');
        */
        
      } else if (strcmp(input, "MUSIC") == 0 || strcmp(input, "MS") == 0) {
        //cout << "MUSIC" << endl;
        
        char* tempTitle = new char[20];
        int tempYear = 0;
        char* tempPub = new char[20];
        char* tempArt = new char[20];
        int tempDur = 0;
        
        cout << "Input title:" << endl;
        cin.getline(input, 20, '\n');
        strcpy(tempTitle, input);
        
        cout << "Input year:" << endl;
        cin.getline(input, 20, '\n');
        tempYear = atoi(input);
        
        cout << "Input publisher:" << endl;
        cin.getline(input, 20, '\n');
        strcpy(tempPub, input);
        
        cout << "Input artist:" << endl;
        cin.getline(input, 20, '\n');
        strcpy(tempArt, input);
        
        cout << "Input duration (in seconds):" << endl;
        cin.getline(input, 20, '\n');
        tempDur = atoi(input);
          
        myVec.push_back(new music(tempTitle, tempYear, tempPub, tempArt, tempDur));
        
      } else if (strcmp(input, "MOVIES") == 0 || strcmp(input, "MV") == 0) {
        //cout << "MOVIES" << endl;
        
        char* tempTitle = new char[20];
        int tempYear = 0;
        char* tempDir = new char[20];
        double tempRate = 0.0;
        int tempDur = 0;
        
        cout << "Input title:" << endl;
        cin.getline(input, 20, '\n');
        strcpy(tempTitle, input);
        
        cout << "Input year:" << endl;
        cin.getline(input, 20, '\n');
        tempYear = atoi(input);
        
        cout << "Input director:" << endl;
        cin.getline(input, 20, '\n');
        strcpy(tempDir, input);
        
        cout << "Input rating:" << endl;
        cin.getline(input, 20, '\n');
        tempRate = atof(input);
        
        cout << "Input duration (in minutes):" << endl;
        cin.getline(input, 20, '\n');
        tempDur = atoi(input);
          
        myVec.push_back(new movie(tempTitle, tempYear, tempDir, tempRate, tempDur));
        
      } else {
        cout << "Returning to menu..." << endl;
      }
    } else if (strcmp(input, "DELETE") == 0) {
      
      cout << "What do you want to search by to delete?\nTITLE\tYEAR" << endl;
      cin.getline(input, 20, '\n');
      
      int matches = 0;
      int indexOfVec[20];
      /*int vg = 0;
      int ms = 0;
      int mv = 0;*/
      media* mediaToDelete[20];
      
      if (strcmp(input, "TITLE") == 0){
        cout << "Enter Title:" << endl;
        cin.getline(input, 20, '\n');
        
        for (int i = 0; i < myVec.size(); i++) {
          if (strcmp(myVec.at(i) -> getTitle(), input) == 0) {
            mediaToDelete[matches] = myVec.at(i);
            matches++;
            indexOfVec[matches] = i;
            if (myVec.at(i) -> getType() == VG) {
              cout << "-\t-\t-\t-\t" << endl;
              cout << "Media Type: VideoGame" << endl;
              cout << "Title: " << ((videoGames*)myVec.at(i)) -> getTitle() << endl;
              cout << "Year: " << ((videoGames*)myVec.at(i)) -> getYear() << endl;
              cout << "Publisher: " << ((videoGames*)myVec.at(i)) -> getPub() << endl;
              cout << "Rating: " << ((videoGames*)myVec.at(i)) -> getRate() << endl;
              cout << "-\t-\t-\t-\t" << endl;
              cout << endl;
            } else if (myVec.at(i) -> getType() == MS) {
              cout << "-\t-\t-\t-\t" << endl;
              cout << "Media Type: Music" << endl;
              cout << "Title: " << ((music*)myVec.at(i)) -> getTitle() << endl;
              cout << "Year: " << ((music*)myVec.at(i)) -> getYear() << endl;
              cout << "Publisher: " << ((music*)myVec.at(i)) -> getPub() << endl;
              cout << "Artist: " << ((music*)myVec.at(i)) -> getArt() << endl;
              cout << "Duration: " << ((music*)myVec.at(i)) -> getDuration() << endl;
              cout << "-\t-\t-\t-\t" << endl;
              cout << endl;
            } else if (myVec.at(i) -> getType() == MV) {
              cout << "-\t-\t-\t-\t" << endl;
              cout << "Media Type: Movie" << endl;
              cout << "Title: " << ((movie*)myVec.at(i)) -> getTitle() << endl;
              cout << "Year: " << ((movie*)myVec.at(i)) -> getYear() << endl;
              cout << "Director: " << ((movie*)myVec.at(i)) -> getDir() << endl;
              cout << "Rating: " << ((movie*)myVec.at(i)) -> getRate() << endl;
              cout << "Duration: " << ((movie*)myVec.at(i)) -> getDuration() << endl;
              cout << "-\t-\t-\t-\t" << endl;
              cout << endl;
            }
            
          }
          
        }
      } else if (strcmp(input, "YEAR") == 0) {
        cout << "Enter Year:" << endl;
        cin.getline(input, 20, '\n');
        
        for (int i = 0; i < myVec.size(); i++) {
          if (myVec.at(i) -> getYear() == atoi(input)) {
            matches++;
            mediaToDelete[matches] = myVec.at(i);
            indexOfVec[matches] = i;
            if (myVec.at(i) -> getType() == VG) {
              cout << "-\t-\t-\t-\t" << endl;
              cout << "Media Type: VideoGame" << endl;
              cout << "Title: " << ((videoGames*)myVec.at(i)) -> getTitle() << endl;
              cout << "Year: " << ((videoGames*)myVec.at(i)) -> getYear() << endl;
              cout << "Publisher: " << ((videoGames*)myVec.at(i)) -> getPub() << endl;
              cout << "Rating: " << ((videoGames*)myVec.at(i)) -> getRate() << endl;
              cout << "-\t-\t-\t-\t" << endl;
              cout << endl;
            } else if (myVec.at(i) -> getType() == MS) {
              cout << "-\t-\t-\t-\t" << endl;
              cout << "Media Type: Music" << endl;
              cout << "Title: " << ((music*)myVec.at(i)) -> getTitle() << endl;
              cout << "Year: " << ((music*)myVec.at(i)) -> getYear() << endl;
              cout << "Publisher: " << ((music*)myVec.at(i)) -> getPub() << endl;
              cout << "Artist: " << ((music*)myVec.at(i)) -> getArt() << endl;
              cout << "Duration: " << ((music*)myVec.at(i)) -> getDuration() << endl;
              cout << "-\t-\t-\t-\t" << endl;
              cout << endl;
            } else if (myVec.at(i) -> getType() == MV) {
              cout << "-\t-\t-\t-\t" << endl;
              cout << "Media Type: Movie" << endl;
              cout << "Title: " << ((movie*)myVec.at(i)) -> getTitle() << endl;
              cout << "Year: " << ((movie*)myVec.at(i)) -> getYear() << endl;
              cout << "Director: " << ((movie*)myVec.at(i)) -> getDir() << endl;
              cout << "Rating: " << ((movie*)myVec.at(i)) -> getRate() << endl;
              cout << "Duration: " << ((movie*)myVec.at(i)) -> getDuration() << endl;
              cout << "-\t-\t-\t-\t" << endl;
              cout << endl;
            }
          }
        }
      } else {
        cout << "Input not recognized... please enter TITLE or YEAR" << endl;
      }
      
      if (matches > 1) {
        cout << matches << "matches found! Input indicie to delete:" << endl;
        cout << "/t" << endl;
        for (int i = 1; i < matches+1; i++) cout << "/t" << i << endl;
        cin.getline(input, 20, '\n');
        
        mediaToDelete[atoi(input)]
        myVec.erase(indexOfVec[atoi(input)]);
        
      } else {
       cout << "Succesfully deleted" << endl;
       delete mediaToDelete[0];
       myVec.erase(indexOfVec[0]);
      }
      
    } else if (strcmp(input, "QUIT") == 0) {
      cout << "Exiting..." << endl;
      stillRunning = false;
    } else if (strcmp(input, "SEARCH") == 0) {
      cout << "What do you want to search by?\nTITLE\tYEAR" << endl;
      cin.getline(input, 20, '\n');
      
      if (strcmp(input, "TITLE") == 0){
        cout << "Enter Title:" << endl;
        cin.getline(input, 20, '\n');
        
        for (int i = 0; i < myVec.size(); i++) {
          if (strcmp(myVec.at(i) -> getTitle(), input) == 0) {
            if (myVec.at(i) -> getType() == VG) {
              cout << "-\t-\t-\t-\t" << endl;
              cout << "Media Type: VideoGame" << endl;
              cout << "Title: " << ((videoGames*)myVec.at(i)) -> getTitle() << endl;
              cout << "Year: " << ((videoGames*)myVec.at(i)) -> getYear() << endl;
              cout << "Publisher: " << ((videoGames*)myVec.at(i)) -> getPub() << endl;
              cout << "Rating: " << ((videoGames*)myVec.at(i)) -> getRate() << endl;
              cout << "-\t-\t-\t-\t" << endl;
              cout << endl;
            } else if (myVec.at(i) -> getType() == MS) {
              cout << "-\t-\t-\t-\t" << endl;
              cout << "Media Type: Music" << endl;
              cout << "Title: " << ((music*)myVec.at(i)) -> getTitle() << endl;
              cout << "Year: " << ((music*)myVec.at(i)) -> getYear() << endl;
              cout << "Publisher: " << ((music*)myVec.at(i)) -> getPub() << endl;
              cout << "Artist: " << ((music*)myVec.at(i)) -> getArt() << endl;
              cout << "Duration: " << ((music*)myVec.at(i)) -> getDuration() << endl;
              cout << "-\t-\t-\t-\t" << endl;
              cout << endl;
            } else if (myVec.at(i) -> getType() == MV) {
              cout << "-\t-\t-\t-\t" << endl;
              cout << "Media Type: Movie" << endl;
              cout << "Title: " << ((movie*)myVec.at(i)) -> getTitle() << endl;
              cout << "Year: " << ((movie*)myVec.at(i)) -> getYear() << endl;
              cout << "Director: " << ((movie*)myVec.at(i)) -> getDir() << endl;
              cout << "Rating: " << ((movie*)myVec.at(i)) -> getRate() << endl;
              cout << "Duration: " << ((movie*)myVec.at(i)) -> getDuration() << endl;
              cout << "-\t-\t-\t-\t" << endl;
              cout << endl;
            }
            
          }
          
        }
      } else if (strcmp(input, "YEAR") == 0) {
        cout << "Enter Year:" << endl;
        cin.getline(input, 20, '\n');
        
        for (int i = 0; i < myVec.size(); i++) {
          if (myVec.at(i) -> getYear() == atoi(input)) {
            if (myVec.at(i) -> getType() == VG) {
              cout << "-\t-\t-\t-\t" << endl;
              cout << "Media Type: VideoGame" << endl;
              cout << "Title: " << ((videoGames*)myVec.at(i)) -> getTitle() << endl;
              cout << "Year: " << ((videoGames*)myVec.at(i)) -> getYear() << endl;
              cout << "Publisher: " << ((videoGames*)myVec.at(i)) -> getPub() << endl;
              cout << "Rating: " << ((videoGames*)myVec.at(i)) -> getRate() << endl;
              cout << "-\t-\t-\t-\t" << endl;
              cout << endl;
            } else if (myVec.at(i) -> getType() == MS) {
              cout << "-\t-\t-\t-\t" << endl;
              cout << "Media Type: Music" << endl;
              cout << "Title: " << ((music*)myVec.at(i)) -> getTitle() << endl;
              cout << "Year: " << ((music*)myVec.at(i)) -> getYear() << endl;
              cout << "Publisher: " << ((music*)myVec.at(i)) -> getPub() << endl;
              cout << "Artist: " << ((music*)myVec.at(i)) -> getArt() << endl;
              cout << "Duration: " << ((music*)myVec.at(i)) -> getDuration() << endl;
              cout << "-\t-\t-\t-\t" << endl;
              cout << endl;
            } else if (myVec.at(i) -> getType() == MV) {
              cout << "-\t-\t-\t-\t" << endl;
              cout << "Media Type: Movie" << endl;
              cout << "Title: " << ((movie*)myVec.at(i)) -> getTitle() << endl;
              cout << "Year: " << ((movie*)myVec.at(i)) -> getYear() << endl;
              cout << "Director: " << ((movie*)myVec.at(i)) -> getDir() << endl;
              cout << "Rating: " << ((movie*)myVec.at(i)) -> getRate() << endl;
              cout << "Duration: " << ((movie*)myVec.at(i)) -> getDuration() << endl;
              cout << "-\t-\t-\t-\t" << endl;
              cout << endl;
            }
          }
        }
      } else {
        cout << "Input not recognized... please enter TITLE or YEAR" << endl;
      }
      
      
      
      
      /*
      for (int i = 0; i < myVec.size(); i++) {
        cout << myVec.at(i) -> getTitle() << endl;
      }
      */
    } else {
      delete myVec.at(0);
      myVec.erase(0);
      /*
      char* testTitle = new char[20];
      strcpy(testTitle, "Pacman");
      int newInt = 2021;
      mediaList[0] = new media(testTitle, newInt); //videogames or media
      myVec.push_back(mediaList[0]);
      strcpy(testTitle, "Galaga");
      newInt = 2022;
      mediaList[1] = new videoGames(testTitle, newInt, testTitle, 7.8);
      myVec.push_back(mediaList[1]);
      strcpy(testTitle, "Galaga");
      newInt = 2023;
      mediaList[2] = new videoGames(testTitle, newInt, testTitle, 9.9);
      myVec.push_back(mediaList[2]);
      
      cout << endl;
      
      cout << myVec.at(0)->getTitle() << endl;
      cout << mediaList[0]->getYear() << endl;
      
      cout << myVec.at(1)->getYear() << endl; //note to self: also use virtual functions for when there are the same fctn (like getRate on both movies and VG)?
      cout << ((videoGames*)myVec.at(1))->getRate() << endl; //I cast to a videogame ptr because it still thinks that it is a media ptr and tries to find get rate when there is no get rate
      */
      cout << "Input not recognized..." << endl;
    }
  }

}
