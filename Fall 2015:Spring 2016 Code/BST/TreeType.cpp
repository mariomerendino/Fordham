#include <iostream>
#include <iomanip>
#include <vector>
#include <assert.h>
#include "TreeType.h"
using namespace std;

struct TreeNode
{
  ItemType info;
  TreeNode* left;
  TreeNode* right;
};
void sortedinput(TreeNode * root, int length);
void GetSmall(TreeNode * root, ItemType &);
bool TreeType::IsFull() const
// Returns true if there is no room for another item 
//  on the free store; false otherwise.
{
  TreeNode* location;
  try
  {
    location = new TreeNode;
    delete location;
    return false;
  }
  catch(std::bad_alloc exception)
  {
    return true;
  }
}
TreeType::TreeType (ItemType items[], int len)
{
    //Initialize the tree (binary search tree) with items given in the
    // array (length of the array is passed as "len"
    
    // You need to make the tree so that it's height is as short as possible
    
    // You should consider calling a recursive function to do so
    int start(0), end(len-1);
    root= sortedinput(items, start, end);
    
}
TreeNode * TreeType::sortedinput(ItemType words[], int left, int right){
    /* Base Case */
    if (left > right)
        return NULL;
    
    /* Get the middle element and make it root */
    int mid = (left + right)/2;
    TreeNode * cur= new TreeNode;
    cur->info= words[mid];
    
    /* Recursively construct the left subtree and make it
     left child of root */
    cur->left =  sortedinput(words, left, mid-1);
    
    /* Recursively construct the right subtree and make it
     right child of root */
    cur->right = sortedinput(words, mid+1, right);
    
    return cur;
}

bool TreeType::IsEmpty() const
// Returns true if the tree is empty; false otherwise.
{
  return root == NULL;
}

int CountNodes(TreeNode* tree);
bool BST(TreeNode * tree);
int TreeType::GetLength() const
// Calls recursive function CountNodes to count the 
// nodes in the tree.
{
  return CountNodes(root);
}


int CountNodes(TreeNode* tree)
// Post: returns the number of nodes in the tree.
{
  if (tree == NULL)
    return 0;
  else 
    return CountNodes(tree->left) + CountNodes(tree->right) + 1;
}

void Retrieve(TreeNode* tree, 
     ItemType& item, bool& found);

ItemType TreeType::GetItem(ItemType item, bool& found)
// Calls recursive function Retrieve to search the tree for item.
{
  Retrieve(root, item, found);
  return item;
}


void Retrieve(TreeNode* tree, 
     ItemType& item, bool& found)
// Recursively searches tree for item.
// Post: If there is an element someItem whose key matches item's,
//       found is true and item is set to a copy of someItem; 
//       otherwise found is false and item is unchanged.
{
  if (tree == NULL)
    found = false;                     // item is not found.
  else if (item < tree->info)      
    Retrieve(tree->left, item, found); // Search left subtree.
  else if (item > tree->info)
    Retrieve(tree->right, item, found);// Search right subtree.
  else
  {
    item = tree->info;                 // item is found.
    found = true;
   }
} 

void Insert(TreeNode*& tree, ItemType item);

void TreeType::PutItem(ItemType item)
// Calls recursive function Insert to insert item into tree.
{
  Insert(root, item);
}


void Insert(TreeNode*& tree, ItemType item)
// Inserts item into tree.
// Post:  item is in tree; search property is maintained.
{
  if (tree == NULL)
  {// Insertion place found.
    tree = new TreeNode;
    tree->right = NULL;
    tree->left = NULL;
    tree->info = item;
  }
  else if (item < tree->info)
    Insert(tree->left, item);    // Insert in left subtree.
  else
    Insert(tree->right, item);   // Insert in right subtree.
} 

void DeleteNode(TreeNode*& tree);

void Delete(TreeNode*& tree, ItemType item);

void TreeType::DeleteItem(ItemType item)
// Calls recursive function Delete to delete item from tree.
{
  Delete(root, item);
}


void Delete(TreeNode*& tree, ItemType item)
// Deletes item from tree.
// Post:  item is not in tree.
{
  if (item < tree->info)
    Delete(tree->left, item);   // Look in left subtree.
  else if (item > tree->info)
    Delete(tree->right, item);  // Look in right subtree.
  else
    DeleteNode(tree);           // Node found; call DeleteNode.
}   

void  GetLargest(TreeNode* tree, ItemType& data);

