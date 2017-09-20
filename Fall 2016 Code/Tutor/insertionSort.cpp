#include <iostream>
using namespace std;
void displayArray(int [], int);
void input(int[] , int , int );
int orderedInsert (int arr[], int first, int last, int target);
void mergeSort(int a[], int b[],int aSize, int bSize);

int main(){
    const int maxSize = 20;
    int array1[maxSize];
    int array2[maxSize];
    int aSize = 0;
    int bSize = 0;
    bool finished = false;
    int choice;
    while(finished == false){
        int cSize = aSize + bSize;
        cout << "What would you like to do?\n\t1) Insert into array #1\n\t2) Display Array #1";
        cout << "\n\t3) Insert into array #2\n\t4) Display Array #2\n\t5) Merge two Arrays and display\n\t0) Quit\n:";
        cin >> choice;
        cout << endl;
        switch(choice){
            case 1:
                int num;
                cout << "What number?\n";
                cin >> num;
                aSize++;
                input(array1, aSize, num);
                break;
            case 2:
                displayArray(array1, aSize);
                break;
            case 3:
                int num2;
                cout << "What number?\n";
                cin >> num2;
                orderedInsert(array2, 0, bSize, num2);
                bSize++;
                break;
            case 4:
                displayArray(array2, aSize);
                break;
            case 5:
                //const int lenghtOfC= cSize;
                //int array3[lenghtOfC];
                mergeSort(array1, array2, aSize, bSize);
                //displayArray(array3, 10);
                break;
            case 0:
                finished = true;
                break;
            default:
                cout << "ERROR: Incorrect Input\n";
                break;
        }
    }
}
void input(int a[], int size, int num){
    if (size == 0){
        a[0] = num;
    }
    else{
        int location = size;
        for(int i=0; i < size; i++){
            //Fix If statement.
            if ((a[i] < num && a[i+1] >= num)|| a[i] == num){
                location = i;
            }
        }
        int temp;
        int count;
        for (int n = size; n > location; n--){
            if (n+1 != size){
                a[n] = a[n-1];
            } 
        }
        a[location]=num;
    }
}
int orderedInsert (int arr[], int first, int last, int target)
// insert target into arr such that arr[first..last] is sorted,
//   given that arr[first..last-1] is already sorted.
//   Return the position where inserted.
{
    int i = last;
    if (last == 0){
        arr[0]= target;
        
    }
    else if (last == 1){
        if (arr[0] > target){
            arr[1] = arr[0];
            arr[0] = target;
            i = 0;
        }
        else{
            arr[1] = target;
        }
        
    }
    else{
        
        while ((i > first) && (target < arr[i-1]))
        {   
            arr[i] = arr[i-1];
            i--;
        }
        arr[i] = target; 
    }
    return i;
}
void displayArray(int a[], int size){
    cout << "Displaying Array...\n";
    for (int i = 0; i < size; i++){
        cout << a[i] <<  " ";
    }
    cout << endl << endl;
}
void mergeSort(int a[], int b[],int aSize, int bSize){
    int c[aSize+bSize];
    int i(0),j(0),k(0);
    while (k != (aSize+bSize)){
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
    displayArray(c, aSize+bSize);
}