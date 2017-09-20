//  TicTacToe.cpp
//  TicTacToe2.0
//
//  Created by Mario J Merendino on 12/12/15.
//  Copyright (c) 2015 Mario J Merendino. All rights reserved.
//
#include "TicTacToe.h"
TicTacToe::TicTacToe(){//default constructor
    turns=0;
    currentplayer=0;
    numgames=0;
    runwithoutplayerinput=false;
}
TicTacToe::TicTacToe(string n1, string n2, string h1,string h2, char m1, char m2){//constructor that takes in name, handle, marker
    p[0].setname(n1);
    p[0].sethandle(h1);
    p[0].setmarker(m1);
    p[1].setname(n2);
    p[1].sethandle(h2);
    p[1].setmarker(m2);
    turns=0;
    currentplayer=0;
    numgames=0;
    runwithoutplayerinput=true;
}

void TicTacToe::startgame(){//starts game
    int choice,choice2;
    cout << "PLAYER 1\n";//takes in p1 and p2 data
    p[0].input();
    cout << "\nPLAYER 2\n";
    p[1].input();
    cout << "Who wants to be X?\n\t1. P1\n\t2. P2\n>>";//prompts to see who is x or o
    cin >>choice;
    switch (choice){
        case 1:
            p[0].setmarker('X');//sets markers depending on choice
            p[1].setmarker('O');
            break;
        case 2:
            p[0].setmarker('O');
            p[1].setmarker('X');
            break;
        default:
            p[0].setmarker('X');
            p[1].setmarker('O');
            break;
    }
    cout << "Who wants to go first?\n\t1. P1\n\t2. P2\n>>";//sees who wants to go first
    cin >>choice2;
    switch(choice2){
        case 1:
            first=true;//sets data member "first" to true or false depending on input
            break;
        case 2:
            first=false;
            break;
        default:
            first=true;
            break;
    }
}
void TicTacToe::input(){//user input
    int x, y;
    do{
        cout << p[currentplayer].getname() <<" your move! Enter the coordinates(x,y): ";//prompts user to enter coordinates
        cin >> x >> y;
    }while(!(checkoccupied(x,y) && checkbounds(x,y)));//checks if space is occupied or not
    Board[x-1][y-1].setmarker(p[currentplayer].getmarker());//sets boards space to current players marker
}
void TicTacToe::display(){//displays board
    for(int y=0; y< COL; y++){
        for(int x=0; x<ROW; x++){
            if(x==ROW-1){
                cout << " " << Board[x][y].getmarker() << " ";
            }
            else{
                cout << " " << Board[x][y].getmarker() << " " << "|" ;
            }
        }
        if(y==COL-1){
            cout <<endl;
        }
        else{
            cout <<endl<< "-----------"<<endl;
        }
    }
}
void TicTacToe::displayblank(){//displays a board with coordinates
    cout << "  DISPLAY BOARD" <<endl;
    for(int y=0; y< COL; y++){
        for(int x=0; x<ROW; x++){
            if(x==ROW-1){
                cout << " " << x+1 << "," << y+1 << " ";
            }
            else{
                cout << " " << x+1 << "," << y+1 << " " << "|" ;
            }
        }
        if(y==COL-1){
            cout <<endl;
        }
        else{
            cout <<endl<< "-----------------"<<endl;
        }
    }
}
bool TicTacToe::checkbounds(int x, int y){//checks bounds on users input
    bool returnval(true);
    if(x > ROW || x < 1){
        returnval=false;
        cout << "Your entry was invalid" << endl;
    }
    if(y > ROW||y < 1){
        returnval=false;
        cout << "Your entry was invalid" << endl;
    }
    return(returnval);
}
bool TicTacToe::checkoccupied(int x, int y){//checks if space is occupied
    bool returnval(true);
    if(Board[x-1][y-1].getmarker()=='X' || Board[x-1][y-1].getmarker()=='O'){
        returnval=false;
        cout << "That space is Occupied" <<endl;
    }
    return(returnval);
}
bool TicTacToe::checkwinner(){//checks fora winner
    bool winner(false);
    for(int y=0; y < ROW; y++){
        if(Board[0][y].getmarker()!=' '&& Board[0][y].getmarker()==Board[1][y].getmarker()&&Board[1][y].getmarker()==Board[2][y].getmarker()){
            winner=true;//checks vertical
        }
        if(Board[y][0].getmarker()!=' '&& Board[y][0].getmarker()==Board[y][1].getmarker()&&Board[y][1].getmarker()==Board[y][2].getmarker()){
            winner=true;//checks horizontal
        }
    }
    if(Board[0][0].getmarker()!=' '&& Board[0][0].getmarker()==Board[1][1].getmarker()&&Board[1][1].getmarker()==Board[2][2].getmarker()){
        winner=true;//checks diagonal
    }
    if(Board[0][2].getmarker()!=' '&&Board[0][2].getmarker()==Board[1][1].getmarker()&&Board[1][1].getmarker()==Board[2][0].getmarker()){
        winner=true;//checks other diagonal
    }
    if (winner==true){
        cout << p[currentplayer].getname() <<" is the WINNER!!" <<endl;
        p[currentplayer].increasewon();//increases current players win count
    }
    if (winner==false && turns==9){
        cout << "There is a tie!" <<endl;
    }
    return(winner);
}
void TicTacToe::clearboard(){//wipes board
    for(int y=0; y< COL; y++){
        for(int x=0; x<ROW; x++){
            Board[x][y].setmarker(' ');
        }
    }
}
void TicTacToe::cplayer(){//sets current player
    if (first){//if bool first is true
        if (turns%2==0){//player 0 goes first
            currentplayer=0;
        }
        else{
           currentplayer=1;
        }
    }
    if(!first){//if bool first is false
        if (turns%2==0){//player 1 goes first
            currentplayer=1;
        }
        else{
            currentplayer=0;
        }
    }
}
void TicTacToe::stats(){//displays statistics of game
    cout << "Todays Date: ";
    d.display();
    cout << "Number of Games Played: " << numgames <<endl;
    cout << p[0].getname() << " won " << p[0].getwon() << " games!"<<endl;
    cout << p[1].getname() << " won " << p[1].getwon() << " games!"<<endl;
}
void TicTacToe::run(){ //RUNS GAME OF TICTACTOE
    bool end(false), endgame(false);
    char ans;
    d.input();
    if(!runwithoutplayerinput){
        startgame();//players input names and handles
    }
    do{
        end=false;
        endgame=false;
        displayblank();//displays a labled board
        cplayer();
        do{
            input();//player inputs move
            display();//displays board
            turns++;//turns increases
            if (turns > 4){
                if(checkwinner()){
                    end=true; //if there is awinner the game ends
                }
                if (turns==9){
                    end=true;//if the game reaches 9 turns the game ends
                }
            }
            cplayer(); //changes player
        }while(!end);//repeats until bool end==true
        numgames++;//number of games increase
        clearboard();//clears board
        stats();//displays stats of games played
        turns=0;//resets turns
        currentplayer=0;//resets current player
        cout << "Would you like to play again(y/n)?";
        cin >> ans;
        if(ans=='n'||ans=='n'){
            endgame=true;
        }
    }while(!endgame);
}
