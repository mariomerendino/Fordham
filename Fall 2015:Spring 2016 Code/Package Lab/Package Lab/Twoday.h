//
//  Twoday.h
//  Package Lab
//
//  Created by Mario J Merendino on 12/7/15.
//  Copyright (c) 2015 Mario J Merendino. All rights reserved.
//

#ifndef __Package_Lab__Twoday__
#define __Package_Lab__Twoday__


#include "Package.h"
class twoday: public package{ //creates class twoday and it inherits from package
public:
    twoday();//default constructor
    void display();//displaymethod
    void input(); //input method
    void calculateCost();//calculates cost
    double getDEFAULTCOST();//accessor
    void setDEFAULTCOST();//mutator
    void stats();//stats
private:
    double DEFAULTCOST;
};
#include "Twoday.cpp"
#endif /* defined(__Package_Lab__Twoday__) */
