//  File Name: Lab10.cpp
//  Author: Mario J Merendino
//  Professro George K. Chan
//  Desc: Program that fills array, displays the arrray, and finds min and max.
//  Last Modified: 03 May 2015

#include <iostream>
using namespace std;
void fillArray(int a[], int size, int& num_used);
void displayArray(int a[], int num_used);
void find_max_min (int a[], int num_used, int& max_index, int& min_index);

int main()
{
    const int ARRAY_SIZE=20;
    int a[ARRAY_SIZE];
    int num=0;
    int x=-1, y=-1;
    
    fillArray(a, ARRAY_SIZE, num);
    cout << "Now display array that has just been entered:\n";
    displayArray(a, num);
    
    find_max_min(a, num, x, y);
    cout << "\n Now display the max value in array a: \n";
    cout << x << " first appears at index " << a[x];
    cout << "\nNow display the min value in array a:\n";
    cout << y << " first appears at index " << a[y] <<endl;
    
}
void fillArray(int a[], int size, int& num_used)
{
    cout << "Please enter up to 20 non-negative intergers (End with a negative number) \n"; //Prompt to input
    int next;
    int index = 0;
    cin >> next;
    while (next > 0)
    {
        a[index++] = next;
        if (index >= size)
        {
            break;
        }
        cin >> next;
    }
    num_used = index;
}
void displayArray(int a[], int num_used)
{
    for (int n=0; n < num_used; n++) //Displays
    {
        cout << a[n] << " ";
    }
    cout << endl;
}
void find_max_min (int a[], int num_used, int& max_index, int& min_index)
{
    int i=0;
    max_index=a[i];
    min_index=a[i];
    for(i=1;i<num_used;i++)
    {
        if(a[i]<min_index)
            min_index=a[i];
        if(a[i]>max_index)
            max_index=a[i];
    }
}
