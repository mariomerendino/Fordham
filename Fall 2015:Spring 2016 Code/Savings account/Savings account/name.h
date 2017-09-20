#ifndef NAME_H
#define NAME_H
#include <iostream>
#include <string.h>
using namespace std;

class Name{

public: 
     Name();//default constructor
     Name(string f, char m, string l);//other constructor
     void input();//input
     void display();//display
     void setfname(string f);//Mutators
     void setlname(string l);
     void setmi(char m);
     string getfname();//Accessors
     string getlname();
     char getmi();
private: 
     string fname, lname;
     char mi; 
};
#endif 
