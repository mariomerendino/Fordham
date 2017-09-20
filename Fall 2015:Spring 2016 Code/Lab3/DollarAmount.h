/*
 h. file, contains prototypes for Dollar Class
 Prints out a dollar amount in english
 Author: Mario J. Merendino
 Professor Zhang
 Last Modified: Feb 23, 2016
 Known bug: None
 */
#ifndef DOLLARAMOUNT_H
#define DOLLARAMOUNT_H
using namespace std;

class DollarAmount{
    friend DollarAmount operator+(DollarAmount &, DollarAmount &);
public:
	/* precondition: d>=0, c>=0, c<100 */
	DollarAmount (int d=0, int c=0){
		dollar = d;
		cent = c;
        DELIM=-1;
	}

	/* postcondition: the dollar amount represented by 
 		the calling object is displayed in English */
	void PrintInEnglish();

	friend istream & operator >> (istream &in, DollarAmount & d);
    friend ostream & operator << (ostream &out, const DollarAmount &d);
	

	void print(ostream & stream) const;
	void input (istream & stream);
    int getDELIM();
    int getdollar();
	
	friend bool operator> (DollarAmount &, DollarAmount &);
    friend bool operator< (DollarAmount &, DollarAmount &);
    friend bool operator== (DollarAmount &, DollarAmount &);
    friend DollarAmount operator/(DollarAmount &, int); // divison operator, used in median function

	

private:
	int dollar;
	int cent;
    int DELIM;

	/* some helper function to be used by PrintInEnglish */
	static void PrintDollar (int d);

	static void Print0_99 (int value);

	/* display ten, twenty, ..., nighty 
 	@param ten_digit: is the tenth digit's value
	@precondition: ten_digit has a value from 1 to 9
 	@postcondition: ...
	*/
	static void PrintTens (int ten_digit);

	static void PrintOnes (int one_digit);
	
	/* display eleven, ... nineteen 
	@param one_digit: the one-th digit
	@precondition: one_digit has a value from 1, 2, ...,9
	@postcondition: ... */
	static void PrintTeens (int one_digit);

}; 
#endif
