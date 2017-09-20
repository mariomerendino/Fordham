/*
 h. file, contains prototypes for Unsorted Class
 Author: Mario J. Merendino
 Professor Zhang
 Last Modified: Feb 23, 2016
 Known bug: None
 */
#include <iostream>
#include "DollarAmount.h"
using namespace std;
//Dollar amount class is included.
typedef DollarAmount ItemType;
const int MAX_ITEMS(20);

class UnsortedType 
{
    //friend ostream operator<< (ostream &, const UnsortedType &);
public:
  UnsortedType();
  // Constructor
  ~UnsortedType();
  //Destructor
  
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

  ItemType GetItem(ItemType, bool&);
  // Function: Retrieves list element whose key matches item's key (if
  //           present).
  // Pre:  List has been initialized.
  //       Key member of item is initialized.
  // Post: If there is an element someItem whose key matches
  //       item's key, then found = true and someItem is returned.
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
    
  void output();//Display method

  ItemType GetNextItem();
  // Function: Gets the next element in list.
  // Pre:  List has been initialized and has not been changed since last call.
  //       Current position is defined.
  //       Element at current position is not last in list.
  //	     
  // Post: Current position is updated to next position.
  //       item is a copy of element at current position.
  void bubblesort();
  void selectionsort();
  //Functions: Two Sorting functions.
  //Pre: list is unorganized
  //Post: List is organized in numerical order.
  void median();
  //Function: Finds the median
  int largestindex(); //Finds the index of the item with largest amt
  ItemType LargestItem();//Finds the largest item in the array after using largest index function
  ItemType sum(); //Calculates sum of the array
  

private:
  int length, indexoflargest;
  ItemType *info;
  int currentPos;
};

