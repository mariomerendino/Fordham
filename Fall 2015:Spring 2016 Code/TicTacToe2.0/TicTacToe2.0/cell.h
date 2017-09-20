//  Creats cell class
//  cell.h
//  TicTacToe2.0
//  Mario J Merendino
//  Prof Papadakis

#ifndef __TicTacToe2_0__cell__
#define __TicTacToe2_0__cell__

#include <iostream>
using namespace std;
class cell{//creates cell class
public:
    cell();//default constructor
    int getrow();//accessors
    int getcol();
    int getival();
    char getmarker();
    void setrow(int);//mutators
    void setcol(int);
    void setmarker(char);
private:
    int row, col;
    char marker, ival;
};
#endif /* defined(__TicTacToe2_0__cell__) */
