/* This program is a practice and demo of working with linked list 
 * Author: X. Zhang
 * Feb 29, 2016
 */
#include <iostream>
using namespace std;

//1. define a struct type named IntNodeType that includes a int and pointer 
// (to a IntNodeType) field 
struct IntNodeType {
   int value;
   IntNodeType * next;
   
   IntNodeType (int v=0, IntNodeType * p=NULL):value(v),next(p)
   {

   }
};

/* Displaying a linked list of IntNodType
 @head: address of the first node 
*/
void ResetZero (IntNodeType * head){
    IntNodeType * p;
    
    p = head;   //initialize pointer p to point to the first node in the linked list
    
    while (p!=NULL)
    {
        p->value=0;
        p = p->next;
    }
    //DisplayLinkedList(p);
}
void DisplayLinkedList (IntNodeType * head)
{
   IntNodeType * p;

    p = head;   //initialize pointer p to point to the first node in the linked list 

    while (p!=NULL)
    {
    cout <<"value: " << p->value <<endl;
	cout <<"pointer to next" <<p->next <<endl;
	p = p->next;  //update p to point to next node in the linked list ... 
    }


}

/* delete (deallocate) all nodes in the linked list given by the head pointer
 postcondition: all nodes in the linked list are deleted
                head is set to NULL
 */
/*void DeleteLinkedList (IntNodeType * & head)
{
	//Todo by you 
}*/

/* Search for given value in the listed list pointed to by firstNodePtr
 @param firstNodePtr 
 @param value 
 @return value: 
*/

IntNodeType * Search (IntNodeType * firstNodePtr, int value)
{
    IntNodeType * p;
    
    p = firstNodePtr;   //initialize pointer p to point to the first node in the linked list
    
    while (p!=NULL)
    {
        if(p->value==value){
            return p;
        }
        p= p->next;
    }
    return p;
}


/* Search for given value in the listed list pointed to by firstNodePtr
 @param firstNodePtr 
 @param value 
 @postcondition: if the value is found in the linked list,
	the node's address will be returned, and
	prevNode will point to the node before; if not found, return NULL, prevNode is NULL 
 @return value: 
*/
/*IntNodeType * SearchToDelete (IntNodeType * firstNodePtr, int value,
		IntNodeType * & prevNode) 
{
    //Todo by you 
}*/

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

    //cur = SearchToDelete (firstPtr, value, prev);
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

int main()
{
    IntNodeType * head; //stores the address of the first node
    int value;


    //2. allocate the first node (and store its address in head)
    //   stores 0 into the int field,
    //   sets the pointer filed to NULL 
    head = new IntNodeType;

    cout <<"First node's address" << head <<endl; 
    head->value = 10;  //EZ: same as (*head).value = 10;
    head->next = NULL;  //EZ: (*head).next = NULL;


    //3. create a new node, 
    IntNodeType * tmp = new IntNodeType (30, NULL);
    cout <<"Second node's address" << tmp <<endl; 
    //link the first node with this new node
    //  by saving the new node's address to the first node's pointer field 
    head->next = tmp; 
    //alternatively, we can directly save the new node's address
    // into the head's node's next field: 
    //       head->next = new IntNodeType (30,NULL);

    // 4. create a new node, and save its address to 
    tmp = new IntNodeType (40, NULL);
    cout <<"third node's address" << tmp <<endl; 
    // link this new node into the list... 
    head->next->next = tmp;

    /////////////////////////////////////////////
    //Todo (1): Draw the memory diagram at this point .
    //Here we practice darwing memory diagram 
    /////////////////////////////////////////////


    cout <<"Display all nodes\n";
    /////////////////////////////////////////////
    //DISPLAY: Here we practice traversing the linked list //
    /////////////////////////////////////////////
    // 5. displaying the linked list (using head pointer) 
    //   It should be 10 -> 30 -> 40 
    DisplayLinkedList (head);
    cout << "\nInsert 0 as first node" <<endl;
    tmp = new IntNodeType (0, NULL);
    tmp->next=head;
    head=tmp;
    DisplayLinkedList(head);
    //cout << "RESET EVERYTHING TO ZERO" <<endl;
    //ResetZero(head);
    //DisplayLinkedList(head);

    //
    // Todo (2): What will be displayed if we call? 
    //
    // DisplayLinkedList (head->next); 


    // Todo (3): write a function to search for a value in the linked list, 
    // return the node's address if found, otherwise, return NULL. 
    // Test the above function to display the address of node containing 40. 

    /////////////////////////////////////////////
    //INSERT: Here we practice inserting new node into the linked list 
    /////////////////////////////////////////////

   // 6. How to insert a new node (with value set to 0)
   //    before first node  in the list ?
   //    After the insertion, the list should be 0 -> 10 -> 30 -> 40 
   //  Todo (4) 
   //

    // 7. How to insert a new node (with value set to 12) to follow node 30
    //  Afterwards, the list should be 0 -> 10 -> 30 -> 12 -> 40 
    // Todo (5)  
    //  Hint: 1. First going through the linked list to find the node that contains value
    //       30  
    //        2. Create the new node, and set it's next pointer 
    //        3. Set the node 30's next pointer  


    /////////////////////////////////////////////
    //DELETE: Here we practice delete node from the linked list 
    /////////////////////////////////////////////

    // 8. Delete the whole linked list 
    // Todo (6) Implement the DeleteLinkedList () function (see below) 
    //          Call it in here (main) .
    //          Display the new list... 

    //  Remove a value from the list
    /*char response;
    do {
      cout <<"What value do you want to remove?";
      cin >> value;
    
      if (Delete (head, value))
      {
    	cout <<"After deleting " << value<<endl;
        //Display the linked list list 
    	DisplayLinkedList (head); 
      } else
	cout <<"value not in the list " << value <<endl;

     cout <<"Delete more (y/n):";
     cin >> response;
   }while (response=='y');
   */
}
