/* Mario J. Merendino
 * Professor Zhang
 * Linked List
 * Mar 8, 2016
 */
#include <iostream>
using namespace std;

// define a struct type named IntNodeType that includes a int and pointer 
// (to a IntNodeType) field 
struct IntNodeType {
   int value;
   IntNodeType * next;
   
   IntNodeType (int v=0, IntNodeType * p=NULL):value(v),next(p)
   {
	//intentionally empty
   }
};

/* Displaying a linked list of IntNodType
 @head: address of the first node 
*/
void DisplayLinkedList (IntNodeType * head); 

/* Create a new node to store the given value,
 * and make this new node the first of the linked lsit 
 @head: address of the first node, will be updated
 @value: 
*/
void InsertAtFront (IntNodeType * & head, int value);

/* Creaet a new node with the given value, and append it to the linked list
 *    given by the head pointer
 *    @param head: pointer pointing to the first node, NULL if the linked list is empty
 *    @param num: the int number to be saved in the node
 *    @return nothing
 *    */
void AppendInTheEnd (IntNodeType * & head, int num);

/* delete (deallocate) all nodes in the linked list given by the head pointer
 postcondition: all nodes in the linked list are deleted
                head is set to NULL
 */
void ClearLinkedList (IntNodeType * & head);

/* Search for given value in the listed list pointed to by firstNodePtr
 @param firstNodePtr: pointer to the head of the list 
 @param value : what value are we looking for 
 @return the address of the node that stores the matching value; if no match, return NULL
*/
IntNodeType * Search (IntNodeType * firstNodePtr, int value) ; 

/* Search for given value in the listed list pointed to by firstNodePtr,
 *  return the matching node's address, and 
 *  set its previous node's address in prevNode parameter
 @param firstNodePtr 
 @param value 
 @postcondition: if the value is found in the linked list,
	the node's address will be returned, and
	prevNode will point to the node before; if not found, return NULL, prevNode is NULL 
 @return value: same as Search... 
*/
IntNodeType * Search (IntNodeType * firstNodePtr, int value, IntNodeType * & prevNode);

/* Delete the node storing the given value from the linked list 
    //    1. Find the value in the list (i.e., find the pointer that points to the node),
    //       and also remembers the address of its previous node 
    //    2. If the node to be removed is not in the header, skip it in the list 
    //        (assign its next node's address to its prev node's next)
    //       otherwise set header to its next node's address 
    //    3. delete the node (to free up heap storage) 
 @param firstPtr: if the value is stored in the head, then firstPtr will be updated  
 @param value
 @return true if the value is removed; false if the value is not found 
*/
bool Delete (IntNodeType * & firstPtr, int value);

/* Create a linked list to store the values in array a
 @param a: the array of int values
 @param size: length of array
 @return the address of the first node
*/
IntNodeType *  InitList (int a[], int size); 

/* Split the given list into two with equal length
 If the list length is odd, the first list gets one element one than
 the second one
@param head: points to the first node of the linked list
@param firstHalf: upon return, points to the first node of first splitted list
@param secondHalf: upon return, points to the first node of the second half 
*/
void Split (IntNodeType * head, IntNodeType * & firstHalf, IntNodeType * &secondHalf);


/* Merge two list into two 
 @param list1: points to the first list
 @param list2: points to the second list 
 @return the address of the first node of the merged linked list (
  list1 element  -> list2 elements
 */
IntNodeType * Merge (IntNodeType * list1, IntNodeType * list2);
IntNodeType * modify(IntNodeType * list, int oldvalue, int newvalue); //Changes the value of a node, by taking in the old value, using the search function, then updating it with a new value
void * InsertInBetween(IntNodeType *list, int preValue, int newvalue); //Inserts A new value before a given value
			

