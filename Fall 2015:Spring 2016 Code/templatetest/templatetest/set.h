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
#include <string.h>

using std::string;
using namespace std;
template <class T>
class Set{
    friend ostream &operator<<( ostream &os, Set& a ){
        a.display(os);
        return(os);
    }
    friend istream &operator>>( istream &os, Set& a){
        a.input(os);
        return(os);
    }
public:
    Set(int=DEFAULTSIZE);
    //Set(Set &, int);
    ~Set();
    void setsentinal();
    void setivar();
    bool element(T);
    void display(ostream &);
    void input(istream &);
    Set<T> Union(Set);
    Set<T> Intersection(Set);
    Set<T> Difference(Set);
    Set<T> addelement(T);
    Set<T> delelement(T);
    Set<T> operator+(Set);
    Set<T> operator-(Set);
    Set<T> operator^(Set);
    Set<T> operator+(T);
    Set<T> operator-(T);
    bool operator==(Set);
private:
    T *set;
    T sentinal;
    T ivar;
    int fillsize, psize, lsize;
    static const int DEFAULTSIZE= 10;

};
#include "set.cpp"
#endif