void DeleteNode(TreeNode*& tree)
// Deletes the node pointed to by tree.
// Post: The user's data in the node pointed to by tree is no 
//       longer in the tree.  If tree is a leaf node or has only one 
//       non-NULL child pointer the node pointed to by tree is 
//       deleted, and tree is updated to point to the non-NULL child,
//       otherwise, the user's data is replaced by its 
//       logical predecessor and the predecessor's node is deleted.
{
  ItemType data;
  TreeNode* tempPtr;

  tempPtr = tree;
  if (tree->left == NULL)
  {
    tree = tree->right;
    delete tempPtr;
  }
  else if (tree->right == NULL)
  {
    tree = tree->left;
    delete tempPtr;
  }
  else
  {
    GetSmall(tree->right, data);
    tree->info = data;
    Delete(tree->right, data);  // Delete predecessor node.
  }
}

void GetLargest(TreeNode* tree, ItemType& data)
// Sets data to the info member of the right-most node in tree.
// i.e., the largest item 
{

  while (tree->right != NULL)
  {
    tree = tree->right;
  }
  data = tree->info;
}

void PrintTree(TreeNode* tree, std::ostream& outFile)
// Prints info member of items in tree in sorted order on outFile.
{
  if (tree != NULL)
  {
    PrintTree(tree->left, outFile);   // Print left subtree.
    outFile << tree->info;
    PrintTree(tree->right, outFile);  // Print right subtree.
  }
}

void TreeType::Print(std::ostream& outFile) const
// Calls recursive function Print to print items in the tree.
{
  PrintTree(root, outFile);
}

///////////////////////////////
//Pretty print
//
//Return the height of the tree that is rooted at the rootNode
int getHeight (TreeNode * rootNode)
{
   if (rootNode==NULL)
	return 0;
   else {
	int left = getHeight (rootNode->left);
        int right = getHeight (rootNode->right); 
	if (left<=right)
		return right+1;
        else
		return left+1;
   }
}

int TreeType::GetHeight() const
{
    return (getHeight(root));
}
 
//Store the nodes at the depth-level of the tree (given at root)
//in the vector of vals 
//Precondition: root!=NULL, depth >= 0 
void getLine (TreeNode * root, int depth, vector<char> & vals)
{
   assert (root!=NULL && depth>=0);

   if (depth==0){ //base case 
       	vals.push_back (root->info);
   } 
   else {	//general case ... 
   	if (root->left != NULL)
           getLine (root->left, depth-1, vals);
   	else //EZ if (depth-1<=0)
        {
	   int cnt=1;
	   for (int i=0;i<depth-1;i++)
		cnt*=2;
	   for (int i=0;i<cnt;i++)
           	vals.push_back ('#');
	} 
    
   	if (root->right!=NULL)
		getLine (root->right, depth-1, vals);
   	else //if (depth-1<=0)
        {
	   int cnt=1;
	   for (int i=0;i<depth-1;i++)
		cnt*=2;
	   for (int i=0;i<cnt;i++)
           	vals.push_back ('#');
	}
   } 

}

void printRow (TreeNode * p, int height, int depth)
{
	vector<char> vec;

        getLine(p, depth, vec);

/*
        for (int i=0;i<vec.size();i++) 
                if (vec[i] != ' ')
                        cout << vec[i] << " ";
                else 
		{
			assert (false);
			cout << "# " ;
		}
	cout <<endl;
*/

        cout << setw((height - depth)*2); // scale setw with depth
        bool toggle = true; // start with left
        if (vec.size() > 1) {
                //for (int v : vec) {
                for (int i=0; i<vec.size(); i++){
                        if (vec[i] != ' ') {
                                if (toggle)
                                        cout << "/" << "   ";
                                else
                                        cout << "\\" << "   "; //this will display 
                        }
                        toggle = !toggle;
                }
                cout << endl;
                cout << setw((height - depth)*2);
	}
        for (int i=0;i<vec.size();i++) 
                if (vec[i] != ' ')
                        cout << vec[i] << "   ";
        cout << endl;

}

void SimplePrintRow (TreeNode * p, int height, int depth)
{
	vector<char> vec;

        getLine(p, depth, vec);

        for (int i=0;i<vec.size();i++) 
                if (vec[i] != ' ')
                        cout << vec[i];
                else 
		{
			assert (false);
			cout << "# " ;
		}
	cout <<endl;

}

void TreeType::PrettyPrint () const
{
   int height = getHeight (root); //*2;
   for (int i=0;i<height;i++)
   {
       printRow (root, height, i);
   }
}


void TreeType::SimplePrettyPrint () const
{
   int height = getHeight (root); //*2;
   for (int i=0;i<height;i++)
   {
       SimplePrintRow (root, height, i);
   }
}
//Pretty print
///////////////////////////////



TreeType::TreeType()
{
  root = NULL;
}

void Destroy(TreeNode*& tree);

TreeType::~TreeType()
// Calls recursive function Destroy to destroy the tree.
{
  Destroy(root);
}


