//
//  savingsaccount.cpp
//  Savings account
//
//  Created by Mario J Merendino on 12/16/15.
//  Copyright (c) 2015 Mario J Merendino. All rights reserved.
//
//static double annualInterestRate=1.05;
#include "savingsaccount.h"
double savingsaccount::annualInterestRate(1.05);
Name savingsaccount::activeofficer;
Date savingsaccount::cdate;
savingsaccount::savingsaccount(){
    accountofficer=activeofficer;
    odate=cdate;
}
void savingsaccount::modifyInterestRate(double r){
    annualInterestRate=r;
}
double savingsaccount::calculateMonthlyInterest(){
    monthlyinterest=balance*((annualInterestRate/100)/12);
    return(monthlyinterest);
}
void savingsaccount::getcdate(){
    cdate.display();
}
void savingsaccount::getodate(){
    odate.display();
}
void savingsaccount::oneyearlater(){
    int y=cdate.getyear();
    y++;
    cdate.setyear(y);
}
void savingsaccount::customername(string f, string l){
    c.setfname(f);
    c.setlname(l);
}
void savingsaccount::setofficer(){
    activeofficer=accountofficer;
}
void savingsaccount::setdate(){
    cdate=odate;
}
void savingsaccount::setbalance(double b){
    balance=b;
}
void savingsaccount::updateSavingsBalance(){
    calculateMonthlyInterest();
    balance=(balance+monthlyinterest);
}
void savingsaccount::activeofficerinput(){
    activeofficer.input();
}
void savingsaccount::cdateinput(){
    cdate.input();
}
void savingsaccount::displayofficer(){
    accountofficer.display();
}
int savingsaccount::getaccountnumber(){
    return(accountNumber);
}
void savingsaccount::displaycustomer(){
    c.display();
}
double savingsaccount::getbalance(){
    return(balance);
}
