//Date.cpp
//Mario Merendino
//Prof Papadakis
//Contains functions for date class
#include "date.h"

Date::Date(){ //default constructor
    mm=1;
    dd=1;
    yy=1900;
}
Date::Date( const Date &d ) {
    cout << "Date" << d.mm << "," << d.dd << "," << d.yy << ": " << endl;
    mm=d.mm;
    dd=d.dd;
    yy=d.yy;
}
Date::Date(int m, int d, int y){//other cosntructor
    mm=m;
    dd=d;
    yy=y;
}
void Date::display(){ //displays function
     cout << getmonth()<<"/" << getday() << "/" << getyear() << endl;
}
void Date::input(){ //inputs month day year
    int m,d,y;
    cout << "Enter date as mm, dd, yyyy"<<endl;
    cin >> m >> d >> y;
    if (m > 12 || m < 1)//checks if month is correct
    {
    while(m > 12 || m <1){
    cout << "Enter a valid month: \n";
    cin >> m;
    }}
    if (d > 31 || d < 1) // checks if day is correct
    {
    while(d > 31 || d <1){
    cout << "Enter a valid day: \n";
    cin >> d;
    }}
    setDate(m,d,y);
}
void Date::setDate(int m, int d, int y) //mutator for whole date
{
   mm=m;
   dd=d;
   yy=y;
}
int Date::getmonth(){ //ACCESSORS
   return(mm);
}
int Date::getday(){
   return(dd);
}
int Date::getyear(){
   return(yy);
}
void Date::operator++(){
    dd++;
}
void Date::setday(int d){
    dd=d;
}
void operator++(Date& d, int i){
    i=1;
    int day;
    day=d.getday();
    d.setday(day+i);
}
