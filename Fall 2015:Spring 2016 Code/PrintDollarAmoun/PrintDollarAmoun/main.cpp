/* Prints dollar amount in english
 * 2.43 would be two and 43/100
 * Author: Mario J. Merendino
 * Professor: Zhang
 * Last Modification: 1/22
 */

#include <iostream>
using namespace std;

void PrintInEnglish(int dollar, int cent);
void PrintDollar(int dollar);

int main(){
    char ans;
    do{
        double number;
        int num, decimal;
        bool test=true;
        cout << "Enter ther dollar amount:$ ";
        cin >> number;
        if (number > 9999){
            do{
                cout << " Please enter a number less than 10,000:$ ";
                cin >> number;
                test=false;
                if(number > 9999){
                    test=true;
                }
            }while(test);
        }
        num=number;
        decimal= ((number- num)*100+1);
        PrintInEnglish(num, decimal);
        cout << "Would you like to continue?(Y or N)" <<endl;
        cin >> ans;
    }while(ans== 'Y'|| ans== 'y');
    
}
void PrintInEnglish(int dollar, int cent){
    PrintDollar(dollar);
    cout << " dollars and " << cent << "/100 cents"<<endl;
}

void PrintDollar(int dollar){
    int hundred, tens, ones;
    string digits[10]={"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    string teens[10]={"ten","eleven", "twelve", "thirteeen", "fourteen", "fifteen", "sixteen", "seventeen", "eightteen", "nineteen"};
    string ty[10]={"zero", "ten", "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    if (dollar < 11){
        cout << digits[dollar];
    }
    if (dollar > 10 && dollar < 20){

    }
    
}