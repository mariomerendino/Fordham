//  Author: Mario Merendino
//  Professor Papadakis;
//  Lab4
//  Creates an Object named set, and compares the values using set methodsin each obj.
//  Last Modified: 11/12/15.

#include "set.h"
#include <iostream>
#include <cstdlib>
using namespace std;
Set::Set( int s ) {
    if ( s > 0 )
        psize = s;
    else
        psize = DEFAULTSIZE;
    // Allocate an array of the specified size
    set = new int[psize];
    if ( !set ) {
        cout << "\nError: Memory allocation failed, exiting program." << endl;
        exit(1);
    }
    
    
    // memory for the array was allocated,
    // initialize each elementto 0 default value
    for ( int i = 0; i < psize; i++ )
        set[i] = 0;
    
    // array has not been populated
    lsize = 0;
}
Set::Set( const Set &copyset, int p ){
    
    // Allocate the require memory
    set = new int[p];
    if ( !set ) {
        cout << "\nError: Memory allocation failed, exiting program." << endl;
        exit(1);
    }
    
    for ( int i = 0; i < p; i++ )
        set[i] = copyset.set[ i ];
    
    lsize = p;
    
}
Set::Set( const Set &copyset ): psize( copyset.psize) {
    
    // Allocate the require memory
    set = new int[psize];
    if ( !set ) {
        cout << "\nError: Memory allocation failed, exiting program." << endl;
        exit(1);
    }
    
    for ( int i = 0; i < psize; i++ )
        set[i] = copyset.set[ i ];
}
Set::~Set(){
}

void Set::input(istream & os){
    bool validate=true;
    cout << "Enter up to 10 numbers or "<<sentinal <<endl;
    for(int i=0; i<psize; i++){
        do{
            os >> set[i];
            if(set[i]== sentinal){
                validate=false;
                break;
            }
            else{
                for(int k=0; k <i; k++){
                    if(set[k]==set[i]){
                        validate=false;
                        cout << "Enter another interger" << endl;
                    }
                }
            }
        }while (!validate);
        if (set[i]== sentinal){
            lsize=i;
            break;
        }
    }
}
void Set::display(ostream & os) const{
    cout << "{";
    for (int i=0; i<psize; i++){
        if(set[i]!= sentinal){
            os << set[i] << ", ";
        }
        else{
            break;
        }
    }
    cout << "}" << endl;
}
istream &operator>> ( istream &os, Set &a )
{
    a.input(os);
    return(os);
}
ostream &operator<< ( ostream &os, const Set &a )
{
    a.display(os);
    return(os);
}
bool Set::element(int n){ //Checks if element is NOT in the set! takes in one interger.
    bool validate= true;
    for(int i=0; i<psize; i++){
        if(set[i]==n){
            validate=false;
        }
        else
            continue;
    }
    return(validate);
}
Set Set::Union(Set Y){ //Union function
    int newp(this->newpsize(Y)), x=lsize;
    Set X(newp);//Creates new set named X passing new physical size
    for(int i=0; i <lsize; i++){ //Loops Through
        X.set[i]=this->set[i];//Sets all ints in first Set to new Set
    }
    for(int k=0; k<newp; k++){
        if(X.element(Y.set[k])){
            X.set[x]=Y.set[k];
            x++;
        }
        else{
            continue;
        }
    }
    return(X); // Returns new set
}
Set Set::Difference(Set Y){
    Set X;
    int i=0;
    for(int k=0; k<lsize; k++){
        if(Y.element(set[k])){
            X.set[i]=set[k];
            i++;
        }
        else{
            continue;
        }
    }
    X.set[i]=sentinal;
    return(X); // Returns new set
}
Set Set::Intersection(Set Y){
    Set X;
    int i=0;
    for(int k=0; k<lsize; k++){
        if(!(Y.element(set[k]))){
            X.set[i]=set[k];
            i++;
        }
        else{
            continue;
        }
    }
    X.set[i]=sentinal;
    return(X); // Returns new set
}
Set Set::addinterger(int n){
    if(element(n)){
        int passlsize;
        passlsize= lsize +1;
        Set X(passlsize);
        for(int y=0; y < this->lsize; y++){
            X.set[y]=set[y];
        }
        X.set[passlsize-1]=n;
        return (X);
    }
    else{
        return(*this);
    }
}
Set Set::removeinterger(int n){
    n=n-1;
    Set X;
    for(int i=0; i<this->lsize+1; i++){
        if(i==n){
            continue;
        }
        else if( i < n){
            X.set[i]=set[i];
        }
        else if(i > n){
            X.set[i-1]=set[i];
            X.lsize=i-1;
        }
    }
    return(X);
}
Set Set::operator+(Set X){
    Set Z= this->Union(X);
    return (Z);
}
Set Set::operator^(Set X){
    Set Z= this->Intersection(X);
    return (Z);
}
Set Set::operator-(Set X){
    Set Z= this->Difference(X);
    return (Z);
}
bool Set::operator==(Set X){
    bool retstat=false;
        for(int i=0; i <getlsize(); i++){
            if(set[i]== X.set[i]){
                retstat=true;
            }
            else{
                retstat=false;
            }
        }
    return(retstat);
}
bool Set::operator!=(Set X){
    return(!(this->operator==(X)));
}
Set Set::operator+(int n){
    Set Z= this->addinterger(n);
    return (Z);
}
Set Set::operator-(int n){
    Set Z= this->removeinterger(n);
    return (Z);
}
int Set::newpsize(Set X){
    int value;
    value= getpsize()+ X.getpsize(); //physicalsize of new array
    return(value);
}
int Set::newlsize(Set X){
    int value;
    value= getlsize() + X.getlsize();
    return(value);
}
int Set::getpsize(){
    return(psize);
}
int Set::getlsize(){
    return(lsize);
}
