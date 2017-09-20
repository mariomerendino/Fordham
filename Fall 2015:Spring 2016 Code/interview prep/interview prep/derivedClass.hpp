//
//  derivedClass.hpp
//  interview prep
//
//  Created by Mario J Merendino on 5/5/16.
//  Copyright © 2016 Mario J Merendino. All rights reserved.
//

#ifndef derivedClass_hpp
#define derivedClass_hpp

#include <iostream>
#include "BaseClass.cpp"
using namespace std;
class student: public person{
public:
    student();
    student(student const &);
    void input();
    void display();
protected:
    string major;
};

#endif /* derivedClass_hpp */
