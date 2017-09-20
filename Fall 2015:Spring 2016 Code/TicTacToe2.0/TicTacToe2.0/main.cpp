//  Driver program
//  main.cpp
//  TicTacToe2.0
//  Mario J Merendino
//  Prof papadakis

#include <iostream>
#include "TicTacToe.h"
#include "TicTacToe.cpp"
using namespace std;
int main() {
    TicTacToe t1;//creates tic tac toe obj
    TicTacToe t2("mario", "john", "MariosHandle", "JohnsHandle", 'X', 'O' );
    t1.run();
    t2.run();
}