void Destroy(TreeNode*& tree)
// Post: tree is empty; nodes have been deallocated.
{
  if (tree != NULL)
  {
    Destroy(tree->left);
    Destroy(tree->right);
    delete tree;
  }
}

void TreeType::MakeEmpty()
{
  Destroy(root);
  root = NULL;
}


void CopyTree(TreeNode*& copy, 
     const TreeNode* originalTree);

TreeType::TreeType(const TreeType& originalTree)
// Calls recursive function CopyTree to copy originalTree 
//  into root.
{
  CopyTree(root, originalTree.root);
}

void TreeType::operator= 
     (const TreeType& originalTree)
// Calls recursive function CopyTree to copy originalTree 
// into root.
{
  {
  if (&originalTree == this)
    return;             // Ignore assigning self to self
  Destroy(root);      // Deallocate existing tree nodes
  CopyTree(root, originalTree.root);
  }

}
void CopyTree(TreeNode*& copy, 
     const TreeNode* originalTree)
// Post: copy is the root of a tree that is a duplicate 
//       of originalTree.
{
  if (originalTree == NULL)
    copy = NULL;
  else
  {
    copy = new TreeNode;
    copy->info = originalTree->info;
    CopyTree(copy->left, originalTree->left);
    CopyTree(copy->right, originalTree->right);
  }
}
// Function prototypes for auxiliary functions.

void PreOrder(TreeNode*, QueType&);
// Enqueues tree items in preorder.


void InOrder(TreeNode*, QueType&);
// Enqueues tree items in inorder.


void PostOrder(TreeNode*, QueType&);
// Enqueues tree items in postorder.


void TreeType::ResetTree(OrderType order)
// Calls function to create a queue of the tree elements in 
// the desired order.
{
  switch (order)
  {
    case PRE_ORDER : PreOrder(root, preQue);
                     break;
    case IN_ORDER  : InOrder(root, inQue);
                     break;
    case POST_ORDER: PostOrder(root, postQue);
                     break;
  }
}


void PreOrder(TreeNode* tree, 
     QueType& preQue)
// Post: preQue contains the tree items in preorder.
{
  if (tree != NULL)
  {
    preQue.Enqueue(tree->info);
    PreOrder(tree->left, preQue);
    PreOrder(tree->right, preQue);
  }
}


void InOrder(TreeNode* tree, 
     QueType& inQue)
// Post: inQue contains the tree items in inorder.
{
  if (tree != NULL)
  {
    InOrder(tree->left, inQue);
    inQue.Enqueue(tree->info);
    InOrder(tree->right, inQue);
  }
}


void PostOrder(TreeNode* tree, 
     QueType& postQue)
// Post: postQue contains the tree items in postorder.
{
  if (tree != NULL)
  {
    PostOrder(tree->left, postQue);
    PostOrder(tree->right, postQue);
    postQue.Enqueue(tree->info);
  }
}


ItemType TreeType::GetNextItem(OrderType order, bool& finished)
// Returns the next item in the desired order.
// Post: For the desired order, item is the next item in the queue.
//       If item is the last one in the queue, finished is true; 
//       otherwise finished is false.
{
  finished = false;
  ItemType item;
  switch (order)
  {
    case PRE_ORDER  : preQue.Dequeue(item);
                      if (preQue.IsEmpty())
                        finished = true;
                      break;
    case IN_ORDER   : inQue.Dequeue(item);
                      if (inQue.IsEmpty())
                        finished = true;
                      break;
    case  POST_ORDER: postQue.Dequeue(item);
                      if (postQue.IsEmpty())
                        finished = true;
                      break;
  }
  return item;
}
void GetSmall (TreeNode * root, ItemType & smallest)
{
    if (root->left==NULL){
        smallest=root->info;
    }
    else{
        GetSmall(root->left, smallest);
    }
}

void TreeType::GetSmallest (ItemType & smallest) const
{
    GetSmall(root, smallest);
}
bool TreeType::isBst(){
    return BST(root);
}
bool BST(TreeNode * tree){
    if (tree == NULL)
        return true;
    if (tree->left != NULL && tree->left->info > tree->info)
        return false;
        
        /* false if right is < than node */
    if (tree->right != NULL && tree->right->info < tree->info)
        return false;
        
        /* false if, recursively, the left or right is not a BST */
    if (!BST(tree->left) || !BST(tree->right))
        return false;
        
        /* passing all that, it's a BST */
    return true;
}

void ancestors(TreeNode * tree, ItemType item);
void ancestors(TreeNode * tree, ItemType item){
    cout << tree->info << " ";
    if (item < tree->info)
        ancestors(tree->left, item);   // Look in left subtree.
    else if (item > tree->info)
        ancestors(tree->right, item);
}
void TreeType::printancestors(ItemType item){
    ancestors(root, item);
}