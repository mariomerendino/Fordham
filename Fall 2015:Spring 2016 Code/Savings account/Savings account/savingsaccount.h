//
//  savingsaccount.h
//  Savings account
//
//  Created by Mario J Merendino on 12/16/15.
//  Copyright (c) 2015 Mario J Merendino. All rights reserved.
//

#ifndef __Savings_account__savingsaccount__
#define __Savings_account__savingsaccount__

#include <stdio.h>
#include <iostream>
#include "name.h"
#include "name.cpp"
#include "date.h"
#include "date.cpp"
#include "customer.h"
#include "customer.cpp"
#include <cstdlib>
#include <time.h>
using namespace std;
class savingsaccount{
public:
    savingsaccount();
    double calculateMonthlyInterest();
    static void modifyInterestRate(double);
    void updateSavingsBalance();
    void updatesavingsbalance();
    void customername(string, string);
    void setofficer();
    void setdate();
    void setbalance(double);
    static void activeofficerinput();
    static void cdateinput();
    void displayofficer();
    void accountnumbergen();
    int getaccountnumber();
    void displaycustomer();
    void getcdate();
    void getodate();
    void oneyearlater();
    double getbalance();
private:
    customer c;
    Name accountofficer;
    static Name activeofficer;
    Date odate;
    static Date cdate;
    int accountNumber;
    double balance, monthlyinterest;
    static double annualInterestRate;

};


#endif /* defined(__Savings_account__savingsaccount__) */
