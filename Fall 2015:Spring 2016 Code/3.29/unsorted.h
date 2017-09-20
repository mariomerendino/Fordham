//Define the class UnsortedType, an unsorted list that stores a "list" of ItemType
//  implemented using linked list 

//Before using it,
//Define ItemType to be the type that you want... 
//e.g., typedef int ItemType;
#ifndef UNSORTEDTYPE_H
#define UNSORTEDTYPE_H
#include <iostream>

//declare ItemType here
////NOTE: all we expect from ItemType is that we should be able to 
////   compare two item types (== operator, used in GetItem())...
////typedef int ItemType;
//#include "SpendRecord.h"
//typedef SpendRecord ItemType;

//After declaring ItemType, we can declare NoteType... 
template<class ItemType> 
class UnsortedType 
{
  struct NodeType
 {
    ItemType info;
    NodeType* next;
 };
public:
  UnsortedType();
  // Constructor
  ~UnsortedType();
  // Destructor
  void MakeEmpty();
  // Function: Returns the list to the empty state.
  // Post:  List is empty.
  bool IsFull() const;
  // Function:  Determines whether list is full.
  // Pre:  List has been initialized.
  // Post: Function value = (list is full)

  int GetLength() const;
  // Function: Determines the number of elements in list.
  // Pre:  List has been initialized.
  // Post: Function value = number of elements in list

  ItemType GetItem(ItemType& item, bool& found);
  // Function: Retrieves list element whose key matches item's key (if
  //           present).
  // Pre:  List has been initialized.
  //       Key member of item is initialized.
  // Post: If there is an element someItem whose key matches
  //       item's key, then found = true and someItem is returned;	
  // 	 otherwise found = false and item is returned.
  //       List is unchanged.

  void PutItem(ItemType item);
  // Function: Adds item to list.
  // Pre:  List has been initialized.
  //       List is not full.
  //       item is not in list.
  // Post: item is in list.

  void DeleteItem(ItemType item);
  // Function: Deletes the element whose key matches item's key.
  // Pre:  List has been initialized.
  //       Key member of item is initialized.
  //       One and only one element in list has a key matching item's key.
  // Post: No element in list has a key matching item's key.

  void ResetList();
  // Function: Initializes current position for an iteration through the list.
  // Pre:  List has been initialized.
  // Post: Current position is prior to list.

  ItemType GetNextItem();
  // Function: Gets the next element in list.
  // Pre:  List has been initialized and has not been changed since last call.
  //       Current position is defined.
  //       Element at current position is not last in list.
  //	     
  // Post: Current position is updated to next position.
  //       item is a copy of element at current position.

private:
  NodeType* listData;
  //int length;
  NodeType* currentPos;
};


// This file contains the linked implementation of class
// UnsortedType.


//Include unsorted.h so that UnsortedType is known 
//#include "unsorted.h"

template<class ItemType>
UnsortedType<ItemType>::UnsortedType()  // Class constructor
{
  //length = 0;
  listData = NULL;
}

template<class ItemType>
UnsortedType<ItemType>::~UnsortedType()
// Post: List is empty; all items have been deallocated.
{
   MakeEmpty();
}

template<class ItemType>
bool UnsortedType<ItemType>::IsFull() const
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

template<class ItemType>
int UnsortedType<ItemType>::GetLength() const
// Post: Number of items in the list is returned.
{
   //Todo: going through the linked list to find out the length (i.e. number of 
   //nodes). 
   NodeType * p=listData;
   int cnt=0;

   while (p!=NULL)
   {
	cnt++;
        p = p->next;
   }

   return cnt;
}

template<class ItemType>
void UnsortedType<ItemType>::MakeEmpty()
// Post: List is empty; all items have been deallocated.
{
  NodeType* tempPtr;

    while (listData != NULL)
    {
      tempPtr = listData;
      listData = listData->next;
      delete tempPtr;
  }
  //length = 0;
}

template<class ItemType>
void UnsortedType<ItemType>::PutItem(ItemType item)
// item is in the list; length has been incremented.
{
  NodeType* location;			// Declare a pointer to a node

  location = new NodeType;		// Get a new node 
  location->info = item;		// Store the item in the node
  location->next = listData;	// Store address of first node 
						//   in next field of new node
  listData = location;		// Store address of new node into
						//   external pointer
  //length++;				// Increment length of the list
}

template<class ItemType>
ItemType UnsortedType<ItemType>::GetItem(ItemType& item, bool& found)
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

template<class ItemType>
void UnsortedType<ItemType>::DeleteItem(ItemType item)
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
  //length--;
}
  
template<class ItemType>
void UnsortedType<ItemType>::ResetList()
// Post: Current position has been initialized.
{
  currentPos = NULL;
}
 
template<class ItemType>
ItemType UnsortedType<ItemType>::GetNextItem()
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






#endif