int main()
{
    IntNodeType * head = NULL; //stores the address of the first node 
		//The above is an empty list 
    char op; 
    int value, beforeThis, afterThis;
    int newValue;
    int values[9]={1,2,3,4,5,6,7,8,9};
    IntNodeType * list;

    do {
        cout <<"*********Menu***************"<<endl;
    	cout <<"What you want to do:"<<endl;
	
    	cout <<"d: delete an value from the list\n"; 
    	cout <<"a: append an value to tne end of the list\n"; 
    	cout <<"i: insert an value to tne beginning of the list\n"; 
        cout <<"m: insert an value before an existing value \n";
    	cout <<"l: lookup a value and modify it in  the list\n"; 
        cout <<"c: break a list into two, merge back so that second half becomes first half\n";
        cout << "n: initalize a list using a predetremined array" <<endl;
    	cout <<"s: show the content of the list\n"; 
        cout <<"q: to exit\n";
        cout <<"*********Menu***************"<<endl;

        cin >> op;

 	switch (op)
	{
	   	case 'd':
			cout <<"What value do you want to remove:";
			cin >> value;

			cout <<"Before deleting:\n";
    			DisplayLinkedList (head); 
			
      			if (Delete (head, value)){
				cout <<"After deleting:\n";
    				DisplayLinkedList (head); 
      			} else
				cout <<"value not in the list " << value <<endl;
	
			break;

		case 'a':
			cout <<"what value do you want to append to list"<<endl;
			cin >> value;
            cout << "0" <<endl;
            AppendInTheEnd(head, value);
			cout <<"Before appending:\n";
            DisplayLinkedList (head);

			//Todo: write a function to append a new node to the end of the list
			// to st ore this new value 
			

			break;
		case 'i':
			cout <<"what value do you want to insert to beginning of  list"<<endl;
			cin >> value;

			cout <<"Before inserting:\n";
    			DisplayLinkedList (head); 

			//Todo: write a function to insert a new node to the end of the list
			// to st ore this new value, and call the function from here...
			InsertAtFront (head, value);

			cout <<"after inserting:\n";
            DisplayLinkedList (head);

			break;
		case 'l':
			cout <<"What value do you want to look up?";
			cin >> value;

			//Todo... Call the search() function

			cout <<"What new value do you want to assign to the node?";
			cin >> newValue; 

            modify(head, value, newValue);
            DisplayLinkedList(head);
			break;
		case 's':
			cout <<"Displaying the current list:"<<endl;
			DisplayLinkedList (head);
			break;

		case 'n':
			cout <<"Create a list from an array\n";

  			list = InitList (values, 9);

  			//Display the newly created list
  			DisplayLinkedList (list);
  			
  			//Todo: destroy the list...
  			ClearLinkedList (list);
  			break;
		case 'c': //Extra credit parts 
			cout <<"Cut the list into half in the middle\n";

			//Todo by you, calling your function that breaks
			//a list into two
			//
			
			//Display both lists using the DisplayLinkedList() functions
			//

			// Merge the two lists back, the second sublist goes first 
			//


			//Display the merged list
			break;
		case 'm':
			cout <<"What value do you want to insert in the middle?"<<endl;
			cin >> value;
			cout <<"Where to insert, before which value?"<<endl;
            cin >> beforeThis;
            InsertInBetween(head, beforeThis, value);
            DisplayLinkedList(head);

			//Todo by you 
		case 'q':
			cout <<"Exiting..."<<endl;

			//Call the DeleteLinkedList () function to deallocate 
			//all memory ...
            ClearLinkedList (head);
			break;
		default:
			cout <<"Unknown request\n";
	}
   } while (op!='q');
} 






/* Displaying a linked list of IntNodType
 @head: address of the first node 
*/
void DisplayLinkedList (IntNodeType * head)
{
   IntNodeType * p;

    p = head;   //initialize pointer p to point to the first node in the linked list 

    cout <<"Displaying the list: " << endl;
    cout <<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" <<endl;
    while (p!=NULL)
    {
        cout <<" Node at " << p << endl;
        cout <<" 	value:  " << p->value <<endl;
        cout <<"	next:   " <<p->next <<endl;
        p = p->next;  //update p to point to next node in the linked list ...
    }
    cout <<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" <<endl;


}

/* Create a new node to store the given value,
 * and make this new node the first of the linked lsit 
 @head: address of the first node, will be updated
 @value: 
*/
void InsertAtFront (IntNodeType * & head, int value)
{
	IntNodeType * p;

	p = new IntNodeType;

	p->value = value;
	p->next = head;

	head = p; 
}


/* Creaet a new node with the given value, and append it to the linked list
 *    given by the head pointer
 *    @param head: pointer pointing to the first node, NULL if the linked list is empty
 *    	if the linked list was empty, the head will point to the new node upon return
 *    @param num: the int number to be saved in the node
 *    @return nothing
 *    */
