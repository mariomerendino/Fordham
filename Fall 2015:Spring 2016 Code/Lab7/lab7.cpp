/* 
 * Source: 
 * http://www.coderslexicon.com/convert-infix-to-postfix-in-c/
 */
#include <iostream>
#include <stack>
#include <string>
#include <ctype.h>
using namespace std;


// Simply determine if character is one of the four standard operators.
bool isOperator(char character) {
	if (character == '+' || character == '-' || character == '*' || character == '/') {
		return true;
	}
	return false;
}


// If the character is not an operator or a parenthesis, then it is assumed to be an operand.
bool isOperand(char character) {
	if (!isOperator(character) && character != '(' && character != ')') {
		return true;
	}
	return false;
}


// Compare operator precedence of main operators.
// Return 0 if equal, -1 if op2 is less than op1, and 1 if op2 is greater than op1.
int compareOperators(char op1, char op2) {
	if ((op1 == '*' || op1 == '/') && (op2 == '+' || op2 == '-')) { return -1; }
	else if ((op1 == '+' || op1 == '-') && (op2 == '*' || op2 == '/')) { return 1; }
	return 0;
}


string InfixToPostfix (string infix)
{
	// Empty character stack and blank postfix string.
	stack<char> opStack;
	string postFixString = "";


	// Get a pointer to our character array.
	const char *cPtr = infix.c_str();

	// Loop through the array (one character at a time) until we reach the end of the string.
	while (*cPtr != '\0') {
		if (isOperand(*cPtr)) 
		{ 
			// If operand, simply add it to our postfix string.
			postFixString += *cPtr; 
		}
		else if (isOperator(*cPtr)) {
			// If it is an operator, pop operators off our stack until it is empty, 
			// an open parenthesis or an operator with less than or equal precedence.
			while (!opStack.empty() && opStack.top() != '(' && 
				compareOperators(opStack.top(),*cPtr) <= 0) {
				postFixString += opStack.top();
				opStack.pop();
			}
			opStack.push(*cPtr);
		}
		else if (*cPtr == '(') 
		{ 
			// Simply push all open parenthesis onto our stack
			opStack.push(*cPtr); 
		}
		else if (*cPtr == ')') {
			// When we reach a closing one, start popping off operators until we run into the opening parenthesis.
			while (!opStack.empty()) {
				if (opStack.top() == '(') { opStack.pop(); break; }
				postFixString += opStack.top();
				opStack.pop();
			}
		}

		// Advance our pointer to next character in string.
		cPtr++;
	}

	// After the input expression has been ran through, if there is any remaining operators left on the stack
	// pop them off and put them onto the postfix string.
	while (!opStack.empty()) {
		postFixString += opStack.top();
		opStack.pop();
	}


	// Show the postfix string at the end.
	//cout << "Postfix is: " << postFixString << endl;
	return postFixString;
}



/* return true if the expr string does not contain variables */ 
bool NoVariable (string postFix)
{
	int length=postFix.length();

	for (int i=0;i<length;i++)
		if (!isOperand(postFix[i]) && !isOperator(postFix[i])) {
			return true;
		}

	return false;
}


