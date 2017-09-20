//
//  point.hpp
//  Midterm CISC2200
//
//  Created by Mario J Merendino on 3/15/16.
//  Copyright © 2016 Mario J Merendino. All rights reserved.
//

#ifndef point_h
#define point_h
#include <iostream>
using namespace std;
class point{
public:
    point();
    point(int x, int y);
    bool IsSameAs(const point &p);
    void output();

private:
    int x_cord;
    int y_cord;
};
#endif /* point_h */
