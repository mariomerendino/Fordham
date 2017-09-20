/*
 cpp. file, contains methods for Unsorted Class
 Dynamically creates array of dollar amounts
 Author: Mario J. Merendino
 Professor Zhang
 Last Modified: Feb 23, 2016
 Known bug: None
 */

#include "unsorted.h"

UnsortedType::UnsortedType()
{
  //constructor: dynamically creates array.
  info= new ItemType[MAX_ITEMS];
  length = 0;
}
UnsortedType::~UnsortedType(){
    //destructor
    delete [] info;
    info=NULL;
}
bool UnsortedType::IsFull() const
{
  //returns true or false if length=max
  return (length == MAX_ITEMS);
}
int UnsortedType::GetLength() const
{
  //accessor method
  return length;
}

ItemType UnsortedType::GetItem(ItemType item, bool& found) 
// Pre:  Key member(s) of item is initialized. 
// Post: If found, item's key matches an element's key in the 
//       list and a copy of that element has been returned;
//       otherwise, item is returned. 
{
  bool moreToSearch;
  int location = 0;
  found = false;

  moreToSearch = (location < length);

  while (moreToSearch && !found) 
  {
    if(item == info[location]){
       found=true;
       break;
    }
    else{
       location++;
       moreToSearch=(location < length);
    } 
  }
  return item;
}
void UnsortedType::MakeEmpty()
// Post: list is empty.
{
  length = 0;
}
void UnsortedType::PutItem(ItemType item)
// Post: item is in the list.
{
  info[length] = item;
  length++;
  if (length==MAX_ITEMS){
      ItemType *temp= new ItemType[2*MAX_ITEMS]; //it creates an array thats double the size of the last
      for(int i=0; i<length; i++){
          temp[i]=info[i];
      }
      delete[]info; //deletes old ptr
      info=temp;
  }

}
void UnsortedType::DeleteItem(ItemType item)
// Pre:  item's key has been initialized.
//       An element in the list has a key that matches item's.
// Post: No element in the list has a key that matches item's.
{
  int location = 0;

  while (item==info[location])
    location++;

  info[location] = info[length - 1];
  length--;
}
void UnsortedType::ResetList()
// Post: currentPos has been initialized.
{
  currentPos = -1;
}

ItemType UnsortedType::GetNextItem()
// Pre:  ResetList was called to initialized iteration.
//       No transformer has been executed since last call.
//       currentPos is defined.
// Post: item is current item.
//       Current position has been updated.
{
  currentPos++;
  return info[currentPos];
}
void UnsortedType::output(){
    for (int i=1; i<length; i++){
        cout << info[i] <<endl;
    }
}
/*ostream operator<< (ostream &out, ItemType t){
    t.output(out);
    return out;
}*/
int UnsortedType::largestindex(){
    int largest;
    for(int i=1; i<length; i++){
        if(info[i]>info[largest]){
            largest=i;
        }
    }
    indexoflargest=largest;
    return largest;
}
void UnsortedType::bubblesort(){ //bubble sort function
    int last(length-1);
    for(int x=0; x<length; x++){
        for(int i=0;i<last;i++){
            if(info[i] > info[i+1]){
                ItemType temp=info[i];
                info[i]=info[i+1];
                info[i+1]=temp;
            }
        } 
    }
}
void UnsortedType::selectionsort(){
    int end=length-1;
    for (int i=0; i<end; i++){
        if (indexoflargest!=end){
            info[i]=info[indexoflargest];
            end--;
        }
    }
}
void UnsortedType::median(){ // calculates the median of the array
    int median;
    if(length%2==0){
        median= length/2;
        cout << "The median is " << info[median] <<endl;
    }
    else{
        median= length/2;
        DollarAmount m;
        m= info[median]+info[median-1];
        m= m/2;
        cout << "The median is " << m <<endl;
    }
}
ItemType UnsortedType::LargestItem(){
    return(info[indexoflargest]);
}
ItemType UnsortedType::sum(){ // calculates the sum of the Array of dollars
    ItemType sum;
    for(int x=0; x<length; x++){
        if(info[x].getdollar()!= -1)
        {
            sum=sum+info[x];
        }
    }
    return(sum);
}

