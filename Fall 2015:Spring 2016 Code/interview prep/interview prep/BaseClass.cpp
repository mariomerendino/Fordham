//
//  BaseClass.cpp
//  interview prep
//
//  Created by Mario J Merendino on 5/5/16.
//  Copyright © 2016 Mario J Merendino. All rights reserved.
//

#include "BaseClass.hpp"
person::person(){
    name= " ";
    age= 0;
}
person::person(person const & copy){
    name=copy.name;
    age=copy.age;
}
void person::input(){
    cout << "Enter name" <<endl;
    cin >> name;
    cout << "Enter age" <<endl;
    cin >> age;
}
void person::display(){
    cout << "Name: " << name <<endl;
    cout << "Age: " << age << endl;
}
void person::setage(int a){
    age= a;
}
void person::setname(string n){
    name=n;
}
string person::getname(){
    return name;
}
int person::getage(){
    return age;
}