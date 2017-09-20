#include<iostream>
#include <time.h>
#include <cstdlib>

using namespace std;
//Function Declarations...

//copys data from array 1, to array 2.
void copyArray(int[], int[], int);
//displays an array.
void displayArray(int[], int);
//input data into an array
void inputArray(int[], int);
//input random data into an array
void inputArrayRand(int[], int);
//bubble sort algorithm
void bubbleSort(int[], int);
//selection sort algorithm
void selectionSort(int[], int);
//insertion sort algorithm
void InsertionSort(int[], int);
//quick sort algorithm
void QuickSort(int a[],int start,int end);
//Partitions array, quick sort helper function
int partitionArray(int a[], int start, int end);
//Merge Sort Algorithm
void mergeSort(int a[], int start, int end);
//Merge Sort Helper function. 
void merge(int a[], int start, int midpoint, int end);
//runs all sorting algorithms on a single array
void run(int[], int);

//main functions.
int main(){
    //creates array of 20 elements. 
    int a[20];
    //inputs random numbers for that array.
    inputArrayRand(a,20);
    //runs all sorting algorithms, and checks runtimes  
    run(a,20);
    
    //creates array of 100 elements.
    int b[100];
    //inputs random numbers for that array
    inputArrayRand(b,100);
    //runs all sorting algorithms, and checks runtimes  
    run(b,100);
    
    //creates array of 200 elements
    int c[200];
    //inputs random numbers for that array
    inputArrayRand(c,200);
    //runs all sorting algorithms, and checks runtimes.
    run(c,200);
    
}
//fills an array with random numbers
void inputArrayRand(int a[], int size){
    srand (time(NULL));
    for(int i =0; i < size; i++){
        int v1 = rand() % 100;
        a[i]=v1;
    }

}
//copys all data from one array, and inputs it into another.
void copyArray(int a[], int b[], int size){
    for(int i= 0; i < size; i++){
        b[i] = a[i];
    }
}
//displays the array.
void displayArray(int a[], int size){
    for(int i= 0; i < size; i++){
        cout << a[i]<< " "; 
    }
    cout <<endl;
}

//quick Sort Algorithm.
void QuickSort(int a[],int start,int end){
    if (start < end){
        int partitionIndex = partitionArray(a, start, end);
        QuickSort(a, start, partitionIndex-1);
        QuickSort(a, partitionIndex+1, end);
        
    }
    else{
    }
}
//partitions an array. Helper function for Quick sort. 
int partitionArray(int a[], int start, int end){
    int pivot = a[end];
    int pIndex = start;
    int temp;
    for (int i = start; i < end; i++){
        if (a[i] <= pivot){
            temp = a[pIndex];
            a[pIndex] = a[i];
            a[i] = temp;
            pIndex++;
        }
    }
    temp = a[pIndex];
    a[pIndex] = a[end];
    a[end] = temp;
    return pIndex;
}
//Selection Sort Algorithm
void selectionSort(int a[], int size){
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
        int temp;
        temp = a[startIndex];
        a[startIndex] = a[smallestIndex];
        a[smallestIndex] = temp; 
    }

}
//Bubble Sort Algorithm.
void bubbleSort(int a[], int size){
    for (int n=0; n <size; n++){
        for (int i=0; i <size; i++){
            if(a[i]> a[i+1]){
                int temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
            }
        }
    }
}
//Insertion Sort Algorithm
void InsertionSort(int a[], int size){
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
//Merge Sort Algorithm
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
//Mergesort helper function
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
//Run function. Runs All algorithms, and gets runtimes.
void run(int a[], int size){   

    cout << "\nRun time of Sorting Algorithms for an Array of size: " << size << endl;
    //Time Variables
    time_t start, end, diff;
    //Displays the current array
    displayArray(a,size);
    //Creates a copy of the array that was previously created, one for each sorting Algorithm.
    int bubbleSortArray[size];
    int selectionSortArray[size];
    int insertionSortArray[size];
    int mergeSortArray[size];
    int quickSortArray[size];
    copyArray(a, bubbleSortArray, size);
    copyArray(a, selectionSortArray, size);
    copyArray(a, insertionSortArray, size);
    copyArray(a, mergeSortArray, size);
    copyArray(a, quickSortArray, size);

    //Starts clock.
    start = clock();
    //runs bubble sort.
    bubbleSort(bubbleSortArray,size);
    //ends clock.
    end = clock();
    cout << "Bubble Sort Runtime: " << (double)(end - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
    
    //starts clock
    start = clock();
    //runs selection sort
    selectionSort(selectionSortArray, size);
    //ends clock
    end = clock();
    cout << "Selection Sort Runtime: " << (double)(end - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
    
    //starts clock
    start = clock();
    //runs insertion sort
    InsertionSort(insertionSortArray, size);
    //ends clock
    end = clock();
    cout << "Insertion Sort Runtime: " << (double)(end - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
    
    //starts clock
    start = clock();
    //runs merge Sort
    mergeSort(mergeSortArray,0, size);
    //ends clock
    end = clock();
    cout << "Merge Sort Runtime: " << (double)(end - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
    
    //starts clock
    start = clock();
    //runs quick sort
    QuickSort(quickSortArray,0, size);
    //ends clock
    end = clock();
    cout << "Quick Sort Runtime: " << (double)(end - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
    displayArray(quickSortArray, size);
}