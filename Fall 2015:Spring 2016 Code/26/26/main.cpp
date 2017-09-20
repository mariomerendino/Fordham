//
//  main.cpp
//  26
//
//  Created by Mario J Merendino on 2/26/16.
//  Copyright © 2016 Mario J Merendino. All rights reserved.
//
using namespace std;
#include <iostream>
struct Node{
    char info;
    Node *next;
};
int main() {
    Node *header;
    header=NULL;
    header= new Node;
    header->info='H';
    header->next=NULL;
   
    Node *temp= new Node;
    temp->info='e';
    temp->next=NULL;
    header->next=temp;
    
    Node *temp2=new Node;
    temp2 ->info='l';
    temp2 ->next= NULL;
    temp ->next= temp2;
    
    Node *temp3=new Node;
    temp3 ->info='l';
    temp3 ->next= NULL;
    temp2 ->next= temp3;
    
    Node *temp4=new Node;
    temp4 ->info='l';
    temp4 ->next= NULL;
    temp3 ->next= temp4;
    
    Node *temp5=new Node;
    temp5 ->info='o';
    temp5 ->next= NULL;
    temp4 ->next= temp5;
    
    Node *temp6=new Node;
    temp6 ->info='!';
    temp6 ->next= NULL;
    temp5 ->next= temp6;
    
    Node *current=header;
    while (current!=NULL){
        cout << current->info;
        current= current->next;
    }
}
