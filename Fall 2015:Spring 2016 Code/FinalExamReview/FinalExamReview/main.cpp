//
//  main.cpp
//  FinalExamReview
//
//  Created by Mario J Merendino on 5/10/16.
//  Copyright © 2016 Mario J Merendino. All rights reserved.
//

#include <iostream>
using namespace std;
template <typename T>
void bubblesort(T a[], int size){
    for (int n=0; n <size; n++){
        for (int i=0; i <size; i++){
            if(a[i]> a[i+1]){
                T temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
            }
        }
    }
}
void selectionsort (int a[], int size)
{
    for (int startIndex = 0; startIndex < size; ++startIndex)
    {
        // smallestIndex is the index of the smallest element we've encountered so far.
        int smallestIndex = startIndex;
        
        // Look for smallest element remaining in the array (starting at startIndex+1)
        for (int currentIndex = startIndex + 1; currentIndex < size; ++currentIndex)
        {
            // If the current element is smaller than our previously found smallest
            if (a[currentIndex] < a[smallestIndex])
                // This is the new smallest number for this iteration
                smallestIndex = currentIndex;
        }
        
        // Swap our start element with our smallest element
        std::swap(a[startIndex], a[smallestIndex]);
    }
}
void reverseorder(int a[], int size){
    int end=size-1;
    for (int i=0; i < size/2; ++i){
        int temp= a[i];
        a[i]=a[end-i];
        a[end-i]=temp;
    }
}
void display(int a[], int size){
    for (int i=0; i < size; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}
void merge(int a[], int b[], int sizea, int sizeb){
    int c[sizea+sizeb];
    int i(0),j(0),k(0);
    while (k != (sizea+sizeb)){
        if(a[i]>b[j]){
            c[k]=b[j];
            j++;
        }
        else{
            c[k]=a[i];
            i++;
        }
        k++;
    }
    for (int x=0; x < sizea+sizeb; x++){
        cout << c[x] << " ";
    }
    cout << endl;
}
int factorial(int num){
    if (num<=1){
        return 1;
    }
    else{
        int temp= num* factorial(num -1);
        return temp;
    }
    
}
int main() {
    int a[6]={5,7,2,3,9,4};
    int b[5]={1,3,7,9,12};
    merge(a, b, 5, 5);
    cout << "Enter a Number: ";
    int num;
    cin >> num;
    cout << "Factorial: " <<factorial(num) <<endl;
}
