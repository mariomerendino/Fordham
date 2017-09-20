//
//  player.cpp
//  TicTacToe2.0
//
//  Created by Mario J Merendino on 12/12/15.
//  Copyright (c) 2015 Mario J Merendino. All rights reserved.
//

#include "player.h"
player::player(){//default constructor
    name="John";
    handle="Appleseed";
    marker= 'X';
    won=0;
}
player::player(string n, string h, char m){ //constructor that takes in name date and marker
    name=n;
    handle=h;
    marker=m;
}
void player::input(){//input method
    cout << "Whats your name: ";
    cin >> name;
    cout << "Whats your handle: ";
    cin >> handle;
}
void player::setname(string n){//mutators
    name=n;
}
void player::sethandle(string h){
    handle=h;
}
void player::setwon(int w){
    won=w;
}
void player::setmarker(char m){
    marker=m;
}
string player::gethandle(){//accessors
    return(handle);
}
string player::getname(){
    return(name);
}
int player::getwon(){
    return(won);
}
char player::getmarker(){
    return(marker);
}
void player::increasewon(){//increases amt games won. 
    won++;
}

