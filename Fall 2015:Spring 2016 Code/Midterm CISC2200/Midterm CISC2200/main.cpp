//
//  main.cpp
//  Midterm CISC2200
//
//  Created by Mario J Merendino on 2/29/16.
//  Copyright © 2016 Mario J Merendino. All rights reserved.
//
#include "staticintarray.h"
#include "staticintarray.cpp"

void problem1();
void bubblesort(int a[], int size);
void reversearray(int a[], int size);
int * retreverse(int a[], int size);
void displayarray(int a[], int size);
void selectionsort(int a[], int size);
#include <iostream>
using namespace std;
int main(){
    const int size=5;
    int a[size]={9,4,3,11,5};
    displayarray(a, size);
    int *q=retreverse(a, size);
    displayarray(q, size);
    bubblesort(q, size);
    displayarray(q, size);
    /*StaticIntArray b;
    b.input();
    b.display();
    b.min();
    cout << endl <<sizeof(a);*/
    
    
}
void bubblesort(int a[],int size){
    int temp, rightend(size-1);
    for(int pass=0; pass<size-1; pass++){
        for(int i=0; i<rightend; i++){
            if(a[i]>a[i+1]){
                temp=a[i];
                a[i]=a[1+i];
                a[i+1]=temp;
            }
        }
        rightend--;
    }
    
}
void selectionsort(int a[], int size){

    
}
void problem1(){
    int a[2]={1,2};
    int *p;
    p = &(a[0]);
    cout << *p <<endl;
    int *q= new int; // (2)
    *q = 3; // (3)
    cout << *q << endl;
    *q = *p;
    cout << *q <<endl;
    q = p+1; //
    cout << *q<<endl;
}
void reversearray(int a[], int size){
    int temp;
    int last=size-1;
    for(int i=0; i < last; i++){
        temp=a[last-i];
        a[last-i]=a[i];
        a[i]=temp;
    }
}
void displayarray(int a[], int size){
    for (int i=0; i<size; i++){
        cout << a[i] << " ";
    }
    cout <<endl;
}
int * retreverse(int a[], int size){
    int *arr=new int[size];
    int last=size-1;
    for(int i=0; i < last; i++)
        arr[i]=a[last-i];
    return arr;
}
void problem11(){
    int a=10;

}
template <class T>
size_t ptrsize(T *ptr){
    return (sizeof(ptr));
}