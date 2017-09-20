//
//  struct.cpp
//  Midterm CISC2200
//
//  Created by Mario J Merendino on 3/15/16.
//  Copyright © 2016 Mario J Merendino. All rights reserved.
//

#include <iostream>
using namespace std;
struct node{
    int value;
    node *next;
    node(int v=0, node *p=NULL):value(v),next(p){
        
    }
};
void append(node *&head, int val){
    node *tail;
    tail=head;
    node *cur=new node(val,NULL);
    if(head==NULL){
        head=cur;
    }
    else{
        while(tail->next!=NULL){
            tail=tail->next;
        }
        tail->next=cur;
    }
}
void display(node *&head){
    node *tmp;
    tmp=head;
    while(tmp!=NULL){
        cout << tmp->value << " ";
        tmp=tmp->next;
    }
    cout <<endl;
}
void length(node*& head){
    node *tail;
    int length=0;
    tail=head;
    while(tail!=NULL){
        tail=tail->next;
        length++;
    }
    cout << "\nLength " << length <<endl;
}
void lastpointer(node*& head){
    node *tail;
    tail=head;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    cout << "last value: " << tail->value << endl;
}
void secondlastpointer(node*& head){
    node *tail;
    tail=head;
    while(tail->next->next!=NULL){
        tail=tail->next;
    }
    cout << "second to last value: " << tail->value << endl;
}
void merge(node*& head, node*&head2){
    node *tail;
    tail=head;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    tail->next=head2;
}
void twentynodes(node*& head){
    node * tail;
    tail=head;
    int counter=1;
    while(counter!=20){
        tail->next = new node(0, NULL);
        tail = tail -> next;
        counter++;
    }
}
void deletenodes(node *&head){
    node *cur;
    cur=head;
    while(cur!=NULL){
        node *temp=cur->next;
        delete cur;
        cur=temp;
    }
}
int main(){
    node *head= NULL;
    node *head2=NULL;
    /*int tempval, amt;
    for (int i=0; i<3; i++){
        cout << "insert a value ";
        cin >> tempval;
        append(head, tempval);
    }
    for (int i=0; i<3; i++){
        cout << "insert a value(head2) ";
        cin >> tempval;
        append(head2, tempval);
    }*/
    
    twentynodes(head);
    display(head);
    deletenodes(head);
    //length(head);
    //lastpointer(head);
    //secondlastpointer(head);
    //merge(head, head2);
    //display(head);
    
    
    
}