//
//  BaseClass.hpp
//  interview prep
//
//  Created by Mario J Merendino on 5/5/16.
//  Copyright © 2016 Mario J Merendino. All rights reserved.
//

#ifndef BaseClass_hpp
#define BaseClass_hpp

#include <iostream>
using namespace std;
class person{
public:
    person();
    person(person const &);
    void display();
    void input();
    string getname();
    void setname(string);
    int getage();
    void setage(int);
protected:
    int age;
    string name;
};
#endif /* BaseClass_hpp */
