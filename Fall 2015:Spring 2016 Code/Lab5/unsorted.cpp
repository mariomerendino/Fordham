// This file contains the linked implementation of class
// UnsortedType.
/*Author: Mario J. Merendino
 *Professor Zhang
 *Last modified: April 2, 2016
 */
#include <iostream>
#include <fstream>
//Include unsorted.h so that UnsortedType is known 
#include "unsorted.h"


UnsortedType::UnsortedType()  // Class constructor
{
  listData = NULL;
}


UnsortedType::UnsortedType(const UnsortedType & src)  // Class constructor
{
    
    (*this)=src; //implement deep copy using n
}
UnsortedType::UnsortedType(ItemType item[], int size){ //constructor using an array
    NodeType * p; //creates node type ptr
    p=listData;//takes values from listdata
    int count=0;
    while(count!=size){
        p->info=item[count];
        p=p->next;
        count++;
    }
}

UnsortedType::~UnsortedType()
// Post: List is empty; all items have been deallocated.
{
   MakeEmpty(); //makes empty dealocates all the memory
}

bool UnsortedType::IsFull() const
// Returns true if there is no room for another ItemType 
//  on the free store; false otherwise.
{
  NodeType* location;
  try
  {
    location = new NodeType;
    delete location;
    return false;
  }
  catch(std::bad_alloc exception)
  {
    return true;
  }
}

int UnsortedType::GetLength() const
// Post: Number of items in the list is returned.
{
    NodeType * p;
    int numnodes=0;
    p = listData;
    while (p!=NULL)
    {
        numnodes++;
        p = p->next;
    }
    return numnodes;
}

void UnsortedType::MakeEmpty()
// Post: List is empty; all items have been deallocated.
{
  NodeType* tempPtr;

    while (listData != NULL)
    {
      tempPtr = listData;
      listData = listData->next;
      delete tempPtr;
  }
}
void UnsortedType::PutItem(ItemType item)
// item is in the list; length has been incremented.
{
  NodeType* location;			// Declare a pointer to a node

  location = new NodeType;		// Get a new node 
  location->info = item;		// Store the item in the node
  location->next = listData;	// Store address of first node 
						//   in next field of new node
  listData = location;		// Store address of new node into
						//   external pointer
}

ItemType UnsortedType::GetItem(ItemType& item, bool& found)
// Pre:  Key member(s) of item is initialized.
// Post: If found, item's key matches an element's key in the 
//       list and a copy of that element has been stored in item;
//       otherwise, item is unchanged. 
{
  bool moreToSearch;
  NodeType* location;

  location = listData;
  found = false;
  moreToSearch = (location != NULL);

  while (moreToSearch && !found) 
  {
    if (item==location->info) 
    {
      found = true;
      item = location->info;
    }
    else
    {
      location = location->next;
      moreToSearch = (location != NULL);
    }
  }
  return item;
}

 void UnsortedType::DeleteItem(ItemType item)
// Pre:  item's key has been initialized.
//       An element in the list has a key that matches item's.
// Post: No element in the list has a key that matches item's.
{
  NodeType* location = listData;
  NodeType* tempLocation;

  // Locate node to be deleted.
  if (item == listData->info) 
  {
    tempLocation = location;
    listData = listData->next;		// Delete first node.
  }
  else
  {
    while (item == (location->next)->info)
      location = location->next;

    // Delete node at location->next
    tempLocation = location->next;
    location->next = (location->next)->next;
  }
  delete tempLocation;
}

void UnsortedType::ResetList()
// Post: Current position has been initialized.
{
  currentPos = NULL;
}
 
ItemType UnsortedType::GetNextItem()
// Post:  A copy of the next item in the list is returned.
//        When the end of the list is reached, currentPos
//        is reset to begin again.
{
  ItemType item;
  if (currentPos == NULL)
    currentPos = listData;
  else
    currentPos = currentPos->next;
  item = currentPos->info;
  return item;
}
void UnsortedType::DisplayLinkedList(){ //displays the linked list
    NodeType * p;
    int counter = 1;
    p = listData;   //initialize pointer p to point to the first node in the linked list
    cout <<"Displaying the list: " << endl;
    cout <<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" <<endl;
    while (p!=NULL)
    {
        cout << "Node: " << counter << endl;
        cout <<"value:  " << p->info <<endl;
        p = p->next;
        counter ++;
    }
    cout <<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" <<endl;
}
UnsortedType & UnsortedType:: operator= (const UnsortedType & other)
{
    NodeType * Otherlistdata = other.listData;
    if (this!=&other) // so we don't self-assign
    {
        
        this->MakeEmpty();//deallocate "this" object's memory (the linked list)
        
        while(Otherlistdata!=NULL){ //assign "this" object's data members with data members of "other"
            PutItem(Otherlistdata->info);
            Otherlistdata=Otherlistdata->next;
        }
        
        
            
            return *this; 
    }
    else{
        cout <<"ERROR" <<endl;
        return *this;
    }
    
}
void UnsortedType::AppendInTheEnd(ItemType item) //adds a value to the end of the list
{
    NodeType *tmp = new NodeType;
    NodeType *cur;
    cur = listData;
    tmp->info=item;
    tmp->next=NULL;
    if (listData == NULL)//incase the linked list is empty
     listData = tmp;
    else{
        while(cur->next!=NULL) //loops to the end of the list
        {
            cur=cur->next;
        }
        cur->next=tmp; //adds tmp to the end
    }
}
UnsortedType UnsortedType::operator+(const UnsortedType & right) //union fucntion
{
    UnsortedType result;
    NodeType *list1=listData;
    NodeType *list2=right.listData;
    while (list1!=NULL){ //loops to the end of the first list
        result.PutItem(list1->info); //puts the values in the new list
        list1=list1->next;
        
    }
    while (list2!=NULL){ //loops to the end of the second list
        result.PutItem(list2->info); //puts the items in the list
        list2=list2->next;
    }
    
    return result;
}
bool UnsortedType::InitDictFromFile (UnsortedType & dict, char * fileName)
{
    ifstream inFile; //declare a ifstream object
    
    // open the file
    inFile.open (fileName); //connect the inFile with disk file
    // given by path name fileName
    
    if (!inFile) //if something went wrong, e.g., file nonexist,...
    {
        cerr <<"failed to open "<<fileName<<endl;
        return false;
    }
    
    // keep reading a string from the file, put it into the dict
    while (!inFile.eof()) //while we haven't reached end of file yet
    {
        string word;
        inFile >> word;
        
        // puts word into the dictionary dict
        dict.AppendInTheEnd(word);
        
    }
    
    inFile.close();
    return true;
}
NodeType * UnsortedType::GetList(){
    return listData;
}



