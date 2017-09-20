// Test driver
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstring>

#include "TreeType.h"

using namespace std;
void bubblesort(char a[], int size);
int main()
{
  char command;        // operation to be executed
  
  char item;
  char ret;
  string orderItem;
  TreeType tree;
  OrderType order;
  bool found;
  bool finished;
  int numCommands;
  string str;
  char input[26];

  do
  { 
    cout <<"Choose what to do: \n";
    cout <<"-------------------------\n";
    cout <<"A: PutItem\n";
    cout <<"D: DeleteItem\n";
    cout <<"S: GetItem\n";
    cout <<"I: info. length, IsFull, height...\n";
    cout <<"P: PrintTree\n";
    cout <<"Q: SimplePrintTree\n";
    cout <<"R: (Iterator) ResetTree, GetNextItem\n";
    cout <<"C: MakeEmpty\n";
    cout <<"B: Build Tree from array\n";
    cout <<"E: Quit\n";
    cout <<"X: isBst\n";
    cout <<"Y: Print Ancestors\n";
    cout <<"F: GetSmallest\n";
    cout <<"O: InputString\n";
    cout <<"-------------------------\n";

    cin >> command; 
    switch (command) 
    { 
	case 'B': 
		cout <<"Enter a string of chars to build a tree:\n";
		cin >> str; 
	
		tree.MakeEmpty();
        	for (int i=0;i<str.length();i++)
		{
      			ret = tree.GetItem(str[i], found);
      			if (!found)
				tree.PutItem (str[i]);
		}
           	break; 
	case 'A': 
      		cout <<"Enter a char to insert:\n";
      		cin >> item; 

      		item = tree.GetItem(item, found);
      		if (found)
        		cout << item << " already in list." << endl;
      		else 
		{
      			tree.PutItem(item);
      			cout << item;
      			cout << " is inserted" << endl;
		}
    		break; 
	case 'D': 
      		cout <<"Enter a char to delete:\n";
      		cin >> item;
      		tree.DeleteItem(item);
      		cout << item;
      		cout << " is deleted" << endl;
		break;
    case 'S': 
      		cout <<"Enter a char to search:\n";
      		cin >> item;

      		item = tree.GetItem(item, found);
      		if (found)
        		cout << item << " found in list." << endl;
      		else cout << item  << " not in list."  << endl;  
		break;
	case 'I':
      		cout << "Number of nodes is " << tree.GetLength() << endl;
    		
      		cout << "Height of tree is " << tree.GetHeight() << endl;
    
      		if (tree.IsEmpty())
        		cout << "Tree is empty." << endl;
      		else cout << "Tree is not empty."  << endl;  

      		if (tree.IsFull())
        		cout << "Tree is full."  << endl;
      		else 
			cout << "Tree is not full." << endl;  
  		break; 
	case 'P': 
      		tree.PrettyPrint();
      		cout << endl;
		break;
	case 'Q':
      		tree.SimplePrettyPrint();
      		cout << endl;
		break;
	case 'R': 
		cout <<"traversal order (preorder, inorder or postorder)"; 
      		cin >> orderItem;
      		if (orderItem == "preorder")
        		order = PRE_ORDER;
      		else if (orderItem == "inorder")
        		order = IN_ORDER;
      		else order = POST_ORDER;    
         
		cout <<"traversing nodes in the given order:";
      		tree.ResetTree(order);
		do {
      			item = tree.GetNextItem(order,finished);
      			cout << item;
		} while (!finished); 
      		cout << endl;
		break;
    case 'X':
            if (tree.isBst()){
                cout << "It's a Binary Search Tree" << endl;
            }
            else{
                cout << "Its Not a BST" <<endl;
            }
            break;
	case 'C':
		tree.MakeEmpty();
      		cout << "Tree has been made empty." << endl;
		break;
	case 'E':
		cout <<"Ok, Exiting\n";
		break;
    case 'Y':
            cout << "Enter a value of an item in the BST: ";
            char val;
            cin >> val;
            tree.printancestors(val);
        break;
        case 'O':
        {
            cout << "Enter a String: ";
            cin >> input;
            bubblesort(input, strlen(input));
            TreeType words(input, strlen(input));
            words.PrettyPrint();
            break;
        }
    case 'F':
            char smallest;
            tree.GetSmallest(smallest);
            cout << "The Smallest value is: " << smallest;
            break;

	default:
		cout << " Command not recognized." << endl;
	}
  } while (command != 'E');
 
  return 0;
}


void bubblesort(char words[], int size){
    int last = size -1;//points to the index of last element in unsorted array
    //loops once for every element in array
    for ( int pass = 0; pass < size; pass++ )
    {
        //loop count decrements to account for portion of array that's been sorted
        for ( int k = 0; k <= last -1; k ++ )
        {
            if ( words[ k ] > words[ k+1 ] )
            {
                //swaps if number is greater
                ItemType temp;
                temp = words[ k+1 ];
                words [ k+1 ] = words [ k ];
                words [ k ] = temp;
            }
        }
        last = last -1;
    }
}


