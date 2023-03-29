#include <iostream>
#include <queue>
#include <cmath>
#include <string>

using namespace std;

// Width of elements at bottom of tree
const int SMALLEST_WIDTH = 5;

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

// Helper Function
string centerPad(int value, int length);

// Our main function just creates and displays a tree
int main() {
  Tree tree;
  tree.root = new TreeNode(10);
  tree.root->left = new TreeNode(3);
  tree.root->left->left = new TreeNode(1);
  tree.root->left->right = new TreeNode(2);
  tree.root->right = new TreeNode(12);
  tree.root->right->right = new TreeNode(0);

  tree.prettyPrint();
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
  return depth(root);
}

// Private depth function
// Returns the max depth/height of the tree
// Recursive function: The height of a tree is one more than the max height of its children
//
// a ? b : c is the ternary operator
// "x = a ? b : c;" is equivalent to:
//     if (a)
//       x = b;
//     else
//       x = c;
int Tree::depth(TreeNode* node) {
  int l_depth = node->left  != nullptr ? depth(node->left)  : 0;
  int r_depth = node->right != nullptr ? depth(node->right) : 0;
  return 1 + max(l_depth, r_depth);
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
