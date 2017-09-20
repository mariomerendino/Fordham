/*
 *SpellChecker application 
 *Creates a dictionary from 2 text files
 *Author: Mario J. Merendino
 *Professor Zhang
 *Last modified: April 2, 2016
 */
#include <iostream>
#include "unsorted.h"
using namespace std;
int main()
{
    UnsortedType dict1, dict2;
    string word;
    bool exit=false;
    bool indict;
    dict1.InitDictFromFile (dict1, "wordsEn.txt"); //creates a dictionary of common words
    //dict2.InitDictFromFile (dict2, "cswords.txt");//creates a dictionary of CISC words
    
    UnsortedType dict; //creates a new dictionary
    //dict= dict1+dict2; //creates the union of both both dictionarys
    dict1.DisplayLinkedList();//displays new dictionary
    

    while (exit!=true){
        NodeType *p;
        p= dict1.GetList();
        indict=false;
        cout << "Enter words into spell check, to end type no: ";
        cin >> word;     // 1. Read a word from cin
        if (word=="no") // if word == no the program exits
        {
            exit=true;
        }
        else{
            while(p!=NULL){ //loops to the end of p
                if (p->info== word){
                    indict=true; //sets indict to be true if the word is found
                }
                p=p->next;
            }
            if(indict){ // if its in the dictionary it says spelled correctly
                cout << "Spelled Correctly" << endl;
            }
            else{
                cout << "Spelled Incorrectly" << endl;
            }
        }
        
    }
    
}

