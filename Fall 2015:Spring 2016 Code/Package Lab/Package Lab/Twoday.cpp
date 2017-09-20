//
//  Twoday.cpp
//  Package Lab
//
//  Created by Mario J Merendino on 12/7/15.
//  Copyright (c) 2015 Mario J Merendino. All rights reserved.
//

#include "Twoday.h"
static int numtwoday=0;
static double totaltwodayamt=0;
twoday::twoday(): package(){
    setDEFAULTCOST();
    numtwoday++;
}
void twoday::display(){
    cout << "Sender: " <<endl;
    sender.display();
    cout << "Reciever: " <<endl;
    recipient.display();
    cout << "Weight of package: " << weight <<  endl;
    cout << "Cost Per OZ: " << costperoz << endl;
    cout << "Two day fee: " << DEFAULTCOST <<endl;
    cout << "Total cost: " << totalcost <<endl ;
}
void twoday::calculateCost(){
    totalcost=DEFAULTCOST+(weight*costperoz);
    totaltwodayamt=+totalcost;
}
void twoday::setDEFAULTCOST(){
    DEFAULTCOST=9.95;
}
double twoday::getDEFAULTCOST(){
    return (DEFAULTCOST);
}
void twoday::input(){
    double w;
    cout << "Input weight in ounces: ";
    cin >> w;
    setweight(w);
    calculateCost();
}
void twoday::stats(){
    cout << "Total number of Twoday Packages: " << numtwoday<<endl;
    cout << "Total amount generated from Twoday packages: " <<totaltwodayamt<<endl;
}