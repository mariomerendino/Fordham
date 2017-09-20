/*
cpp. file, contains methods for Dollar Class
Prints out a dollar amount in english
Author: Mario J. Merendino
Professor Zhang
Last Modified: Feb 23, 2016
Known bug: None
*/

#include <iostream>
#include <assert.h>
#include <sstream>
#include "DollarAmount.h"

using namespace std;

void DollarAmount::print(ostream & stream) const
{
	stream <<dollar<<"."<<cent;
}

void DollarAmount::input (istream & stream)
{

	int d, c;
	char ch;
	bool success=false;

	do {
		stream >> d>> ch >> c;
		if (stream.fail()){
			cout <<"failed to enter\n";
			stream.clear();
			stream.ignore (2048,'\n');
		} else {
			if (d<-1 || c<0 || c>99)
				cout <<"Value not in range\n";
			else
				success=true;
		}
		if (!success)	
			cout <<"try again\n";
	} while (!success);

	dollar = d;
	cent = c;
}



//a friend function is not a member function
istream & operator >> (istream & in, DollarAmount & d)
{
	d.input (in);
	return in;
}

ostream & operator<< (ostream & out, const DollarAmount & d)
{
	d.print (out);
	return out;
}


/* postcondition: the dollar amount represented by 
	the calling object is displayed in English */
void DollarAmount::PrintInEnglish()
{
	PrintDollar(dollar);

	if (cent!=0)
	{
		cout <<" and " << cent <<"%100";
	}

}



/* some helper function to be used by PrintInEnglish */

void DollarAmount::PrintDollar (int d)
{
	assert (d>=0 && d<=9999);

	int hundreds = d/100;
	Print0_99 (hundreds);
	cout <<" hundred ";

	int remaining = d%100;
	if (remaining!=0)
	{
		Print0_99 (remaining);
	}
}

/* precondition: value>=0, value <=99 */
void DollarAmount::Print0_99 (int value)
{
	int tens=value/10;
	int ones=value%10;

	if (tens==0)
	{
		PrintOnes (ones);
	} else if (tens==1)
	{
		PrintTeens (ones);
	}
	else 
	{
		PrintTens (tens);
		cout <<" ";
		PrintOnes (ones);
	}
}

/* display ten, twenty, ..., nighty 
@param ten_digit: is the tenth digit's value
@precondition: ten_digit has a value from 1 to 9
@postcondition: ...
*/
void DollarAmount::PrintTens (int ten_digit)
{
   string name[10]={"","ten","twenty","thirty","forty","fifty",
		"sixty","seventy","eighty","ninety"};

   assert (ten_digit>=0 && ten_digit<=9);
   cout <<name[ten_digit];
}

void DollarAmount::PrintOnes (int one_digit)
{
   string name[10]={"zero","one","two","three","four","five",
		"six","seven","eight","nine"};

   assert (one_digit>=0 && one_digit<=9);
   cout <<name[one_digit];

}
	
/* display eleven, ... nineteen 
@param one_digit: the one-th digit
@precondition: one_digit has a value from 1, 2, ...,9
@postcondition: ... */
void DollarAmount::PrintTeens (int one_digit)
{
   string name[10]={"ten","eleven","twelve","thirteen","forteen","fifteen",
		"sixteen","seventeen","eighteen","nineteen"};

   assert (one_digit>=0 && one_digit<=9);
   cout <<name[one_digit];
}
bool operator>(DollarAmount &d, DollarAmount &d1){ //Operator overload >
    bool ret=false; //return value
    if(d.dollar > d1.dollar){ //if d1 > d2 it returns true
        ret=true;
    }
    if(d.dollar == d1.dollar){
        if (d.cent > d1.cent){
            ret=true;
        }
    }
    return ret;
}
bool operator<(DollarAmount &d, DollarAmount &d1){
    bool ret=true;
    if(d > d1){
       ret=false;
    }
    if(d==d1){
       ret=false;
    }
    return ret;
}
bool operator==(DollarAmount &d, DollarAmount &d1){
   bool ret=false;
   if(d.dollar==d1.dollar && d.cent==d1.cent){
      ret=true;
   }
   return ret;
}
DollarAmount operator+(DollarAmount &d1, DollarAmount &d2){ //Operator Overload for +
    DollarAmount d3;
    d3.dollar=d1.dollar+d2.dollar; //adds dollars together
    d3.cent=d1.cent+d2.cent;//adds cents together
    if(d3.cent > 100){ //if cents are greater than 100, it adds 1 to the dollar amount
        d3.cent= d3.cent-100;
        d3.dollar= d3.dollar+1;
    }
    return d3;
}
DollarAmount operator/(DollarAmount &d1, int x){ //operator overload for division of a dollar and an integer
    DollarAmount d2;
    d2.dollar=d1.dollar/x; //divides dollars
    d2.cent=d1.cent/x; //divides cents
    if(d1.cent==0){
        d2.cent=50;
    }
    return d2;
}

int DollarAmount::getDELIM(){
    return (DELIM);
}
int DollarAmount::getdollar(){
    return (dollar);
}
