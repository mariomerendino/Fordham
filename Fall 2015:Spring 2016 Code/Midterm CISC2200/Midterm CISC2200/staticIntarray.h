//
//  staticIntarray.hpp
//  Midterm CISC2200
//
//  Created by Mario J Merendino on 2/29/16.
//  Copyright © 2016 Mario J Merendino. All rights reserved.
//

#ifndef staticIntarray_h
#define staticIntarray_h

#include <iostream>
using namespace std;
class StaticIntArray {
public:
    StaticIntArray();
    void display();
    void input();
    void min();
    
private:
    static const int CAPACITY=20;
    int array[CAPACITY];
    int size; //size<=CAPACITY, keep track the length of the array’s filled part
};

#endif /* staticIntarray_h */
