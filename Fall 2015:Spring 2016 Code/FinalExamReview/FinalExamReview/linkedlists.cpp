//
//  linkedlists.cpp
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
    NodeType (int v=0, NodeType * p=NULL):value(v),next(p)
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
void insertinbeginning(NodeType *& head, int num){
    NodeType * p;
    p= new NodeType(num, head);
    head=p;
}
void append(NodeType * & head, int num){

    NodeType *tmp, *cur;
    tmp=new NodeType(num, NULL);
    cur=head;
    if(cur==NULL){
        NodeType * p;
        
        p = new NodeType;
        
        p->value = num;
        p->next = head;
        
        head = p;
    }
    else{
        while(cur->next!=NULL){
            cur=cur->next;
        }
        cur->next=tmp;
    }
}
void removebypos(NodeType *& head, int pos){
    int counter=1;
    NodeType * cur= head;
    NodeType * temp;
    while(counter!= pos){
        counter ++;
        temp=cur;
        cur= cur->next;
    }
    temp->next= cur->next;
    cur=head;
}
void reversedLinkedList(NodeType *& head)
{
    if(head == NULL) return;
    
    NodeType *prev = NULL,*current = NULL, *next = NULL;
    current = head;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    // now let the head point at the last node (prev)
    head = prev;
}
void removebyvalue(NodeType *& head, int value){
    NodeType * cur= head;
    NodeType * temp;
    if(head->value==value){
        cur=cur->next;
        cur=head;
    }
    else{
        while(cur->value!= value){
            temp=cur;
            cur= cur->next;
        }
        temp->next= cur->next;
        cur=head;
    }
}
void insertinbetween(NodeType *& head, int prevVal, int value){
    NodeType * cur= head;
    NodeType * temp;
    while (cur->value!=prevVal){
        cur= cur->next;
    }
    temp= cur->next;
    NodeType * insert= new NodeType(value, temp);
    cur->next= insert;
}
NodeType * MinimumLocation(NodeType * list, NodeType *& minptr){
    if(list!=NULL){
        if(list->value < minptr->value){
            minptr = list;
        }
        return MinimumLocation(list->next, minptr);
    }
    else
        return minptr;
}
NodeType * merge(NodeType * list1, NodeType * list2){
    NodeType * list3;
    NodeType * cur, * tail;
    
    return list3;
}
int main(){
    cout << "Enter into Linked List(1) : ";
    int value;
    cin >> value;
    NodeType * list=new NodeType(value, NULL);
    for (int i=0; i<5; i++){
        cout << "Enter into Linked List(1) : ";
        cin >> value;
        append(list, value);
    }
    display(list);
    reversedLinkedList(list);
    display(list);
}