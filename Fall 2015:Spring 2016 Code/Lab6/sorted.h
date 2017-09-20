#ifndef SORTED_H
#define SORTED_H
//#include "ItemType.h" 
// File ItemType.h must be provided by the user of this class. 
//  ItemType.h must contain the following definitions: 
//  MAX_ITEMS:     the maximum number of items on the list 
//  ItemType:      the definition of the objects on the list 
//  RelationType:  {LESS, GREATER, EQUAL}
//  Member function ComparedTo(ItemType item) which returns 
//       LESS, if self "comes before" item 
//       GREATER, if self "comes after" item 
//       EQUAL, if self and item are the same 

#include "unsorted.h"

class SortedType: public UnsortedType
{
public:
  SortedType(int size=MAX_ITEMS);

  SortedType(const SortedType & other); 

  //We don't need to override operator=, destructor (as the inherited one is good for us). 

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

   ItemType GetItem(ItemType, bool&);
  // Function: Retrieves list element whose key matches item's key (if
  //           present).
  // Pre:  List has been initialized.
  //       Key member of item is initialized.
  // Post: If there is an element someItem whose key matches
  //       item's key, then found = true and someItem is returned.
  //     otherwise found = false and item is returned.
  //       List is unchanged.
  SortedType operator +(SortedType &);


  ItemType GetLargestItem() const;

private:
  //don't need any additional data members 
};
#endif
