/* class definition for DollarAmount
 */
#ifndef DOLLARAMOUNT_H
#define DOLLARAMOUNT_H
using namespace std;

class DollarAmount{
public:
	/* precondition: d>=0, c>=0, c<100 */
	DollarAmount (int d=0, int c=0){
		dollar = d;
		cent = c;
	}

	/* postcondition: the dollar amount represented by 
 		the calling object is displayed in English */
	void PrintInEnglish();

	friend istream & operator >> (istream &in, DollarAmount & d);
	

	void print(ostream & stream) const;
	void input (istream & stream); 
	
	friend bool operator> (DollarAmount &, DollarAmount &);
        friend bool operator< (DollarAmount &, DollarAmount &);
        friend bool operator== (DollarAmount &, DollarAmount &); 
	

private:
	int dollar;
	int cent;

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
