#include <iostream>
#include "DollarAmount.h"
using namespace std;

#ifndef SPENDRECORD_H
#define SPENDRECORD_H

/* class declaration */
class SpendRecord:public DollarAmount
{
public:
	SpendRecord (int dollar=0, int cent=0, string des=""): DollarAmount (dollar,cent),description(des)
	{
		//empty
	}

	SpendRecord (DollarAmount d):DollarAmount (d)
	{
	}
	
	string GetDescription()
	{
		return description;
	}

	virtual void print(ostream & stream) const;
        virtual void input (istream & stream); 



	friend istream & operator>> (istream & input, SpendRecord & obj);
	friend ostream & operator << (ostream & output, const SpendRecord & obj);

private:
	string description;
};
#endif
