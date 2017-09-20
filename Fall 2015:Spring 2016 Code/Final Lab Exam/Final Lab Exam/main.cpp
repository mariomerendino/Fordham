//
//  main.cpp
//  Final Lab Exam
//
//  Created by Mario J Merendino on 5/4/15.
//  Copyright (c) 2015 Mario J Merendino. All rights reserved.

#include <iostream>
using namespace std;

void fillArray(int a[], int& num, int f1, int f2);
void displayArray(int a[], int& num);
void sum(int a[], int& num);

int main()
{
    int number=50, x=0, y=1;
    int fibonacci[number];
    cout << "The first 50 Fibonacci numbers are: ";
    fillArray(fibonacci, number, x, y);
    displayArray(fibonacci, number);
    sum(fibonacci, number);
}

void fillArray(int a[], int& num, int f1, int f2)
{
    for ( int i =0; i < num; i++ )
    {
        if ( i == 0 ) a[i] = 0;
        else if ( i == 1 ) a[i] = 1;
        else a[i] = a[i -1] + a[i -2];
    }

}
void displayArray(int a[], int& num)
{
    for (int n=0; n < num; n++) //Displays
    {
        cout << "\t\t" << a[n];
        if (n%4 ==0)
        {
            cout << endl;
        }
    }
    cout << endl;
}
void sum(int a[], int& num)
{
    int total;
    for (int n=0; n < num; n++)
    {
        total = a[n] + a[n+1];
    }
    cout << "the sum of the first 50 Fibonacci numbers is:";
}