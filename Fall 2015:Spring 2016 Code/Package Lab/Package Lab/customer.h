//
//  customer.h
//  Package Lab
//
//  Created by Mario J Merendino on 12/7/15.
//  Copyright (c) 2015 Mario J Merendino. All rights reserved.
//

#ifndef Package_Lab_customer_h
#define Package_Lab_customer_h
#include <iostream>
using namespace std;
class customer{//Creates a class type customer
public:
    customer();//default constructor
    customer(string,string,string,string,string,string,int,int);//constructor that takes in every data member
    void input();//input method
    void display();//output method
    string getfname();//ACCESSOR METHODS
    string getlname();//
    string getcity();//
    string getstate();///
    string getstreet();//
    string getstype();//
    int getzip();
    int gethouse();
    void setfname(string);//MUTATOR METHODS
    void setlname(string);//
    void setcity(string);//
    void setstate(string);//
    void setstreet(string);//
    void setstype(string);//
    void setzip(int);//
    void sethouse(int);//
private://DATA MEMBERS
    string fname, lname, city, state, street, stype;
    int zip, house;
};
#include "customer.cpp"
#endif
