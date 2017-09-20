#include <string>
#include <fstream>
typedef char ItemType;
struct TreeNode;
#include "QueType.h"
enum OrderType {PRE_ORDER, IN_ORDER, POST_ORDER};
class TreeType
{
public:
  TreeType();                     // constructor
 ~TreeType();                    // destructor
  TreeType(const TreeType& originalTree);
    TreeType (ItemType items[], int len);
  void operator=(const TreeType& originalTree);
  // copy constructor
  void MakeEmpty();
  bool IsEmpty() const;
  bool IsFull() const;
  bool isBst();
  int GetLength() const; 
  int GetHeight() const;
  ItemType GetItem(ItemType item, bool& found);
  void PutItem(ItemType item);
  void DeleteItem(ItemType item);
  void ResetTree(OrderType order); 
  ItemType GetNextItem(OrderType order, bool& finished);
  void Print(std::ostream& out) const;
  void PrettyPrint() const;
  void SimplePrettyPrint() const;
  void GetSmallest(ItemType &)const;
  void printancestors(ItemType);
    TreeNode * sortedinput(ItemType words[], int left, int right);
private:
  TreeNode* root;
  QueType preQue;
  QueType inQue;
  QueType postQue;
};

