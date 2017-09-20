//
//  main.cpp
//  Savings account
//
//  Created by Mario J Merendino on 12/16/15.
//  Copyright (c) 2015 Mario J Merendino. All rights reserved.
//

#include <iostream>
#include "savingsaccount.h"
#include "savingsaccount.cpp"
void accumulateinterest(int, savingsaccount[]);
void balancesummary(int, savingsaccount[]);
using namespace std;
int main() {
    savingsaccount *s[100];
    int numaccounts;
    double interest, sbal;
    string fname, lname;
    bool exit(false);
    cout << "Current Account Officer: "<<endl;
    s[0]->activeofficerinput();
    cout << "Current Date: "<<endl;
    s[0]->cdateinput();
    cout << "Current Annual Interest Rate: ";
    cin >> interest;
    s[0]->modifyInterestRate(interest);
    for(int x=0; x< 100; x++){
        while(!exit){
            s[x]=new savingsaccount();
            cout << "Enter Customers first name(exit '~'): ";
            cin >> fname;
            if(fname=="~"){
                exit=true;
            }
            else{
                cout << "Last name: ";
                cin >> lname;
                s[x]->customername(fname, lname);
                cout << "Enter Starting balance: ";
                cin >> sbal;
                s[x]->setbalance(sbal);
                numaccounts++;
            }
        }
    }
    accumulateinterest(numaccounts, s[numaccounts]);
    balancesummary(numaccounts, s[numaccounts]);
}
void accumulateinterest(int n, savingsaccount m[]){
    cout << "Accumulating interest for one year" <<endl;
    for (int x=0; x<n; x++){
        cout << "hi";
        m[x].updateSavingsBalance();
        m[x].oneyearlater();
    }
}
void balancesummary(int n, savingsaccount m[]){
    cout << "Account Officer\tDate Opened\tCurrent Date\tCustomer\tCurrent balance" <<endl;
    for(int x=0; x <n; x++){
        m[x].displayofficer();
        cout << "\t";
        m[x].getodate();
        cout << "\t";
        m[x].getcdate();
        cout << "\t";
        m[x].displaycustomer();
        cout << "\t" << m[x].getbalance() <<endl;
    }
}

