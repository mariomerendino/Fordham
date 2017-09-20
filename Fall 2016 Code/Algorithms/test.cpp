#include <iostream>
using namespace std;

void displayCharArray(char[], int);
void displayIntArray(int a[], int size);
int main(){

    //Prompts user to input to string
    string input;
    cout << "Input a string: ";
    cin >> input;

    char arrayOfChars[25];
    int arrayOfInts[25];

    int arrayIndex=0;
    int numCount=0;

    bool exists = false;

    for (int i=0; i < input.size(); i++ ){        
        for (int x=0; x < arrayIndex; x++){
            if(input[i] == arrayOfChars[x]){
                exists = true;
            }
        }
        
        if(!exists){
            arrayOfChars[arrayIndex] = input[i];
            arrayOfInts[arrayIndex] = numCount;
            arrayIndex++;
            numCount = 0;            
        }
        exists = false;
    }


    displayCharArray(arrayOfChars, arrayIndex);
    displayIntArray(arrayOfInts, arrayIndex);

}
void displayCharArray(char a[], int size){
    for (int i = 0; i < size; i++){
        cout << a[i] <<  " ";
    }
    cout << endl << endl;

}
void displayIntArray(int a[], int size){
    for (int i = 0; i < size; i++){
        cout << a[i] <<  " ";
    }
    cout << endl << endl;

}