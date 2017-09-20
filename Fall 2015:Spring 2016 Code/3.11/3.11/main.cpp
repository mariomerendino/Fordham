//
//  main.cpp
//  3.11
//
//  Created by Mario J Merendino on 3/11/16.
//  Copyright © 2016 Mario J Merendino. All rights reserved.
//
using namespace std;
#include <iostream>
void selectionsort(int a[], int size);
int main(){
    const int size=10;
    int a[size];
    cout << "Fill array of ten ints: " << endl;
    for (int i=0; i <size; i++){
        cin >> a[i];
    }
    cout << "Before sort" <<endl;
    for (int i=0; i <size; i++){
        cout << a[i] << " ";
    }
    selectionsort(a, size);
    cout << "After sort" <<endl;
    for (int i=0; i <size; i++){
        cout << a[i] << " ";
    }
}
void selectionsort(int a[], int size){
    int pass, largestindex(0), rightend(size-1);
    for(pass=0; pass < size-1; pass++){
        for(int i=1; i<rightend; i++){
            if(a[i]<a[largestindex]){
                largestindex=i;
            }
        }
        a[largestindex]=a[rightend];
        rightend--;
    }
}
