//  Author: Mario Merendino
//  Professor Papadakis;
//  Lab4
//  Creates an Object named set, and compares the values in each obj.
//  Last Modified: 11/12/15.


#include <iostream>
#include <cstdlib>
#include "set.h"
#include "set.cpp"

int main(){
    cout << "Welcome to the Set creator, Please create two sets"<<endl;;
    cout << "There cannot be any duplicate values within the set"<<endl;
    Set A, B, C;
    int interger, spotinarray;
    cin >> A;
    cin >> B;
    cout << "Set A: " << A;
    cout << "Set B: " << B;
    cout << "Calculating Union of the two Sets" <<endl;
    C= A+B;
    cout << "Set C: " << C;
    cout << "Calculating the Difference of the two Sets(A-B)" << endl;
    C= A-B;
    cout << "Set C: " << C;
    cout << "Calculating the Intersection of the two Sets" << endl;
    C= A^B;
    cout << "Set C: " << C;
    cout << "Set A and B are ";
    if(A==B)
        cout <<"EQUAL" << endl;
    else
        cout << "NOT EQUAL"<< endl;
    cout << "Add one more interger to set A: ";
    cin >> interger;
    A= A+interger;
    cout << "Set A: "<< A;
    cout << "Remove one interger from set B" <<endl;
    cin >> spotinarray;
    B= B-spotinarray;
    cout <<"Set B: " << B;
}
