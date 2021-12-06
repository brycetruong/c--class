/*
Author: Bryce Truong
Date Created: 11/5/21
Last Modified: 12/6/21

This is a classes project that does stuff. You can add, search, and delete THREE different media types: Videogames, Music, and Movies.


Sources:
https://www.quantstart.com/articles/C-Virtual-Destructors-How-to-Avoid-Memory-Leaks/
https://www.geeksforgeeks.org/destructors-c/
https://www.learncpp.com/cpp-tutorial/header-guards/
https://www.geeksforgeeks.org/stack-vs-heap-memory-allocation/
https://www.cplusplus.com/reference/vector/vector/erase/
https://www.tutorialspoint.com/how-do-i-find-the-length-of-an-array-in-c-cplusplus
https://www.cplusplus.com/reference/vector/vector/crbegin/
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
  
  media* mediaList[20]; //useless I never used this array except in my testing phase
  
  vector<media*> myVec;
  
  while (stillRunning == true) {
    cout << "Welcome to the menu. Please select one of the following:\nADD\tDELETE\tSEARCH\tQUIT" << endl;
    cin.getline(input, 20, '\n');
    if (strcmp(input, "ADD") == 0) {
      
      /* READ ME FOR ADDING - COMMENTS
      How I added things to my media vector was I initialized the internal variables using the constructor.
      I made temporary vars which I stored the user input, and then at the end, I called the constructor for the videogames/music/movie and pushed everything into it.
      I don't have to put in the type of media it is, because that is already made automatically when the constructor is called.
      
      */
      
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
      int indexOfVec[20]; //probably should've called this indexInVec to be clearer
      media* mediaToDelete[20];
      
      /* READ ME FOR DELETING - COMMENTS PART 1/2
      So the delete searching part is the exact same as the searching part (see comments below in searching section)
      The only thing that is different, is when it finds a matching title/year, it adds the ptr to an array, and adds the index that it was at to another array.
      This is because if there are multiple matches, the user can choose which one to delete.
      
      */
      
      if (strcmp(input, "TITLE") == 0){
        cout << "Enter Title:" << endl;
        cin.getline(input, 20, '\n');
        
        for (int i = 0; i < myVec.size(); i++) {
          if (strcmp(myVec.at(i) -> getTitle(), input) == 0) {
            //The three lines below differ from the regular search loop.
            mediaToDelete[matches] = myVec.at(i);
            indexOfVec[matches] = i;
            matches++;
            
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
            mediaToDelete[matches] = myVec.at(i);
            indexOfVec[matches] = i;
            matches++;
            
            
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
      
      /* READ ME FOR DELETING - COMMENTS PART 2/2
      After the loop compiles all the matches, I check if there are multiple matches, and if there aren't more than 1 match, then I just delete the first one in the array.
      I delete the actual object first, and then I remove it from the vector. Removing it from the vector was a little bit tricky because vector::erase() uses an iterator instead of just a normal index.
      I print out all of the matches, and then prompt the user to delete which one (using the index).
      
      */
      
      if (matches > 1) {
        cout << matches << " matches found! Input indicie to delete:" << endl;
        
        for (int i = 0; i < matches; i++) {
          cout << i << endl;
        }
        cout << "-\t-\t-\t-\t-\t-" << endl;
        cout << endl;

        cin.getline(input, 20, '\n');

        delete mediaToDelete[atoi(input)];
        myVec.erase(myVec.begin() + indexOfVec[atoi(input)]);
        
      } else {
        if (matches != 0) {
          cout << "Succesfully deleted" << endl;
        delete mediaToDelete[0];
        myVec.erase(myVec.begin() + indexOfVec[0]);
        } else {
          cout << "No matches found" << endl;
        }
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
        
        /* READ ME FOR SEARCHING AND PRINTING - COMMENTS
        
        So basically how my search and printing works is, I loop thru the entire vector, and first find the matching title/year
        Inside each distinct media, I have a type (VG, MS, or MV) which tells me what kind of media it is so I don't accidentally call getDuration() on a videogame media.
        Then when I print out, you will notice that I to a videogame (or music or movie) ptr because it still thinks that it is a media ptr and tries to find getRate() when there is no getRate()
        I do this for all of the functions other than getYear() or getTitle() because those are part of the media class. (actually I realized that I also casted those to ptrs too but they would work exactly the same without...)
        The arrow (->) dereferences the ptrs and treats them as normal objects which I then can use the getSomething() functions on them.
        
        */
        
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
    } else {
      cout << "Input not recognized..." << endl;
    }
  }

}
