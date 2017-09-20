//
//  Overnight.cpp
//  Package Lab
//
//  Created by Mario J Merendino on 12/7/15.
//  Copyright (c) 2015 Mario J Merendino. All rights reserved.
//

#include "Overnight.h"
static int numovernight=0;
static double totalovernightamt=0;
overnight::overnight(): package(){
    setDEFAULTRATE();
    numovernight++;
}
void overnight::display(){
    cout << "Sender: " <<endl;
    sender.display();
    cout << "Reciever: " <<endl;
    recipient.display();
    cout << "Weight of package: " << weight <<  endl;
    cout << "Cost Per OZ: " << costperoz << endl;
    cout << "Overnight Rate: " << DEFAULTRATE <<endl;
    cout << "Total cost: " << totalcost <<endl ;
}
void overnight::calculateCost(){
    totalcost= (DEFAULTRATE*weight)+(costperoz*weight);
    totalovernightamt=+totalcost;
}
void overnight::setDEFAULTRATE(){
    DEFAULTRATE=1.75;
}
double overnight::getDEFAULTRATE(){
    return (DEFAULTRATE);
}
void overnight::input(){
    double w;
    //sender.input();
    //recipient.input();
    cout << "Input weight in ounces: ";
    cin >> w;
    setweight(w);
    calculateCost();
}
void overnight::stats(){
    cout << "Total number of overnight Packages: " << numovernight<<endl;
    cout << "Total amount generated from overnight packages: " <<totalovernightamt<<endl;
}
