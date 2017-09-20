//
//  staticIntarray.cpp
//  Midterm CISC2200
//
//  Created by Mario J Merendino on 2/29/16.
//  Copyright © 2016 Mario J Merendino. All rights reserved.
//

#include "staticIntarray.h"

StaticIntArray::StaticIntArray(){
    size=0;
}
void StaticIntArray::input(){
    for (int i=0; i<CAPACITY; i++){
        int temp;
        cout << "Enter a value, enter 0 to end input: ";
        cin >> temp;
        if(temp==0){
            break;
        }
        else{
            array[i]=temp;
            size++;
        }
    }
}
void StaticIntArray::display(){
    for (int i=0; i<size; i++){
        cout << array[i] << " ";
    }
    cout << "\nSize of the array "<< size <<endl;
}
void StaticIntArray::min(){
    int smallest=array[0];
    for(int i=0; i<size; i++){
        if(array[i]<smallest){
            smallest=array[i];
        }
    }
    cout << smallest;
}

