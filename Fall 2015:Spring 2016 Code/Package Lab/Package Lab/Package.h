//
//  Package.h
//  Package Lab
//
//  Created by Mario J Merendino on 12/7/15.
//  Copyright (c) 2015 Mario J Merendino. All rights reserved.
//

#ifndef __Package_Lab__Package__
#define __Package_Lab__Package__

#include "customer.h"
class package{
public:
    package();//Default constructor
    void input();//input method
    void setweight(double);//Mutator methods
    void setcostperoz(double);
    void settotalcost(double);
    void calculateCost();//calculates cost
    double getweight();///accessor methods
    double getcostperoz();
    double getprecost();
    double gettotalcost();
protected:
    customer sender, recipient;
    double weight, costperoz, totalcost;
};
#include "Package.cpp"

#endif /* defined(__Package_Lab__Package__) */
