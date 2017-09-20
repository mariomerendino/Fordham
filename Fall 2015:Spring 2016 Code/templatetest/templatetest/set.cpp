//
//  set.h
//  template test
//
//  Created by Mario J Merendino on 11/27/15.
//  Copyright (c) 2015 Mario J Merendino. All rights reserved.
//


template <class T>
Set<T>::Set( int s ) {//DEFAULT CONSTRUCTOR
    if ( s > 0 )//if user initializes psize in parenthesis
        psize = s;
    else
        psize = DEFAULTSIZE;// otherwise use default value
    // Allocate an array of the specified size
    set = new T[psize];//DYNAMIC MEMORY ALLOCATION
    if ( !set ) {
        cout << "\nError: Memory allocation failed, exiting program." << endl;
        exit(1);
    }
    setivar();//Sets initializing value
    for ( int i = 0; i < psize; i++ )
        set[i] = ivar;//sets each value to the initialized value
    lsize = 0;
    setsentinal();
}
/*template <class T>
Set<T>::Set(Set &copyset, int x){//COPY CONSTRUCTOR
    if ( x > 0 )//if user initializes psize in parenthesis
        psize = x;
    else
        psize = DEFAULTSIZE;// otherwise use default value
    set = new int[copyset.lsize];
    if ( !set ) {
        cout << "\nError: Memory allocation failed, exiting program." << endl;
        exit(1);
    }
 
    for ( int i = 0; i < lsize; i++ )
        set[i] = copyset.set[ i ];
 
    lsize = copyset.lsize;
}*/
template<class T>
Set<T>::~Set(){
    //if (set)
    //    delete [] set;
    //set = NULL;
}
template <class T>
void Set<T>::display(ostream & os){ //Display method
    cout << "{";
    for (int i=0; i<psize; i++){//loops through set
        if(set[i]== sentinal){//if it = the sentinal value, the display method ends
            break;
        }
        else{
            if(i != lsize-1){
                os << set[i] << ", ";//displays value if its not the sentinal
            }
            else{
                os << set[i];
            }

        }
    }
    cout << "}" << endl;
    cout <<"Logical Size: " <<lsize<<endl;
    cout <<"Physical Size: " <<psize<<endl<<endl;;
}
template <class T>
void Set<T>::input(istream &os){ //input method
    
    cout << "Enter up to " << psize << " elements or " << sentinal << " to signal end of input:" << endl;
    bool validate;//used for loop
    for ( int i = 0; i < psize; i++ ) {// loops through set
        do{
            validate=true;
            os >> set[i];//input value for set
            for(int k=0; k<i; k++){
                if (set[k]==set[i]){//if inputed value is equal to anyother value in the set
                    cout << "NO REPEATING VALUES! Enter another element"<<endl;
                    validate=false;//sets validate = to false
                    lsize = i;
                }
            }
        }while (!validate); //if validate= false, it repeats
        if ( set[ i ] == sentinal){
            lsize = i;
            break;
        }
    }
}
template <class T> //SETS SENTINAL VALUE FOR EACH DATA TYPE
void Set<T>::setsentinal(){
    sentinal=0;
}
template <>
void Set<int>::setsentinal(){
    sentinal=-999;
}
template <>
void Set<char>::setsentinal(){
    sentinal='0';
}
template <>
void Set<double>::setsentinal(){
    sentinal=0.0;
}
template <>
void Set<string>::setsentinal(){
    sentinal="0";
}
template <class T>
void Set<T>::setivar(){//SETS Initial VALUE FOR EACH DATA TYPE
    ivar=0;
}
template <>
void Set<int>::setivar(){
    ivar=0;
}
template <>
void Set<char>::setivar(){
    ivar=0;
}
template <>
void Set<double>::setivar(){
    ivar=0.0;
}
template <>
void Set<string>::setivar(){
    ivar='0';
}
template <class T>
bool Set<T>::element ( T n ){//checks if element is in a set
    bool validate = false;
    for (int i=0; i<lsize; i++){//loop through set
        if (set[i]==n){//if set[i] is equal to n
            validate=true; //the value is in set[i]
            break;
        }
    }
    return validate;
    
}
template <class T>
Set<T> Set<T>::Union(Set Y){ //Union function
    int x=lsize;
    Set<T> X(psize+Y.psize);//Creates new set named X passing new physical size
    for(int i=0; i <lsize; i++){ //Loops Through
        X.set[i]=this->set[i];//Sets all ints in first Set to new Set
        X.lsize=i+1;
    }
    for(int k=0; k<lsize+Y.lsize; k++){//loops through second set
        if(!(X.element(Y.set[k]))){//if Y.set[k] is not in set X it adds it to the new set
            X.set[x]=Y.set[k];
            x++;
        }
        if(Y.set[k]==sentinal){
            break;
        }
    }
    X.lsize=x-1;
    return(X); // Returns new set
}
template <class T>
Set<T> Set<T>::Intersection(Set Y){//Intersection function
    Set<T> X(psize+Y.psize);
    int i=0;
    for(int k=0; k<psize; k++){//loops through
        if(Y.element(set[k])){//if its an element in set Y, it adds it to the new set
            X.set[i]=set[k];
            i++;
            X.lsize=i;
        }
    }
    X.set[i]=sentinal;
    return(X); // Returns new set
}
template <class T>
Set<T> Set<T>::Difference(Set Y){//Difference function
    Set<T> X(psize);
    int i=0;
    for(int k=0; k<lsize; k++){
        if(!(Y.element(set[k]))){ //if its not the other set
            X.set[i]=set[k];// it adds it to the new set
            i++;
            X.lsize=i;
        }
    }
    X.set[i]=sentinal;
    return(X); // Returns new set
}
template <class T>
Set<T> Set<T>::delelement(T n){//Deletes element
    Set<T> X;//Creates Set X
    bool validate=true;
    if(element(n)){//if its an element in the set
        for(int i=0; i<this->lsize+1; i++){//loops through
            if(set[i]==n){//if n is = to set[i]
                validate=false;// all it does it continue and sets validate to false
                continue;
            }
            else if(validate){//if validate is true it adds the value to the set
                X.set[i]=set[i];
            }
            else if(!validate){//if validate is false it adds teh value to the previous number in the set.
                X.set[i-1]=set[i];
            }
        }
        X.set[lsize]=sentinal;
        return(X);
    }
    else{//if its not in the set it returns the original set
        return(*this);
    }
}
template <class T>
Set<T> Set<T>::addelement(T n){// Adds element to the set
    if(!(element(n))){//if its not in the set
        int passlsize;
        passlsize= lsize +1;
        Set X(passlsize);//create new set
        for(int y=0; y < this->lsize; y++){
            X.set[y]=set[y];//set everything from old set equal to the new set
        }
        X.set[passlsize-1]=n;//sets new value to next in sequence
        X.lsize=passlsize;
        return (X);
    }
    else{
        return(*this);
    }
}
template <class T>//OVERLOADED OPERATORS
Set<T> Set<T>::operator+(Set X){//Union
    return (Union(X));
}
template <class T>
Set<T> Set<T>::operator^(Set X){//intersection
    return (Intersection(X));
}
template <class T>
Set<T> Set<T>::operator-(Set X){//difference
    return (Difference(X));
}
template <class T>
Set<T> Set<T>:: operator+(T n){//add an element to the set
    return (addelement(n));
}
template <class T>
Set<T> Set<T>:: operator-(T n){//Remove element
    return (delelement(n));
}
template <class T>
bool Set<T>::operator==(Set X){//Equality
    bool retstat=true;
    for(int i=0; i <lsize; i++){
        if(element(X.set[i])){
            continue;
        }
        else{
            retstat=false;
        }
    }
    return(retstat);
}
