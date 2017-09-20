#include <iostream>
#include <fstream>
#include <assert.h>
#include "sorted.h"
#include "DictEntry.h"

using namespace std;

//TODO: Change UnsortedType to SortedType ... 
bool InitDictFromFile (SortedType & dict, const char *fileName)
{
  ifstream inFile;		//declare a ifstream object

  // open the file
  inFile.open (fileName);	//connect the inFile with disk file 
  // given by path name fileName

  if (!inFile)			//if something went wrong, e.g., file nonexist,...
    {
      cerr << "failed to open " << fileName << endl;
      return false;
    }

  // keep reading a string from the file, put it into the dict
  while (!inFile.eof ())	//while we haven't reached end of file yet
    {
      string word;
      inFile >> word;
        if(inFile.eof()){
            break;
        }

	string meaning;
        getline (inFile, meaning);

	cout <<"Read word: " << word<<endl;
	cout <<"Read meaning: " << meaning<<endl;

	dict.PutItem (DictEntry (word, meaning));

    }

  inFile.close ();

  dict.Print();
  return true;
}


int main ()
{
  SortedType dict1, dict2, dict3;
  char cont; 
  string word;
  bool found;
  DictEntry result;

  InitDictFromFile (dict1, "words.txt");
  InitDictFromFile (dict2, "cswords.txt");
  dict3=dict1+dict2;
  dict3.Print();
  do {
	cout <<"Enter a word to check spell:";
        cin >> word;
    //dict3.DeleteItem(DictEntry(word));
    dict3.Print();
	result = dict3.GetItem (DictEntry (word),found);
	if (!found)
		cout <<"Not a word\n";
	else
	{
		cout <<"Found the word\n";
		cout <<"Meaning " << result.GetMeaning() <<endl;
	}
    

	cout <<"Continue?";
	cin >> cont;

  } while (cont=='Y' || cont=='y');

}
