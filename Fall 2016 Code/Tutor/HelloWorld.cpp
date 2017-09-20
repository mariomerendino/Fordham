#include <iostream>
using namespace std;

int main(){
	
	//Variables
	int age;
	string name;
	char sex;
	double gassmileage;
	
	//Displays hello world
	cout << "Hello World";
	
	//Prompts user to entsdsasder their name 
	cout << "\nEnter your name\n";

	//User Enters name
	cin >> name;

	//Displays Name
	cout << "Your Name Is " << name << endl;

	//Ask user what favorite num is
	cout << "WHATS YOUR FAVORITE NUMBER" << endl;
	
	//Creates Two Numbers
	int num1;
	int num2;
	int num3;

	//User Inputs num
	cin >> num1;  

	//asks user what 2nd fav num is
	cout << "Whats ur 2nd fav num" << endl;

	cin >> num2;

	num3 = num1 + num2;

	cout << "Adding the numbers togther is... " << num3 << endl;
	
}
