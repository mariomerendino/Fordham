//
//  main.cpp
//  Prime
//
//  Created by Mario J Merendino on 10/5/15.
//  Copyright (c) 2015 Mario J Merendino. All rights reserved.
//

#include <iostream>
using namespace std;
bool prime(int test);
int main(){
    int number=1;
    for(int i= 10; i >= number;)
    {
        int post;
        post=(number*number)-(number)+11;
        prime(post);
        if(prime)
        {
        cout << number << ":" << post << " true" <<endl;
        }
        else
        {
        cout << number << ":" << post << " false" <<endl;
        }
        number++;
    }
}
bool prime(int test)
{
    bool pass;
    for(int a=2;a>test;a++)
    {
        if(test%a==0)
        {
            pass=false;
        }
        else
        {
            pass=true;
        }
    }
    return(pass);
}