int evaluatePostfix (string postFix)
{
	/* algorithm: 
         Declare a stack of int to store the operands, and also the result of the subexpression 
 	 scan the expression from left to right, char by char 
	 i) if the char is a digit, push the digit's value into the stack
	 ii) if the char is an operand, pop two elements from the stack
              and apply the operation on the two elements, 
              push the result onto the stack 
         when reaching the end of the expression, the value in the stack is the result */
        // Declaring a Stack from Standard template library in C++.
    stack<int> eval;
    for (int i=0; i<postFix.length(); i++){
        if (isOperator(postFix[i])){
            int result;
            int operand2 = eval.top();
            eval.pop();
            int operand1 = eval.top();
            eval.pop();
            if(postFix[i] == '+'){
                result=operand1 +operand2;
            }
            else if(postFix[i] == '-'){
                result=operand1 - operand2;
            }
            else if(postFix[i] == '*'){
                result=operand1 * operand2;
            }
            else if(postFix[i] == '/'){
                result=operand1 / operand2;
            }
            eval.push(result);
        }
        else if(isdigit(postFix[i])){
            int operand = 0;
            operand=postFix[i]-'0';
            eval.push(operand);
        }
    }
    return eval.top();
}
int evaluatePrefix (string preFix)
{
    /* algorithm:
     Declare a stack of int to store the operands, and also the result of the subexpression
     scan the expression from left to right, char by char
     i) if the char is a digit, push the digit's value into the stack
     ii) if the char is an operand, pop two elements from the stack
     and apply the operation on the two elements,
     push the result onto the stack
     when reaching the end of the expression, the value in the stack is the result */
    // Declaring a Stack from Standard template library in C++.
    stack<int> eval;
    for (int i=0; i<preFix.length(); i++){
        if (isOperator(preFix[i])){
            int result;
            int operand2 = eval.top();
            eval.pop();
            int operand1 = eval.top();
            eval.pop();
            if(preFix[i] == '+'){
                result=operand1 +operand2;
            }
            else if(preFix[i] == '-'){
                result=operand1 - operand2;
            }
            else if(preFix[i] == '*'){
                result=operand1 * operand2;
            }
            else if(preFix[i] == '/'){
                result=operand1 / operand2;
            }
            eval.push(result);
        }
        else if(isdigit(preFix[i])){
            int operand = 0;
            operand=preFix[i]-'0';
            eval.push(operand);
        }
    }
    return eval.top();
}

/* Return the ending index for the prefix expressin start from start  */
/* Example: 
 *  expr: +ab, start: 0, return 2, as "+ab" is a prefix ("+", "+a" are not...)
 *  expr: +ab, start: 1, return 1; as "a" is a prefix ("ab" is not)...
 *  expr: +a*cd, start: 0, return 4, as "+a*cd" is a prefix expression ("+a", "+a*c"... are not) 
 *  expr: +a*cd, start 2, return 4, as ... 
 *  expr: *+ab-cd, start 1, return 3, as "+ab" is a prefix expression (not "+ab-",,...) 
 *  expr: *+ab-cd, start 0, return 6, ... */
int EndOfPrefix (string expr, int start)
{
    int index;
    if(isOperand(expr[start])){
        return start;
    }
    else{
        index=start+1;
        index=EndOfPrefix(expr, index);
        index++;
        return(EndOfPrefix(expr,index));
    }
}


//Return true if the expr is a valid prefix expression; else return false
bool IsPrefix (string expr)
{
    int lastchar=EndOfPrefix(expr,0);
    return(lastchar>=0 && (lastchar==expr.length()-1));
}

/* return a postfix expression for the given expression in prefix */
string PrefixToPostfix (string prefix)
{
    int prefixLength= prefix.length();
    char ch= prefix[0];
    string postExp;
    if(isOperand(ch)){
        postExp=postExp+ch;
    }
    else if (isOperator(ch)){
        int endFirst=EndOfPrefix(prefix, 1);
        postExp=postExp+PrefixToPostfix(prefix.substr(1,endFirst));
        postExp=postExp+PrefixToPostfix(prefix.substr(endFirst+1,prefixLength-1));
        postExp=postExp+ch;
    }
    return postExp;
}

int main()
{
   char cont;
   string expr;
   string postFix;

   do {
	cout <<"Enter an infix or prefix expression:";
	cin >> expr;

	if (IsPrefix (expr)) {
        postFix=PrefixToPostfix (expr);
        cout << "Value of prefix: " << evaluatePrefix(postFix) << endl;

	}
    else {
        postFix = InfixToPostfix (expr);
	}
	cout <<"Postfix is: " << postFix << endl;

	if (!NoVariable(postFix)){
		cout << "Value is " << evaluatePostfix(postFix)<<endl;
	}
	cout <<"Try again:(Y/N):";
	cin >> cont;

   } while (cont=='y' || cont=='Y');
}
