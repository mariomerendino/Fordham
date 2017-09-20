/* class definition for DollarAmount
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
		stream >> d;
		if (stream.fail()){
			cout <<"failed to enter\n";
			stream.clear();
			stream.ignore (2048,'\n');
		} else {
			if (d==-1)
			{	//terminator 
				dollar = -1;
				cent = 0;

				return;
			}
			stream >> ch >> c;
			if (d<0 || c<0 || c>99)
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

bool DollarAmount::isTerminator() const
{
	return (dollar==-1 && cent==0);
}

//a friend function is not a member function
istream & operator >> (istream & in, DollarAmount & d)
{
/*
	int dollar, cent;
	char ch;
	bool success=false;

	do {
		in >> dollar >> ch >> cent;
		if (in.fail()){
			cout <<"failed to enter\n";
			in.clear();
			in.ignore (2048,'\n');
		} else {
			if (dollar<0 || cent <0 || cent>99)
				cout <<"Value not in range\n";
			else
				success=true;
		}
		if (!success)	
			cout <<"try again\n";
	} while (!success);

	d.dollar = dollar;
	d.cent = cent;
*/
	d.input (in);
	return in;
}

ostream & operator<< (ostream & out, const DollarAmount & d)
{
	d.print (out);
	return out;
}

/* comparing calling object with op2 */
bool DollarAmount::operator> (DollarAmount & op2) const
{
	if (dollar>op2.dollar)
		return true;
	else if (dollar<op2.dollar)
		return false;
	else if (cent>op2.cent)
		return true;
	else
		return false;
}

bool operator== (const DollarAmount & left, const DollarAmount & right)
{
	return (left.dollar == right.dollar & 
		left.cent==right.cent);
}

DollarAmount DollarAmount::operator+ (const DollarAmount & right)  const
{
	DollarAmount sum;

	sum.dollar = dollar + right.dollar + (cent+right.cent)/100;
	sum.cent = (cent+right.cent)%100;
	return sum;

}

DollarAmount DollarAmount::operator/ (int divisor)  const
{
	DollarAmount result;

	result.dollar = dollar/divisor;
	result.cent = ( (dollar%divisor)*100
			+cent )/divisor; 
	return result;
}



/* postcondition: the dollar amount represented by 
	the calling object is displayed in English */
void DollarAmount::PrintInEnglish()
{
	PrintDollar(dollar);

	if (cent!=0)
	{
		cout <<" and " << cent <<"%100"<<endl;
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
		cout <<" and ";
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

