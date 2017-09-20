//
//  main2.cpp
//  PrintDollarAmount
//
//  Created by Mario J Merendino on 2/7/16.
//  Copyright © 2016 Mario J Merendino. All rights reserved.
//

#include <iostream>
#include "DollarAmount.h"
#include "DollarAmount.cpp"
int main(){
    Dollar d1;
    char ans;
    cout << "Welcome to the CheckPrinter!" << endl << "Please input a number with only two decimal places greater than 0 and less than 10,000" << endl <<endl;//greets user
    do{
        d1.input();
        d1.PrintInEnglish();
        cout << "Would you like to continue?(Y or N)" <<endl;
        cin >> ans;
    }while(ans== 'Y'|| ans== 'y');
    cout << "GoodBye!" <<endl;
}
