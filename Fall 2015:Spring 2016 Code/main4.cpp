
#include <iostream>
using namespace std;

int sum (int info[], int fromIndex, int toindex){
    if(fromIndex==toindex){
        return info[fromIndex];
    }
    else{
        return (sum(info, fromIndex+1, toindex)+info[fromIndex]);
    }
}
void sort(int a[], int size){
    int tmp;
    if (size==1){
        return;
    }
    for(int i=0; i<size-1; i++){
        if(a[i]>a[i+1]){
            tmp=a[i];
            a[i]=a[i+1];
            a[i+1]=tmp;
        }
    }
    sort(a, size-1);
}
int main(){
    int a[3]={8,3,4};
    sort(a, 3);
    for (int i=0; i< 3; i++){
        cout << a[i] <<endl;
    }
}
