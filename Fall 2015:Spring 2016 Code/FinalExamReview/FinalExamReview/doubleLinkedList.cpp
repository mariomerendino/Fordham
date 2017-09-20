
//
//  doubleLinkedList.cpp
//  FinalExamReview
//
//  Created by Mario J Merendino on 5/10/16.
//  Copyright © 2016 Mario J Merendino. All rights reserved.
//

#include <iostream>
using namespace std;
struct NodeType{
    int value;
    NodeType * next;
    NodeType * prev;
    NodeType (int v=0, NodeType * n=NULL, NodeType * p=NULL):value(v),next(n),prev(p)
    {
        //intentionally empty
    }
};
void display(NodeType * list){
    NodeType * p = list;
    int count=0;
    while (p != NULL){
        count ++;
        cout << "Node: #" << count << " Value: " << p->value << endl;
        p= p->next;
    }
}
void append(NodeType *& list, NodeType *& end, int value){
    
}
int main(){
    NodeType * head;
    NodeType * tail;
    head=tail;
    int value;
    for (int i=0; i< 4; i++){
        cout << "Enter a value: ";
        cin >> value;
        append(head, tail, value);
    }
    display(head);
}