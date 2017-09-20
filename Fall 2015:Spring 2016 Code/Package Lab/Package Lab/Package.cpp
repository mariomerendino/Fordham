//
//  Package.cpp
//  Package Lab
//
//  Created by Mario J Merendino on 12/7/15.
//  Copyright (c) 2015 Mario J Merendino. All rights reserved.
//


package::package(): sender("Mario", "Merendino","Threepence","Dr","Melville","NY", 8, 11747),recipient("Fordham", "University", "E.Fordham", "Rd", "Bronx", "NY", 441, 10458){
    weight=0.0;
    costperoz=5.05;
}
void package::input(){
    cout << "Input weight in ounces: ";
    cin >> weight;
    calculateCost();
}
void package::calculateCost(){
    totalcost=weight*costperoz;
}
void package::setweight(double w){
    weight=w;
}
void package::setcostperoz(double c){
    costperoz=c;
}
void package::settotalcost(double t){
    totalcost=t;
}
double package::getweight(){
    return(costperoz);
}
double package::getcostperoz(){
    return(costperoz);
}
double package::gettotalcost(){
    return(totalcost);
}
