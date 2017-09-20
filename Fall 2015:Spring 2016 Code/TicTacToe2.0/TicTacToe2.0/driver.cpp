//
//  driver.cpp
//  TicTacToe2.0
//
//  Created by Mario J Merendino on 12/16/15.
//  Copyright (c) 2015 Mario J Merendino. All rights reserved.
//
#include "date.h"
#include "date.cpp"
#include <iostream>
using namespace std;
int main(){
    Date d;
    d.input();
    d.display();
    d++;
    d.display();
    ++d;
    d.display();
}