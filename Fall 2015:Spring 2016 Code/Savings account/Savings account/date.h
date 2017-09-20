#ifndef DATE_H
#define DATE_H
#include <iostream>
using namespace std;

class Date{
    friend ostream &operator<<(ostream &, Date*&);
public://prototypes
    Date();//default constructor
    Date(int,int,int);
    Date( const Date & ); // copy constructor
    void input();//input funct
    void display();//display funct
    void setDate(int,int,int);
    void setday(int);
    int getmonth();//accessors
    int getday();
    int getyear();
    void setyear(int);
    Date operator++();

private:
    int mm,dd,yy;
};
#endif 
