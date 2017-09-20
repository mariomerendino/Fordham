//
//  SpendingRecord.hpp
//  PrintDollarAmount
//
//  Created by Mario J Merendino on 1/29/16.
//  Copyright © 2016 Mario J Merendino. All rights reserved.
//

#ifndef SpendingRecord_h
#define SpendingRecord_h
#include "DollarAmount.h"
#include "DollarAmount.cpp"
#include <iostream>
class SpendingRecord{
friend ostream &operator<<( ostream &os,SpendingRecord& a){
    a.display(os);
    return(os);
}
friend istream &operator>>( istream &os, SpendingRecord& a){
    a.input(os);
    return(os);
}
public:
    SpendingRecord();
    void display(ostream& );
    void input(istream& );
    Dollar getdollar();
private:
    Dollar d;
    string desc;
};

#endif /* SpendingRecord_h*/
