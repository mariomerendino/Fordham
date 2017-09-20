//  Author: Mario Merendino
//  Professor Papadakis;
//  Lab4
//  Creates an Object named set, and compares the values in each obj.
//  Last Modified: 11/12/15.


#include <iostream>
#include <cstdlib>
#include "set.h"
#include "set.cpp"

/*int main(){
    Set A;
    int interger;
    cin >> A;
    cout << A;
    cout << "remove one interger from the set: ";
    cin >> interger;
    A= A-interger;
    cout << A;
}*/
int main(){
    Set A, B, C;
    cin >> A;
    cin >> B;
    cout << A << B;
    C=B-A;
    cout << C;
}