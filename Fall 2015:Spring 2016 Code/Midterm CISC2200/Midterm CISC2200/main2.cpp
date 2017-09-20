//
//  main2.cpp
//  Midterm CISC2200
//
//  Created by Mario J Merendino on 3/14/16.
//  Copyright © 2016 Mario J Merendino. All rights reserved.
//

#include <iostream>
using namespace std;
void displayarray(int a[],int cap,int delim);
void findLargestSmallest(int a[],int cap,int delim, int &largest);
int main(){
    const int cap(11), delim(-999);
    int a[cap],largest;
    for(int i=0; i<cap-2; i++){
        cout << "Enter up to 10 positive ints or -999 to end: "<< endl;
        cin >> a[i];

        if(a[i]==delim){
            break;
        }
        if(i==9){
            a[10]=delim;
        }
    }
    displayarray(a,cap,delim);
    findLargestSmallest(a, cap, delim, largest);
    cout << largest;
    
}
void displayarray(int a[], int cap, int delim){
    for (int i=0; i<cap; i++){
        if(a[i]==delim){
            break;
        }
        else{
            cout << a[i] << " ";
        }
    }
    cout <<endl;
}
void findLargestSmallest(int a[],int cap, int delim, int &largest){
    largest=a[0];
    for(int i=0;i<cap; i++){
        if(a[i]==delim){
            break;
        }
        else{
            if(a[i]>largest){
                largest=a[i];
            }
        }
    }
}
