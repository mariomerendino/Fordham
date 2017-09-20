//  Author: Mario Merendino
//  Professor Papadakis;
//  Lab4
//  Creates an Object named set, and compares the values in each obj.
//  Last Modified: 11/12/15.

#ifndef __Lab4__set__
#define __Lab4__set__

#include <stdio.h>
#include <iostream>
#include <cstdlib>
using namespace std;

class Set{
    friend ostream &operator<<( ostream &, const Set & );
    friend istream &operator>>( istream &, Set  &);
public:
    Set(int = DEFAULTSIZE);
    //Set(int[], int, char);
    Set(const Set &);
    Set(const Set &, int);
    ~Set();
    void input();
    void display();
    int newlsize(Set);
    int newpsize(Set);
    Set Union(Set);
    Set operator+(Set);
    Set operator+(int);
    Set operator^(Set);
    Set operator-(Set);
    Set operator-(int);
    bool element(int);
    bool operator==(Set);
    bool operator!=(Set);
    int getpsize();
    int getlsize();
    void setlsize(int);
    Set addinterger(int);
    Set Intersection(Set);
    Set removeinterger(int n);
    Set Difference(Set);

    
private:
    int *set;
    static const int sentinal=-999;
    int fillsize, psize, lsize;
    static const int DEFAULTSIZE= 10;
    void display( ostream &) const;
    void input( istream &);
};

#endif
