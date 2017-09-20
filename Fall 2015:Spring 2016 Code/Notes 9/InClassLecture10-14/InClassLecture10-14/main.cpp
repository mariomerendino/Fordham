//
//  InClassLecture10-14
//  Heap Vs. Stack memory
//  POINTERS
//

#include <iostream>
#include "date.h"
using namespace std;
void Example1();
void Example2();
void Example3();
int main(){
    Example2();
}
void Example1(){ //Pointers with ints, and Variables
    int iVar=9; //Creates Variable
    cout << iVar << " " <<&iVar << endl; //Prints 9 and iVars address
    int *iPtr; //Creates Pointer(*)
    int *iPtr2 = new int; //Creates other Pointer
    iPtr=new int; //Sets iPtr to a heap location
    cout << iPtr << " " <<&iPtr << endl;//Prints new heap location and prints iptrs location
    iPtr= &iVar; //Reassigns iPtr to iVars location, YOU LOSE HEAP LOCATION.
    cout << iPtr << " " <<&iPtr << endl;//Prints ivars location, and iptr location
    *iPtr2= 20; //Sets new int to 20 in the heap
    cout << iPtr2 << " " << *iPtr2;
    
 }
void Example2(){
    Date d;
    Date *dptr=&d;
    d.display();
    dptr->display();
    dptr->input();
    d.display();
    dptr->display();
}
void Example3(){
    int x=10; //sets x = 10
    int *iPtr=&x;
    cout << x << " " << &x << " " << iPtr << " " << *iPtr << endl;
    *iPtr = 15;
    cout << x << " " << &x << " " << iPtr << " " << *iPtr << endl;
}