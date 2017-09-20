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

	/* comparing calling object with op2 */
	bool operator> (DollarAmount & op2) const; 
	
	DollarAmount operator+ (const DollarAmount & right) const;
	
	DollarAmount operator/ (int divisor) const;

	friend istream & operator >> (istream &in, DollarAmount & d);
	
	friend ostream & operator<< (ostream &out, const DollarAmount & d);
	friend bool operator== (const DollarAmount & left, const DollarAmount & right);

	virtual void print(ostream & stream) const;
	virtual void input (istream & stream); 
	
	//EZ: return true if the dollar is -1 
	bool isTerminator() const;

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
