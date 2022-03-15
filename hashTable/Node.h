#include <iostream>
using namespace std;
class Node {
public:
  Node();
  ~Node();
  Node(char *, char *);
  
  void setNext(Node *);
  Node * getNext();
  
  void setfname(char *);
  void setlname(char *);
  char * getfname();
  char * getlname();

  void setID(int);
  int getID();
  void setGPA(float);
  float getGPA();

private:
  char * fname;
  char * lname;
  Node * next;

  int ID;
  float GPA;
};
