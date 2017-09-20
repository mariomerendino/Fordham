#include <iostream>
#include "string.h"
using namespace std;
string replaceSpace(string s);
void ReplaceSpaceMod20(string str);
int main(){
    string str = "Hello World";
    cout << str << endl;
    string newStr = ReplaceSpaceMod20(string str);
    cout << newStr << endl;
}
string replaceSpace(string s){
    string newStr = s;
    int counter=0;
    //Loop through
    for(int i=0; i < s.length(); i++){
        //if the character is a space
        if( s[i] == ' '){
            //Resize string
            newStr.resize(newStr.length() + 3);
            //add characters
            newStr[counter] = '%';
            counter++;
            newStr[counter] = '2';
            counter++;
            newStr[counter] = '0';
        }
        //if its not a space, set it equal to the current value in the string
        else{
            newStr[counter] = s[i];
        }
        counter++;
       
    }
    return newStr;
}
void ReplaceSpaceMod20(string str) {
string replace_string = "20";
int counter = 0;
for (auto it = str.begin( ); it != str.end( ); ++it) {
    counter++;
	if (*it == ' ') {
		str.erase(it);
		str.insert(counter, replace_string);
	}
}
}