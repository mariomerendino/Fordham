#include <iostream>
#include "DictEntry.h"
using namespace std;


DictEntry::DictEntry(string w, string desc)
{
     word = w;
     meaning = desc;
}

ostream & operator<<(ostream & out, const DictEntry & obj)
{
   out <<obj.word<<":"<<obj.meaning<<endl;
   return out;
}
	
bool DictEntry::operator< (const DictEntry & entry) const
{
	return (word<entry.word);
}

bool DictEntry::operator== (const DictEntry & entry) const
{
	return (word==entry.word);
}

bool DictEntry::operator> (const DictEntry & entry) const
{
	return (word>entry.word);
}

string DictEntry::GetWrod() const
{
 	return word;
}

string DictEntry::GetMeaning() const
{
	return meaning;
}
bool DictEntry::operator!= (const DictEntry & entry) const
{
    return (word!=entry.word);
}
void DictEntry::operator=(const DictEntry & entry){
    word=entry.word;
    meaning=entry.meaning;
}
