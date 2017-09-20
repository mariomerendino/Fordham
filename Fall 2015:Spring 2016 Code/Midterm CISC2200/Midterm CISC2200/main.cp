#include <iostream>
#include <assert.h>
#include "DollarAmount.h"
#include "unsorted.h"

using namespace std;


void CalTotal (UnsortedType list);
int main()
{
	int d, c;
	int i=0;
	char ch;
	bool end=false;

	DollarAmount  amount;
	UnsortedType records;
        UnsortedType * p = new UnsortedType; 

	do
	{
		cout <<"Enter dollar amount:";
		cin >> amount;

		if (amount.isTerminator())
			end = true;
		else 
			records.PutItem (amount);
	
	} while (!end);

	CalTotal (records);

	CalTotal (records);

	amount = DollarAmount (100,0);
	records.PutItem(amount);
	CalTotal (records);
        delete p;
}



void CalTotal (UnsortedType list)
{
	cout <<"Display all, and adding total\n";
        cout <<list.GetLength()<<endl;
	DollarAmount total,item;
	list.ResetList();
	for (int i=0;i<list.GetLength();i++)
	{
		item = list.GetNextItem();
		cout <<"item: " <<item<<endl;
		total = total+item;
	}
	cout <<"Total amount is" << total << endl;

	
}


