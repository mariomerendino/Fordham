//
//  factorial.cpp
//  
//
//  Created by Mario J Merendino on 4/22/16.
//
//

#include <iostream>
using namespace std;
int factorial(int num){
    int result;
    if(num>0){
        result=factorial(num-1);
        return num*result;
    }
    else if (num==0){
        return 1;
    }
}
int main(){
    int ret;
    ret=factorial(4);
    cout << "Factorial(4)= "<< ret<<endl;
    
}