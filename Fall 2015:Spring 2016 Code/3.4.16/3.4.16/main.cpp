//
//  main.cpp
//  3.4.16
//
//  Created by Mario J Merendino on 3/4/16.
//  Copyright © 2016 Mario J Merendino. All rights reserved.
//
#include <iostream>
using namespace std;

struct IntNodeType{
    int value;
    IntNodeType *next=NULL;
};

void display(IntNodeType *);

int main() {
    IntNodeType *head, *temp, *n;
    int amt;
    int vals[4]={1,2,3,4};
    n= new IntNodeType;
    temp=n;
    head=n;
    for(int i=0; i<4; i++){
        n= new IntNodeType;
        n->value=vals[i];
        temp->next=n;
        temp=n;
    }
    display(head);
}
void display(IntNodeType *p){
    IntNodeType *cur;
    cur=p;
    while(cur!=NULL){
        cout << cur->value << " ";
        cur=cur->next;
    }
}
