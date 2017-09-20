
/*
 main.cpp: Contains the main function. 
 Prints out a dollar amount in english
 Author: Mario J. Merendino
 Professor Zhang
 Last Modified: Jan 26, 2016
 Known bug: None
 */
template<class T>
void sort(T a[], int size);
#include <iostream>
#include "DollarAmount.h"
#include "DollarAmount.cpp"
//function Declarations
Dollar sum(Dollar a[], int size);
void median(Dollar a[], int size);
void copy(Dollar a[], Dollar b[], int size);

int main(){
    int DEFAULTSIZE(10), size(0); //Creates variables for default size, and size of the array
    bool stop=false;
    Dollar* ptr=NULL; //Creates a pointer of dollar amounts
    ptr= new Dollar[DEFAULTSIZE]; //creates an array of type dollar DYNAMICALLY
    do{
        cout << "Enter the dollar amount of the Item (e.g. $1.50,  enter -1.00 to end):$";
        cin >> ptr[size]; //user input
        if (ptr[size].getdollar()==-1){ //stops the loop if -1
            stop=true;
        }
        else{
            size++; //increases size of array
        }
        if (size==DEFAULTSIZE){ //if the user enters more than the default amount
            Dollar *temp= new Dollar[2*size]; //it creates an array thats double the size of the last
            copy(temp, ptr, size); //copies the array
            delete[]ptr; //deletes old ptr
            ptr=temp;
        }
    }while(!stop);
    sort(ptr, size); // sorts them in least to greatest
    for (int x=0; x<size; x++){
        cout << ptr[x] << endl; // displays it
    }
    Dollar s;
    s=sum(ptr, size); //total sum of the array
    cout << "Your total today is:" << s << " ("; //displays total
    s.PrintInEnglish(); //prints the total in english
    cout << ")" <<endl;
    median(ptr, size);
}
template<class T>
void sort(T a[], int size){ //bubble sort function
    int last(size-1);
    for(int x=0; x<size; x++){
        for(int i=0;i<last;i++){
            if(a[i] > a[i+1]){
                T temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
            }
        }
    }
}
Dollar sum(Dollar a[], int size){ // calculates the sum of the Array of dollars
    Dollar sum;
    for(int x=0; x<size; x++){
        sum=sum+a[x];
    }
    return(sum);
}
void median(Dollar a[], int size){ // calculates the median of the array
    int median;
    if(size%2==!0){
        median= size/2;
        cout << "The median is " << a[median] <<endl;
    }
    else{
        median= size/2;
        Dollar m;
        m= a[median]+a[median-1];
        m= m/2;
        cout << "The median is " << m <<endl;
    }
}
void copy(Dollar a[], Dollar b[], int size){ // copy function, copies contents of array b to array a.
    for(int x=0; x<size; x++){
        a[x]=b[x];
    }
}
  