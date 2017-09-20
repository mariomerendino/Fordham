//
//  player.h
//  TicTacToe2.0
//
//  Created by Mario J Merendino on 12/12/15.
//  Copyright (c) 2015 Mario J Merendino. All rights reserved.
//

#ifndef __TicTacToe2_0__player__
#define __TicTacToe2_0__player__

#include <iostream>
#include <string.h>
using namespace std;
class player{//creates player class
public:
    player();//default constructor
    player(string,string,char);//constructor that takes in name, handle, and marker
    void input();//input method
    void setname(string);//mutators
    void sethandle(string);
    void setmarker(char);
    void setwon(int);
    string gethandle();//accessors
    string getname();
    char getmarker();
    int getwon();
    void increasewon();//increases amount of games won
private:
    string name, handle;
    int won, turns;
    char marker;
};

#endif /* defined(__TicTacToe2_0__player__) */
