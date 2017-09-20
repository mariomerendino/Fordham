//
//  main.cpp
//  Cave Adventure
//
//  Created by Mario J Merendino on 12/7/15.
//  Copyright (c) 2015 Mario J Merendino. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctime>
using namespace std;
void OldMcDonald();
void twelvedays();
void Level1();
int main(){
    string Name;
    char ans1, ans2;
    cout << "Brave Night! What is your name: ";
    cin >> Name;
    cout << "We are in need of your help " << Name << "!" << endl;
    cout << "We need you to defeat them, can you help? (Y or N): ";
    cin >> ans1;
    if( ans1== 'n'|| ans1== 'N'){
        cout << "GAMEOVER"<<endl;
        exit(0);
    }
    cout << "Thank You Thank You Oh brave knight, are you ready to enter the mouth of the caves (Y/N)?";
    cin >> ans2;
    do{
        if ( ans2== 'n'|| ans2== 'N'){
            cout << "…. Please, please help up brave knight, are you ready to enter the mouth of the caves (Y/N)?";
            cin >> ans2;
        }
        
    }while (ans2=='n'|| ans2=='N');
    Level1();
}

void OldMcDonald(){
    string animal, noise;
    int x;
    srand(time_t(1));
    x =(rand() % 6 + 1);
    switch (x){
        case 1:
            animal = "Dog";
            noise = "Wuf";
            break;
        case 2:
            animal = "Cow";
            noise = "Moo";
            break;
        case 3:
            animal = "Pig";
            noise = "Oink";
            break;
        case 4:
            animal = "Sheep";
            noise = "Baa";
            break;
        case 5:
            animal = "Cat";
            noise = "Meow";
            break;
    }
    
    cout << "Old mac donald had a farm EI-EI-O\nAnd on that farm, He had a " << animal << " EI-EI-O\nwith a " <<noise << "-" << noise << " here, and a\n" << noise << "-" << noise << " there Everywhere a " <<noise << "-" << noise<< "\nOld mac donald had a farm EI-EI-O" << endl;
}
void twelvedays(){
    string day, gift;
    for (int i=1; i<13; i++){
        switch (i) {
            case 1:
                day= "First";
                gift= "a partige in a pear tree";
                break;
            case 2:
                day= "Second";
                gift= "two french hens, and a partige in a pear tree";
                break;
            case 3:
                day= "Third";
                gift= "three turtle doves, two french hens, and a partige in a pear tree";
                break;
            case 4:
                day = "Fourth";
                gift= "Four calling brids, three turtle doves, two french hens, and a partige in a pear tree";
                break;
            case 5:
                day = "Fifth";
                gift = "Five GOLDEN RINGS, Four calling brids,three turtle doves, two french hens, and a partige in a pear tree";
                break;
            case 6:
                day = "Sixth";
                gift = "Six Geese Laying, Five GOLDEN RINGS, Four calling brids,three turtle doves, two french hens, and a partige in a pear tree";
                break;
            case 7:
                day = "Seventh";
                gift = "Seven Swans swimmnig, Six Geese Laying, Five GOLDEN RINGS, Four calling brids, three turtle doves, two french hens, and a partige in a pear tree";
                break;
            case 8:
                day= "Eighth";
                gift= "Eight Maids a milking, Seven Swans swimmnig, Six Geese Laying, Five GOLDEN RINGS, Four calling brids, three turtle doves, two french hens, and a partige in a pear tree";
                break;
            case 9:
                day = "Nineth";
                gift= "Nine Pipers Piping, Eight Maids a milking, Seven Swans swimmnig, Six Geese Laying, Five GOLDEN RINGS, Four calling brids, three turtle doves, two french hens, and a partige in a pear tree";
                break;
            case 10:
                day = "Tenth";
                gift= "Ten Drummers Drumming, Nine Pipers Piping, Eight Maids a milking , Seven Swans swimmnig, Six Geese Laying, Five GOLDEN RINGS, Four calling brids, three turtle doves, two french hens, and a partige in a pear tree";
                break;
            case 11:
                day= "Eleventh";
                gift= "Eleven Lords a leaping, Ten Drummers Drumming, Nine Pipers Piping, Eight Maids a milking, Seven Swans swimmnig, Six Geese Laying, Five GOLDEN RINGS,\nFour calling brids, three turtle doves, two french hens, and a partige in a pear tree";
                break;
            case 12:
                day = "Twelfth";
                gift= "Twelve Ladies dancing,Eleven Lords a leaping, Ten Drummers Drumming, Nine Pipers Piping Eight Maids a milking, Seven Swans swimmnig, Six Geese Laying, Five GOLDEN RINGS, Four calling brids, three turtle doves, two french hens, and a partige in a pear tree";
                break;
            }
        cout << "On the " << day << " day of Christmas my true love gave to me, " << gift <<endl<<endl;
    }
}
void Level1(){
    bool obtainsword(false), killgoblin(false), level(false);
    int ans1, ans2, ans3;
    cout << "\n\nLEVEL 1:" <<endl;
    if(obtainsword==false && killgoblin==false){
        cout << "You are now entering the mouth of the cave\nWhat would you like to do?"<<endl;
        cout << "\t1. Attack the Goblin\n\t2. Pick up GoldenSword\n>>";
        cin >> ans1;
        switch(ans1){
            case 1:
                killgoblin=true;
                break;
            case 2:
                obtainsword=true;
                break;
            default:
                killgoblin=true;
                break;
        }
    }
    if(obtainsword==true && killgoblin==false){
        cout <<"You picked up the treasure without killing the goblin, you must rest!" <<endl;
        OldMcDonald();
        cout <<"\nGreat You're Well Rested! what would you like to do?"<<endl;
        cout <<"\t1. Kill the Goblin" <<endl;
        cin >> ans2;
        killgoblin=true;
        level=true;
    }
    if(obtainsword==false && killgoblin == true){
        cout <<"\nYou killed the goblin and you're still alive what would you like to do?" <<endl;
        cout <<"\t1. Move on to Next adventure\n\t2. Pick up Golden Sword\n>>";
        cin >> ans3;
        switch(ans3){
            case 1:
                level=true;
                break;
            case 2:
                obtainsword=true;
                level=true;
                break;
            default:
                obtainsword=true;
                break;
        }
    }
    if (level== true && obtainsword==false){
        cout <<"Bitch";
        
    }
    if(level==true && obtainsword==true && killgoblin ==true){
        cout << "You win";
    }
    
}