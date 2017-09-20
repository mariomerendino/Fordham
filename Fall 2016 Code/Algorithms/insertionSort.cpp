//Mario J. Merendino
//Professor Hsu
//Computer Algorithms
//06 October 2016

#include <iostream>
using namespace std;

//Funcion Prototypes 
void insertionSort(int[], int);
void displayArray(int[], int);
void mergeSort(int[], int, int);
void merge(int[], int, int, int);
void insertIntoArray(int a[], int& size);

//main function
int main(){
    //maximum size of the arrays
    const int maxSize = 25;

    //declares the two arrays. 
    int a[maxSize];
    int b[maxSize];
    int c[maxSize];
    int d[maxSize];
    int e[maxSize];

    //Size of the two arrays.
    int aSize = 0;
    int bSize = 0;
    int cSize = 0;
    int dSize = 0;
    int eSize = 0;

    //checks if the user inputs 0 to exit the program.
    bool finished = false;

    //User input for deciding what function they would like to use. 
    int choice;

    //loops until finished == true.
    while(finished == false){
        cout << "What would you like to do?\n\t1) Insert into array A\n\t2) Insert into array B";
        cout << "\n\t3) Insert into array C \n\t4) Insert into array D\n\t5) Insert into array E";
        cout << "\n\t6) Display Arrays \n\t7) insertionSort\n\t8) mergeSort \n\t0) Quit\n:";
        cin >> choice;
        cout << endl;
        switch(choice){
            //input into array a
            case 1:
                insertIntoArray(a, aSize);
                break;
            //input into array b
            case 2:
                insertIntoArray(b, bSize);
                break;
            //input into array c
            case 3:
                insertIntoArray(c, cSize);
                break;
            //input into array d
            case 4:
                insertIntoArray(d, dSize);
                break;
            //input into array e
            case 5:
                insertIntoArray(e, eSize);
                break;
            //display array a
            case 6:
                cout << "Displaying Array A...\n";
                displayArray(a, aSize);
                cout << "Displaying Array B...\n";
                displayArray(b, bSize);
                cout << "Displaying Array C...\n";
                displayArray(c, cSize);
                cout << "Displaying Array D...\n";
                displayArray(d, dSize);
                cout << "Displaying Array E...\n";
                displayArray(e, eSize);
                break;
            //insertion sort to all arrays
            case 7:
                insertionSort(a, aSize);
                insertionSort(b, bSize);
                insertionSort(c, cSize);
                insertionSort(d, dSize);
                insertionSort(e, eSize);
                break;
            //merge sort to all arrays.
            case 8:
                mergeSort(a, 0, aSize-1);
                mergeSort(b, 0, bSize-1);
                mergeSort(c, 0, cSize-1);
                mergeSort(d, 0, dSize-1);
                mergeSort(e, 0, eSize-1);
                break;
            //quit
            case 0:
                finished = true;
                break;
            default:
                cout << "ERROR: Incorrect Input\n";
                break;
        }
    }
}
void insertIntoArray(int a[], int& size){
    cout << "How many numbers do you want to input?";
    int num;
    cin >> num;
    cout << endl;
    for (int i = 0; i < num; i++){
        cout << ":";
        cin >> a[i];
    }
    size = num;
}
void insertionSort(int a[], int size){
    int i, key;
    for(int j(1); j < size; j++){    // Start with 1 (The second number in the array.
    key = a[j]; //set that equal to the key
        for(i = (j - 1); (i >= 0) && (a[i] > key); i--){ // larger values move up in the array
            a[i+1] = a[i];
        }
        a[i+1] = key;    //Put key into its proper location
     }
     
     return;
}
void mergeSort(int a[], int start, int end){
    //recursive function base case. 
    if (start >= end){
        return;
    }
    else{
        int midpoint = ((start+ (end-1)) / 2);
        //calls the function on its self from start -> midpoint
        mergeSort(a, start, midpoint);
        //calls the function on its self from midpoint -> end
        mergeSort(a, midpoint + 1, end);
        //merges the entire array.
        merge(a, start, midpoint, end);
    }    
}
void merge(int a[], int start, int midpoint, int end){
    
    int x = midpoint - start + 1;
    int y = end - midpoint;

    // create temporary arrays 
    int b[x];
    int c[y];

 
    // Copy data to temporary arrays
    for (int m = 0; m < x; m++)
        b[m] = a[start + m];
    for (int n = 0; n < y; n++)
        c[n] = a[midpoint + 1+ n];
 
    //Merge the two arrays together. 
    int i = 0; // Initial index of first subarray
    int j = 0; // Initial index of second subarray
    int k = start; // Initial index of merged subarray
    while (i < x && j < y)
    {
        if (b[i] <= c[j]) // if b[i] is smaller than c[j], a[] will take B's value.
        {
            a[k]= b[i];
            i++;
        }
        else  // if c[j] is smaller than b[i], a[] will take B's value.
        {
            a[k] = c[j];
    
            j++;
        }
        k++;
    }
 
    //Copy the remaining elements of b[], if there are any 
    while (i < x) 
    {
        a[k] = b[i];
        i++;
        k++;
    }
 
    //Copy the remaining elements of c[], if there are any
    while (j < y)
    {
        a[k] = c[j];
        j++;
        k++;
    }
}
void displayArray(int a[], int size){
    for (int i = 0; i < size; i++){
        cout << a[i] <<  " ";
    }
    cout << endl << endl;

}
