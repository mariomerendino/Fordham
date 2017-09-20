//
//  Overnight.h
//  Package Lab
//
//  Created by Mario J Merendino on 12/7/15.
//  Copyright (c) 2015 Mario J Merendino. All rights reserved.
//

#ifndef __Package_Lab__Overnight__
#define __Package_Lab__Overnight__

#include <stdio.h>
#include "Package.h"
class overnight: public package{//creates overnight class, inherits from package
public:
    overnight();//default constructor
    void display();//display method
    void input();//input method
    void setDEFAULTRATE();//mutator
    double getDEFAULTRATE();//accessor
    void calculateCost();//calculates cost
    void stats();//outputs total amount of packages.
private:
    double DEFAULTRATE;
};
#include "Overnight.cpp"
#endif /* defined(__Package_Lab__Overnight__) */
