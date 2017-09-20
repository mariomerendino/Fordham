//
//  stack.hpp
//  FinalExamReview
//
//  Created by Mario J Merendino on 5/12/16.
//  Copyright © 2016 Mario J Merendino. All rights reserved.
//

#ifndef stack_hpp
#define stack_hpp

#include <iostream>
using namespace std;
class stack{
public:
    stack();
    void push(int);
    int top() const;
    void pop();
    bool isEmpty() const;
    void MakeEmpty();
private:
    int s[10];
    int topindex=-1;
};

#endif /* stack_hpp */
