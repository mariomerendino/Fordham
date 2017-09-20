//
//  main.cpp
//  recursivecount
//
//  Created by Mario J Merendino on 4/26/16.
//  Copyright © 2016 Mario J Merendino. All rights reserved.
//

#include <iostream>
#include <string.h>
using namespace std;
bool isString(string test){
    bool ret=false;
    static int acount(0);
    char firstletter=test[0];
    if(firstletter==test[acount]){
        acount++;
        isString(test);
    }
    if(acount*2==test.length()-acount){
        ret=true;
    }
    return ret;
}
int main() {
    string test;
    bool yes;
    cout << "Enter a string a2b: ";
    cin >> test;
    yes=isString(test);
    if(yes){
        cout << "true" <<endl;
    }
    else{
        cout << "false"<<endl;
    }
    
}
