#include <string>
#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

// Width of elements at bottom of tree
const int SMALLEST_WIDTH = 5;

// Helper Function
string centerPad(int value, int length);

// Classes
class TreeNode {
  public:
    TreeNode(int value);
    ~TreeNode();
    int value;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
};

class Tree {
  public:
    TreeNode* root;
    ~Tree();
    int depth();
    void prettyPrint();
  private:
    int depth(TreeNode* node);
};

int Height(TreeNode* T) //const
// Returns the height of a tree T.
{
    if (T == nullptr)
        return 0;
    else {
        int heightLeft = Height(T->left);
        int heightRight = Height(T->right);
        if (heightLeft > heightRight)
            return heightLeft+ 1;
        else
            return heightRight+ 1;
    }
}

int Difference(TreeNode* T) //C++ example for checking imbalance
// Returns the difference between the heights of the left and right subtrees of T.
// Assumes the given TreeNode* T is not null.
{
    return Height(T->left) - Height(T->right);
}
    
TreeNode* RotateRight(TreeNode* T) 
{
    cout << "Right " << T->value << endl;
    TreeNode* S = T->left;
    TreeNode* B = S->right;
    S->right = T;
    T->left = B;
    return S;
}

TreeNode* RotateLeft(TreeNode* T) 
{
    cout << "Left " << T->value << endl;
    TreeNode* S = T->right;
    TreeNode* B = S->left;
    S->left = T;
    T->right = B;
    return S;
}

TreeNode* RotateLeftRight(TreeNode* T)
{
    cout << "LeftRight " << T->value << endl;
    TreeNode* S = T->left;
    T->left = RotateLeft(S);
    return RotateRight(T);
}

TreeNode* RotateRightLeft(TreeNode* T)
{
    cout << "RightLeft " << T->value << endl;
    
    TreeNode* S = T->right;
    T->right = RotateRight(S);
    return RotateLeft(T);
}

TreeNode* Balance(TreeNode* T) // C++ example
// Checks and balances the subtree T.
{
    int balanceFactor = Difference(T); // BF of a balanced node must be either -1, 0 or 1.
    if (balanceFactor> 1) {
        if (Difference(T->left) > 1)
            return RotateRight(T);
        else
            return RotateLeftRight(T);
    }
    else if (balanceFactor< -1) {
        if (Difference(T->right) < 0)
            return RotateLeft(T);
        else
            return RotateRightLeft(T);
    }
    else
        return T;
}

// TreeNode constructor
// Creates a new node with the given value
TreeNode::TreeNode(int new_value) : value(new_value) {
  // Intentionally left empty
}

// TreeNode destructor 
// Before a node is deleted, delete its child nodes
TreeNode::~TreeNode() {
  if (left != nullptr)
    delete left;
  if (right != nullptr)
    delete right;
}

// Tree destructor
// Deletes the root node. The TreeNode destructor will handle deleting the rest of the tree
Tree::~Tree() {
  if (root != nullptr)
    delete root;
}

// Public depth function
// Calls the private depth function with the correct argument
int Tree::depth() {
  return Height(root);
}

// Returns a string of a given length with the value centered in the string
// and the rest of the string filled with spaces
string centerPad(int value, int length) {
  string str_value = to_string(value); // Convert int to string

  // Calculate the length we need to add to each side
  float pad_length = (length - str_value.length())/2.0;

  // Concatenate spaces on either side of the value
  // Recall: ceil rounds up, floor rounds down
  return string(ceil(pad_length), ' ') + str_value + string(floor(pad_length), ' ');
}

// Prints the tree in a nicely formatted manner
void Tree::prettyPrint() {
  // Get the max depth of the tree
  int depth_val = depth();

  // Create a queue of tree nodes for BFS and add the root node to start
  queue<TreeNode*> tree_queue;
  tree_queue.push(root);

  // For each level in the tree
  for (int level = 0; level < depth_val; level++) {
    // Calculate the width using the depth and the current level
    // The width we are printing is constant on each level
    int width = pow(2, depth_val - level - 1) * SMALLEST_WIDTH;

    // For each element in the level
    // There are 2^level elements in the level since we are printing null elements
    for (int i = 0; i < pow(2, level); i++) {

      // Get element to print from queue
      TreeNode* curr = tree_queue.front();
      tree_queue.pop();

      // If element is not null, print it and, add left and right elements to the queue
      if (curr != nullptr) {
        cout << centerPad(curr->value, width);
        tree_queue.push(curr->left);
        tree_queue.push(curr->right);
      // If the element is null, print a blank string, and add nullptr's to the queue in place of
      // left and right elements
      } else {
        cout << string(width, ' ');
        tree_queue.push(nullptr);
        tree_queue.push(nullptr);
      }
    }
    // At the end of each level, print a newline
    cout << endl;
  }
}

int main() {
    Tree tree;
    tree.root = new TreeNode(10);
    tree.root->left = new TreeNode(5);
    tree.root->right = new TreeNode(15);
    tree.root->right->left = new TreeNode(12);
    tree.root->right->left->right = new TreeNode(14);
  
    // Note that Balance is usually called in the recursive function Insert/Delete
    // This allows it to balance subtrees regardless of size when needed
    // This balance call example is just for demonstration purposes
    cout << "Pre-Balanced Tree: " << endl;
    tree.prettyPrint();
    tree.root = Balance(tree.root);
    cout << "Post-Balanced Tree: " << endl;
    tree.prettyPrint();

    
}
