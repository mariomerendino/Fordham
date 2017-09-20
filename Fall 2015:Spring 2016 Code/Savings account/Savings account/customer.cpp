//
//  person.cpp
//  Package Lab
//
//  Created by Mario J Merendino on 12/7/15.
//  Copyrigh t (c) 2015 Mario J Merendino. All rights reserved.
//
#include "customer.h"
customer::customer(){
    fname="Mario";
    lname="Merendino";
}
customer::customer(string f,string l,string s,string t,string c,string st,int h,int z){
    fname=f;
    lname=l;
    house=h;
    street=s;
    stype=t;
    city=c;
    state=st;
    zip=z;
}
void customer::input(){
    cin >> fname;
    cin >> lname;
    /*cout << "Enter the users house number: ";
    cin >> house;
    cout << "Enter the users street name: ";
    cin >> street;
    cout << "Enter the kind of street (dr, ln, st, ave...)";
    cin >> stype;
    cout << "Enter the users city: ";
    cin >> city;
    cout << "Enter the users state: ";
    cin >> state;
    cout << "Enter the users zip: ";
    cin >> zip;*/
}
void customer::display(){
    cout << fname << " " << lname;
}
string customer::getfname(){
    return(fname);
}
string customer::getlname(){
    return(lname);
}
string customer::getstate(){
    return(state);
}
string customer::getcity(){
    return(city);
}
string customer::getstype(){
    return(stype);
}
string customer::getstreet(){
    return(street);
}
int customer::getzip(){
    return(zip);
}
int customer::gethouse(){
    return(house);
}
void customer::setfname(string f){
    fname=f;
}
void customer::setlname(string l){
    lname=l;
}
void customer::setstate(string s){
    state=s;
}
void customer::setcity(string c){
    city=c;
}
void customer::setstreet(string s){
    street=s;
}
void customer::setstype(string t){
    stype=t;
}
void customer::setzip(int z){
    zip=z;
}
void customer::sethouse(int h){
    house=h;
}