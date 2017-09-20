//
//  TicTacToe.h
//  TicTacToe2.0
//
//  Created by Mario J Merendino on 12/12/15.
//  Copyright (c) 2015 Mario J Merendino. All rights reserved.
//

#ifndef __TicTacToe2_0__TicTacToe__
#define __TicTacToe2_0__TicTacToe__

#include <iostream>
#include "cell.h"
#include "cell.cpp"
#include "player.h"
#include "player.cpp"
#include "date.h"
#include "date.cpp"
using namespace std;
class TicTacToe{//creates tic tac toe class
public:
    TicTacToe();//default constructor
    TicTacToe(string,string,string,string,char,char);//default constructor that takes in two players
    void startgame();//starts game
    void clearboard();//wipes board
    void display();//displays board
    void displayblank();//displays board with coordinates
    void input();//input method
    bool checkwinner();//checks for a winner
    void run();//runs game
    void run2();//runs game with user inputed names
    void cplayer();//changes player
    bool checkoccupied(int,int);//checks for an occupied space
    bool checkbounds(int,int);//checks if input is in bounds
    void stats();//displays stats
private:
    static const int ROW=3;
    static const int COL=3;
    static const int DEFAULT_NUM_PLAYER=2;
    int numgames;
    cell Board[ROW][COL];
    int currentplayer, turns;
    player p[DEFAULT_NUM_PLAYER];
    Date d;
    bool first, runwithoutplayerinput;

};

#endif /* defined(__TicTacToe2_0__TicTacToe__) */
