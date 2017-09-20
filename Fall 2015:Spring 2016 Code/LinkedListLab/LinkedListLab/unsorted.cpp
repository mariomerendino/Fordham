// Implementation file for Unsorted.h

#include "unsorted.h"
#include <assert.h>

UnsortedType::UnsortedType(int init_size=MAX_ITEMS)
{
  assert (init_size>0);
  info = new ItemType[init_size];
  size = init_size;

  length = 0;
}

UnsortedType::~UnsortedType ()
{
  if (info!=NULL)
  	delete [] info;
}

bool UnsortedType::IsFull() const
{
  return (length == size);
}
int UnsortedType::GetLength() const
{
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
    if (item==(info[location]))
    {
      found = true;
            item = info[location];
    }
    else
	{
      		location++;
                    moreToSearch = (location < length);
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
  if (length==size){
	ItemType * tmp = new ItemType[size*2];
        size *= 2;

        for (int i=0;i<length;i++)
		tmp[i] = info[i];

	delete [] info;
	info = tmp; 
  } 
  info[length] = item;
  length++;
}

void UnsortedType::DeleteItem(ItemType item)
// Pre:  item's key has been initialized.
//       An element in the list has a key that matches item's.
// Post: No element in the list has a key that matches item's.
{
  int location = 0;

  while (!(item==info[location]))
    location++;

  info[location] = info[length - 1];
  length--;
}
void UnsortedType::ResetList()
// Post: currentPos has been initialized.
{
  currentPos = -1;
}

ItemType & UnsortedType::GetNextItem()
// Pre:  ResetList was called to initialized iteration.
//       No transformer has been executed since last call.
//       currentPos is defined.
// Post: item is current item.
//       Current position has been updated.
{
  currentPos++;
  return info[currentPos];
}

ItemType & UnsortedType::operator[](int index) 
{
   return info[index];
}

int UnsortedType::LargestItemIndex (int start, int end)
{
    assert (start<=end && start>=0 && end>=0 && start <= length-1 && end <=length-1);
    int index = start; 
    
    for (int i=start+1; i<=end; i++)
	if (info[i]>info[index])
		index = i;
   
    return index;
}

ItemType UnsortedType::GetLargestItem()
{
   return info[LargestItemIndex(0,length)];
}

 // sort in ascending order
void UnsortedType::sort()
{
  //bubble sort is used 
  ItemType tmp;
  int rightEnd=length-1; //info[0]...info[rightEnd] is unsorted 

  for (int pass=0;pass<length-1;pass++)
  {
	//in each pass, compare adjacent pairs and swap
	//  move largest number to the right...
	for (int i=0;i<rightEnd-1;i++)
	{
		if (info[i]>info[i+1])
		{
			tmp = info[i];
			info[i] = info[i+1];
			info[i+1] = tmp;
		}
	}
	rightEnd--; //info[rightEnd] does nto need to be touched... 
  }
}

// sort in ascending order
void UnsortedType::SelectionSort()
{
     int lagrestIndex;
     int rightEnd;

     rightEnd = length-1;

     for (int pass=0;pass<length-1;pass++)
     {
	largestIndex = LargestItemIndex (0,rightEnd);

	if (largestIndex!=rightEnd)
	{
		tmp = info[largestIndex];
		info[largestIndex] = info[rightEnd];
		info[rightEnd] = tmp;
	}
	rightEnd--;
     }
}

