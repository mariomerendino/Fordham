/* A bunch of sorting and search functions */

#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

void GenerateRandomArray (int a[], int size)
{
	for (int i=0;i<size;i++)
		a[i] = rand()%10000; //value ranging from 0 to 9999
}

void CopyArray (int a[], int b[], int size)
{
	for (int i=0;i<size;i++)
		a[i] = b[i];
}

/*predoncidtion: a1 of length "len1" is sorted, a2 of length "len2" is sorted
 * store theire values into array a, so that a is sorted */
void MergeSortedArray (int a1[], int len1, int a2[], int len2, int a[], int len)
{
    int i1=0,i2=0,i=0;
    while(i1 <=len1 && i2<=len2){
        if(a1[i1] < a2[i2]){
            a[i]=a1[i1];
            i++;
            i1++;
        }
        else{
            a[i]=a2[i2];
            i++;
            i2++;
        }
    }
}

template <class ItemType>
void SelectionSort (ItemType a[], int size)
{
     int largestIndex;
     int rightEnd;
     ItemType tmp;

     //counting number of comparison operation 
     int CompOpCnt=0;
     int SwapOpCnt=0;

     rightEnd = size-1;

     for (int pass=0;pass<size-1;pass++)
     {
	//find the index of the largest element in a[0]...a[rightEnd]
	largestIndex = 0;
        for (int j=1; j<=rightEnd; j++)
	{
		CompOpCnt++;
		if (a[j]>a[largestIndex])
			largestIndex = j;
	}

	//if the largest element is not in the rightEnd, excahnge them 
	if (largestIndex!=rightEnd)
	{
		SwapOpCnt++;

		tmp = a[largestIndex];
		a[largestIndex] = a[rightEnd];
		a[rightEnd] = tmp;
	}
	rightEnd--;
     }

     cout <<"SelectionSort(size="<<size<<"):comparison: " << CompOpCnt;
     cout << ";	swap " << SwapOpCnt <<endl;
}

template <class ItemType>
void sort (ItemType a[], int size)
{
     ItemType tmp;
     int rightEnd=size-1; //a[0]...a[rightEnd] is unsorted
     
     //counting number of comparison operation 
     int CompOpCnt=0;
     int SwapOpCnt=0;

	for (int pass=0;pass<size-1;pass++)
	{
		//in each pass, compare adjacent pairs and swap
		//  move largest number to the right...
		for (int i=0;i<rightEnd-1;i++)
		{
			CompOpCnt++;

			if (a[i]>a[i+1])
			{
				SwapOpCnt++;

				tmp = a[i];
				a[i] = a[i+1];
				a[i+1] = tmp;
			}
		}
		rightEnd--; //a[rightEnd] does nto need to be touched...
	}

     cout <<"BubbleSort (size="<<size<<"):	comparison: " << CompOpCnt;
     cout << ";	swap " << SwapOpCnt <<endl;
	
}

/* linear search */
/* return -1 if not found */
template <class ItemType>
int Search (ItemType a[], int size, ItemType search){
    int count=0;
    for (int i=0; i<=size; i++){
        if(a[i]==search){
            
            cout << "Number of comparisons: " << count << endl;
            return i;
        }
        count ++;
    }
    return -1;

}

/* Precondition: array a[] is sorted in asceonding order */
template <class ItemType>
int BinarySearch (ItemType a[], int size, ItemType search)
{
    int left=0;
    int right=size-1;
    int midpoint= size/2;
    int count=0;
    

 // repeat the following, as long as left<=right
 //  1. find the middle point
 //  2. compare itmes at the middle point with "search" 
 //     * if same, return 
 //     * if "search" is smaller, continue to search the left half
 //     *  if "search" is larger, continue to search the right half
    if(search==a[midpoint]){
        return midpoint;
    }
        
    while((a[midpoint] != search) && (left <= right))
    {
        if (a[midpoint] > search)
        {
            right = midpoint - 1;
        }
        else
        {
            left = midpoint + 1;
        }
        midpoint = (left + right) / 2;
        count++;
    }
    cout << "Number of comparisons: " << count << endl;
    return midpoint;

}
template <class ItemType>
void printarray(ItemType a[], int size){
    cout << "Array Info: ";
    for (int i=0; i<=size; i++){
        cout << "a[" <<i << "] =" << a[i] <<endl;
    }
}



int main()
{
	int array1[100],array2[100],array3[200];
    int search;
    int bsearch;
    int lsearch;

	//seed random number generator
	srand (time(NULL));

	GenerateRandomArray (array1, 100);
	GenerateRandomArray (array2, 100);

	/* compare two sorting */
	SelectionSort (array1, 100);

	sort (array2, 100);
    printarray(array1, 100);
    printarray(array2, 100);
    cout << "What are you searching for? (Binary) ";
    cin >> search;
    bsearch=BinarySearch(array1, 100, search);
    cout << "Position: " << bsearch <<endl;
    cout << "What are you searching for? (linear) ";
    cin >> search;
    lsearch=Search(array1, 100, search);
    cout << "Position: " << lsearch <<endl;
    MergeSortedArray(array1,100,array2,100,array3,200);
    printarray(array3,200);

	/* compare linear search and binary searching */
	//Todo: 



	
	
	

}
