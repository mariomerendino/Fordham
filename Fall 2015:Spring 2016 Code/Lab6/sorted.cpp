// Implementation file for Unsorted.h

#include "sorted.h"
#include <assert.h>

//Just call parent's constructor 
SortedType::SortedType (int size):UnsortedType (size)
{
  // intentioannly empty body
}

//Just call parent's constructor 
SortedType::SortedType (const SortedType & other):UnsortedType (other)
{
  //intentially //empty body
}

void SortedType::PutItem(ItemType item)
// Post: item is in the list.
{
    if (length==size)
    {
        ItemType * tmp = new ItemType[size * 2];
        size *= 2;
        
        for (int i = 0; i < length; i++)
            tmp[i] = info[i];
        delete [] info;
        info = tmp;
    }
    if(length==0)
    {
        info[0] = item;
    }
    else
    {

        int index=length;
        while(index != 0 && index <=length)
        {
            info[index] = info[index - 1];
            
            if(item > info[index - 1])
            {
                info[index] = item;
                break;
            }
            index=index-1;
        }
    }
    length++;

}

void SortedType::DeleteItem(ItemType item)
// Pre:  item's key has been initialized.
//       An element in the list has a key that matches item's.
// Post: No element in the list has a key that matches item's.
{
    int left=0;
    int right=length-1;
    int midpoint= length/2;
    
    if(item==info[midpoint]){
    }
    else{
        while((info[midpoint] != item) && (left <= right))
        {
            if (info[midpoint] > item)
            {
                right = midpoint - 1;
            }
            else
            {
                left = midpoint + 1;
            }
            midpoint = (left + right) / 2;
        }
    }
    for (int i=midpoint; i<length; i++) {
        info[i] = info[i+1];
    }
    length--;

}

ItemType SortedType::GetItem(ItemType item, bool& found)
{
    int left=0;
    int right=length-1;
    int midpoint= length/2;

    if(item==info[midpoint]){
        return info[midpoint];
    }
    
    while((info[midpoint] != item) && (left <= right))
    {
        if (info[midpoint] > item)
        {
            right = midpoint - 1;
        }
        else
        {
            left = midpoint + 1;
        }
        midpoint = (left + right) / 2;
    }
    if (info[midpoint]==item){
        found=true;
    }
    else{
        found=false;
    }
    return info[midpoint];
}

ItemType SortedType::GetLargestItem() const
{
   return info[length-1];
}
SortedType SortedType::operator +(SortedType &x){
    SortedType u(20);
    int i1=0,i2=0,i=0;
    while(i1 < length && i2< x.length){
        if(info[i1] < x.info[i2]){
            u.info[i]=info[i1];
            i1++;
        }
        else{
            u.info[i]=x.info[i2];
            i2++;
        }
        i++;
    }
    if (i1 < length){
        u.info[i]= info[i1];
        i1++;
        i++;
    }
    if (i2 < x.length){
        u.info[i2]= x.info[i];
        i++;
        i2++;
    }
    u.length= i;
    return u;
}




