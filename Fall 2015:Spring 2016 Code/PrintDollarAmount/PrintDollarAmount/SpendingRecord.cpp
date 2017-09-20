//
//  SpendingRecord.cpp
//  PrintDollarAmount
//
//  Created by Mario J Merendino on 1/29/16.
//  Copyright © 2016 Mario J Merendino. All rights reserved.
//

#include "SpendingRecord.h"
SpendingRecord::SpendingRecord(){
    desc= "Coffee";
}
void SpendingRecord::display(ostream &os){
    os << d << " " << desc;
}
void SpendingRecord::input(istream &os){
    os >> d >> desc;
}
Dollar SpendingRecord::getdollar(){
    return d;
}