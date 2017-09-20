/*
 Driver File
 Author: Mario J. Merendino
 Professor Zhang
 Last Modified: Feb 23, 2016
 Known bug: None
 */
#include <iostream>
#include "unsorted.h"
int main()
{
    UnsortedType data;
    ItemType dollar;
    
    do{
        cout << "Enter the expenditure record (ex $5.95, enter -1.00 to end):";
        cin >> dollar;
        data.PutItem(dollar);
    } while ( dollar.getdollar() != dollar.getDELIM());
    cout <<"\nList of Expenditures:\n";
    data.bubblesort();
    data.output();
    ItemType sum= data.sum();
    cout << "The total is: " << sum<< "(";
    sum.PrintInEnglish();
    data.largestindex();
    cout << ")\nYour largest expense is: " << data.LargestItem()<<endl;
    data.median();

}