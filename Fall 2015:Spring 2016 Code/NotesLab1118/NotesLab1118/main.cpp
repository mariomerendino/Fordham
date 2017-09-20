#include <iostream>
using namespace std;
void printArray(int a[], int s);
template<typename T>
void printArray(T a[], int s){
    cout << "Template Print: ";
    cout << "{";
    for (int i=0; i<s; i++){
        cout << a[i] <<", ";
    }
    cout << "}"<<endl<<endl;
}
template<typename T>
void printArray(T a[], int x, int s){
    cout << "Template Print(taking in two parameters): ";
    cout << "{";
    for (int i=x; i<s; i++){
        cout << a[i] <<", ";
    }
    cout << "}"<<endl<<endl;
}
void printArray(int a[], int s){
    cout << "Print Array: ";
    cout << "{";
    for (int i=0; i<s; i++){
        cout << a[i] <<", ";
    }
    cout << "}"<<endl<<endl;
}
int main(){
    const int var=10;
    int arr[var]={1,2,3,4,5,6,7,8,9,10};
    string carray[var]={"a", "b", "c", "d", "e", "f", "g", "h", "i", "j"};
    printArray(arr, var);
    printArray(carray, var);
    printArray(arr, 5, 8);
    printArray(carray, 5, 8);
}
