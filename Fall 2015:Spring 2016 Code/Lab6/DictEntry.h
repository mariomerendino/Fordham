#ifndef DICTENTRY_H
#define DICTENTRY_H
#include <iostream>
#include <string>
using namespace std;

class DictEntry {
friend ostream & operator<<(ostream & out, const DictEntry & obj);
public:
	DictEntry(string w="", string desc="");
	
 
	bool operator< (const DictEntry & entry) const;
	bool operator== (const DictEntry & entry) const;
	bool operator> (const DictEntry & entry) const;
    bool operator!= (const DictEntry & entry) const;
    void operator=(const DictEntry &);

	string GetWrod() const;

	string GetMeaning() const;

private:
	string word;
	string meaning;
};
#endif
