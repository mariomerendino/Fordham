#include <iostream>
#include <fstream>
#include "unsorted.h"

using namespace std;

int main(){

	UnsortedType list;
	int d;
	
	do{
		cout << "Enter a positive int or -1: ";
		cin >> d;
		if(d>0){
			ItemType t;
			t.Initialize(d);

			list.PutItem(t);
		}
	} while (d>0 && !list.IsFull());
	ItemType total;
	list.ResetList();
	int length=list.GetLength();
	for (int i=0; i<length; i++){
		ItemType t= list.GetNextItem();
		total= total+t;	
	}
	total.Print(cout);
}
