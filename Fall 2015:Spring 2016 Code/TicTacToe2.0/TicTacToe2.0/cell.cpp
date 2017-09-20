//
//  cell.cpp
//  TicTacToe2.0
//
//  Created by Mario J Merendino on 12/12/15.
//  Copyright (c) 2015 Mario J Merendino. All rights reserved.
//

#include "cell.h"
cell::cell(){//default constructor
    row++;
    col++;
    ival= ' ';
    marker=ival;
}
void cell::setcol(int c){//mutators
    col=c;
}
void cell::setrow(int r){
    row=r;
}
void cell::setmarker(char m){
    marker=m;
}
int cell::getcol(){//accessor
    return(col);
}
int cell::getrow(){
    return(row);
}
char cell::getmarker(){
    return(marker);
}
