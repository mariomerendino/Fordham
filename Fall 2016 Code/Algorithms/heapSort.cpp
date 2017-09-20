#include <iostream>
using namespace std;
void displayArray(int[], int);
void max_heap(int a[], int i, int n);
void heapsort(int a[], int n);
void build_maxheap(int a[], int n);
int main(){

    int array1[10] = {14,12,5,2,1,3,4,11,13,15};
    int array2[10] = {10,9,8,7,6,5,4,3,2,1};
    int array3[15] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    
    cout << "Unsorted Array #1" << endl;
    displayArray(array1,10);
    build_maxheap(array1,10);
    heapsort(array1, 10);
    cout<<"Sorted Array #1" <<endl;
    displayArray(array1,10);

    cout << endl<< "Unsorted Array #2" << endl;
    displayArray(array2,10);
    build_maxheap(array2,10);
    heapsort(array2, 10);
    cout<<"Sorted Array #2" <<endl;
    displayArray(array2,10);
    
    cout << endl<< "Unsorted Array #3" << endl;
    displayArray(array3,15);
    build_maxheap(array3,15);
    heapsort(array3, 15);
    cout<<"Sorted Array #3" <<endl <<endl;
    displayArray(array3,15);
}
void displayArray(int a[], int size){
    for (int i = 0; i < size; i++){
        cout << a[i] <<  " ";
    }
    cout << endl << endl;

}
void max_heap(int a[], int i, int n){
    int j, temp;
    temp = a[i];
    j = 2*i;
    while (j <= n)
    {
        if (j < n && a[j+1] > a[j])
            j = j+1;
        if (temp > a[j])
            break;
        else if (temp <= a[j])
        {
            a[j/2] = a[j];
            j = 2*j;
        }
    }
    a[j/2] = temp;
}
void heapsort(int a[], int n){
    int i, temp;
    for (i = n; i >= 0; i--)
    {
        temp = a[i];
        a[i] = a[1];
        a[1] = temp;
        max_heap(a, 1, i - 1);
    }
}
void build_maxheap(int a[], int n){
    for(int i = n/2; i >= 1; i--)
    {
        max_heap(a, i, n);
    }
}
