// This file contains the linked implementation of class
// UnsortedType.

#include <iostream>

//Include unsorted.h so that UnsortedType is known 
#include "unsorted.h"

template<class ItemType> 
UnsortedType<ItemType>::UnsortedType<ItemType>()  // Class constructor
{
  length = 0;
  listData = NULL;
  cout << "Default constructor is called\n";
}

template<class ItemType>
UnsortedType<ItemType>::UnsortedType<ItemType>(const UnsortedType<ItemType> & src)  // Class constructor
{
  //Todo by you: implement deep copy 
  cout <<"(shallow) copy constructor being called\n";
  length = src.length;
  listData = src.listData;
}
template<class ItemType>
UnsortedType<ItemType>::~UnsortedType<ItemType>()
// Post: List is empty; all items have been deallocated.
{
   MakeEmpty();
   cout << "destructor called\n";
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
   return length;
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
  length = 0;
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
  length++;				// Increment length of the list
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
  length--;
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







