/*.
 *h file, contains prototypes for Unsorted class
 *Creates a linked list of string type
 *Author: Mario J. Merendino
 *Professor Zhang
 *Last modified: April 2, 2016
 */
//Define the class UnsortedType, an unsorted list that stores a "list" of ItemType
//  implemented using linked list 

//Before using it,
//Define ItemType to be the type that you want... 
//e.g., typedef int ItemType;
#ifndef UNSORTEDTYPE_H
#define UNSORTEDTYPE_H

//declare ItemType here
////NOTE: all we expect from ItemType is that we should be able to 
////   compare two item types (== operator, used in GetItem())...
////typedef int ItemType;
#include "SpendRecord.h"
typedef string ItemType;

//After declaring ItemType, we can declare NoteType... 
struct NodeType
{
    ItemType info;
    NodeType* next;
};

class UnsortedType 
{
public:
  UnsortedType(); //default constructor
  UnsortedType (const UnsortedType & src);
  // Constructor
  UnsortedType(ItemType item[], int size);
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
  void DisplayLinkedList();
  //Function: Prints the linked list in an organized list
  //Pre: List has values
  //Post: Prints the linked list
  void AppendInTheEnd(ItemType item);
  //Function: Adds a value to the end of the linked list
  //Pre: A linked list has been created
  //Post: An item is added to the end of the list
  UnsortedType & operator= (const UnsortedType & other);
  //Function: assignment operator
  //Pre: A linked list has been created with value
  //Post: A new list is returned, containing a deep copy of *this listData
  UnsortedType operator+(const UnsortedType & right);
  //Function: Union
  //Pre: There are two linked lists both containing values
  //Post: A new list is returned, containing both lists values.
  bool InitDictFromFile (UnsortedType & dict, char * fileName);
  //Function: Initializes a dictionary using words from a file
  //Pre: A .txt file containing a dictionary with words.
  //Post: UnsortedType dict has a linked list of all the words the .txt file
  NodeType * GetList();
  //Function: Accessor Method
  //Post: returns variable listData;
private:
  NodeType* listData;
  NodeType* currentPos;
};
#endif