void AppendInTheEnd (IntNodeType * & head, int num)
{
    IntNodeType *tmp, *cur;
    tmp=new IntNodeType(num, NULL);
    cur=head;
    if(cur==NULL){
        IntNodeType * p;
        
        p = new IntNodeType;
        
        p->value = num;
        p->next = head;
        
        head = p;
    }
    else{
        while(cur->next!=NULL){
            cur=cur->next;
        }
        cur->next=tmp;
    }
}


/* Search for given value in the listed list pointed to by firstNodePtr
 @param firstNodePtr: pointer to the head of the list 
 @param value : what value are we looking for 
 @return the address of the node that stores the matching value; if no match, return NULL
*/
IntNodeType * Search (IntNodeType * firstNodePtr, int value) 
{
	IntNodeType * p;

	p = firstNodePtr;
	while (p!=NULL)
	{
		if (p->value==value)
			return p;
		p = p->next; //update p with the current node's next field 
	}
	return p;
}


/* Search for given value in the listed list pointed to by firstNodePtr,
 *  return the matching node's address, and 
 *  set its previous node's address in prevNode parameter
 @param firstNodePtr 
 @param value 
 @postcondition: if the value is found in the linked list,
	the node's address will be returned, and
	prevNode will point to the node before; if not found, return NULL, prevNode is NULL 
 @return value: same as Search... 
*/
IntNodeType * Search (IntNodeType * firstNodePtr, int value, IntNodeType * & prevNode)
{
    IntNodeType * p;
    
    p = firstNodePtr;
    prevNode=NULL;
    if(p->next==NULL){
        
    }
    else{
        while (p!=NULL)
        {
            if (p->value==value)
                return p;
            prevNode=p; //sets previous node to current node, then it updates the current node to one further postition 
            p = p->next; //update p with the current node's next field
        }
    }
    return p;
}

/* Delete the node storing the given value from the linked list 
    //    1. Find the value in the list (i.e., find the pointer that points to the node),
    //       and also remembers the address of its previous node 
    //    2. If the node to be removed is not in the header, skip it in the list 
    //        (assign its next node's address to its prev node's next)
    //       otherwise set header to its next node's address 
    //    3. delete the node (to free up heap storage) 
 @param firstPtr: if the value is stored in the head, then firstPtr will be updated  
 @param value
 @return true if the value is removed; false if the value is not found 
*/
bool Delete (IntNodeType * & firstPtr, int value)
{
    IntNodeType * prev, * cur;

    cur = Search (firstPtr, value, prev);
    if (cur==NULL)
	return false;
    else {
	// remove cur node from the linked list 
	if (prev!=NULL)
	{	//not the first one 
		prev->next = cur->next;   //bypass the cur node 
	} 
	else //cur is the first node 
		firstPtr = cur->next; //update the head pointer 

	delete cur; //deallocate the node itself 
	return true;
    }
}

/* Delete all nodes in the list (deallocate the memory)
 @param head: points to the first node in the list
 @postcondition: head will be set to NULL
*/
void ClearLinkedList (IntNodeType * & head)
{
    IntNodeType *cur=head;
    while(cur!=NULL){
        IntNodeType *temp=cur->next;
        delete cur;
        cur=temp;
    }
}

IntNodeType *  InitList (int a[], int size) //Initializes list using an array
{
    IntNodeType *n=NULL;
    n=new IntNodeType;
    for(int i=0; i<size; i++){ //loops through array
        AppendInTheEnd(n,a[i]); //inserts values using append in the end funct
    }
    return n;
}
IntNodeType * modify(IntNodeType *list, int oldvalue, int newvalue){
    IntNodeType *cur;
    cur= Search(list, oldvalue); //searches for node using value & sets the current pointer to the location it searched for.
    cur->value= newvalue; //updates node with new value
    return cur; //returns new list
}
void * InsertInBetween(IntNodeType *list, int preValue, int newvalue){
    IntNodeType *before, *middle, *cur;
    middle=new IntNodeType;
    cur=Search(list,preValue, before); //sets current to node with searched for value
    middle->value=newvalue; //sets new node with new value
    before->next=middle; //inserts value after the previous node
    middle->next=cur; //sets new nodes next value, to the current node.
}