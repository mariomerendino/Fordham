//
//  point.cpp
//  Midterm CISC2200
//
//  Created by Mario J Merendino on 3/15/16.
//  Copyright © 2016 Mario J Merendino. All rights reserved.
//

#include "point.h"
point::point(){
    x_cord=0;
    y_cord=0;
}
point::point(int x, int y){
    x_cord=x;
    y_cord=y;

}
bool point::IsSameAs(const point &p){
    bool ret;
    if(p.x_cord==x_cord && p.y_cord==y_cord){
        ret=true;
    }
    else{
        ret=false;
    }
    return ret;
}
void point::output(){
    cout << "(" << x_cord << "," << y_cord << ")" << endl;
}
int main(){
    point p1(2,3), p2(2,4);
    if (p1.IsSameAs(p2)){
        cout << "p1 is same as p2" <<endl;
    }
    else{
        cout << "They're not the same" << endl;
    }
    p2.output();
}