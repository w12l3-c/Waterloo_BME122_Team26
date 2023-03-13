#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

class BinaryTreeNode {
    public:
        string iData;
        int key;
        BinaryTreeNode* left;
        BinaryTreeNode* right;

        BinaryTreeNode(int key, string data);
        ~BinaryTreeNode();
};

class BinaryTree{
    private:
        int SMALLEST_WIDTH = 5;
    public:
        BinaryTreeNode* root;
        int depth();
        void BFT();
        void DFT();
        void prettyPrint();

        ~BinaryTree();
};

int Height(BinaryTreeNode* T){
    if (T == NULL) return -1;
    else if (T->left == NULL && T->right == NULL){
        return 0;
    }
    else {
        return 1 + max(Height(T->left), Height(T->right));
    }
}

int BinaryTree::depth(){
    Height(root);
}

int Height2(BinaryTreeNode* T){
    int l_depth = T->left != nullptr ? Height2(T->left) : 0;
    int r_depth = T->left != nullptr ? Height2(T->right) : 0;
    return 1 + max(l_depth, r_depth);
}

BinaryTreeNode::BinaryTreeNode(int key, string data):key(key),iData(data),left(NULL),right(NULL){}

BinaryTreeNode::~BinaryTreeNode(){
    if (left != nullptr){
        delete left;
    }
    if (right != nullptr){
        delete right;
    }
}

BinaryTree::~BinaryTree(){
    if (root != nullptr){
        delete root;
    }
}

//Traversal

// Breath first
// first in - first out
// go through each level
void BinaryTree::BFT(){
    if (root==NULL){
        cout << "Tree is empty" << endl;
        return ;
    }
    queue<BinaryTreeNode*> Q;
    Q.push(root);
    while (!Q.empty()){
        BinaryTreeNode* P = Q.front();
        Q.pop();
        cout << P->iData << ', ';
        if (P->left != NULL) Q.push(P->left);
        if (P->right != NULL) Q.push(P->right);
    }
    cout << endl;
}

string centerPad(string value, int length){
    string str_value = value;
    float pad_length = (length - str_value.length())/2.0;

    return string(ceil(pad_length), ' ') + str_value + string(floor(pad_length), ' ');
}

void BinaryTree::prettyPrint(){
    int depth_val = depth();

    queue<BinaryTreeNode*> tree_queue;
    tree_queue.push(root);

    for(int level = 0; level < depth_val; level++){
        int width = pow(2, depth_val - level - 1) * SMALLEST_WIDTH;
        for(int i= 0; i < pow(2, level); i++){
            BinaryTreeNode* curr = tree_queue.front();
            tree_queue.pop();

            if (curr != nullptr){
                cout << centerPad(curr->iData, width);
                tree_queue.push(curr->left);
                tree_queue.push(curr->right);
            } else {
                cout << string(width, ' ');
                tree_queue.push(nullptr);
                tree_queue.push(nullptr);
            }
        }
        cout << endl;
    }
}

// Depth first
// go through each branch
void BinaryTree::DFT(){
    if (root == NULL){
        cout << "Tree is empty" << endl;
        return;
    }
    // PreOrder (root, left, then right)
    stack<string> pre;
    DFTPre(root, pre);
    cout << endl;
    // InOrder (left, root, then right)
    stack<string> in;
    DFTIn(root, in);
    cout << endl;
    // PostOrder (left, right, then root)
    stack<string> post;
    DFTPost(root, post);
    cout << endl;
    
}

void DFTPre(BinaryTreeNode* T, stack<string> S){
    if(T == NULL) return;
    S.push(T->iData);
    cout << T->iData << " ";
    DFTPre(T->left, S);
    DFTPre(T->right, S);
}

void DFTIn(BinaryTreeNode* T, stack<string> S){
    if (T == NULL) return;
    DFTIn(T->left, S);
    S.push(T->iData);
    cout << T->iData << " ";
    DFTIn(T->right, S);
}

void DFTPost(BinaryTreeNode* T, stack<string> S){
    if (T == NULL) return;
    DFTPost(T->left, S);
    DFTPost(T->right, S);
    S.push(T->iData);
    cout << T->iData << " ";
}

// Search
// each node k on the left is always smaller, and right is always larger
//BFS
string BFS(BinaryTreeNode* T, int K){
    if (T == nullptr)return "Searh failed. No such key";
    if (K == T->key)return T->iData;
    else if (K<T->key)return BFS(T->left, K);
    else return BFS(T->right, K);
}

//DFS



// Insert
bool insert(BinaryTreeNode** pT, BinaryTreeNode* N){
    BinaryTreeNode* T;
    T = *pT;
    if (*pT == nullptr){
        return true;
    }
    if (N->key == T->key){
        return false;
    }
    else if (N->key < T->key){
        if(T->left == nullptr){
            T->left = N;
            return true;
        }
        else return insert(&(T->left), N);
    }
    else {
        if(T->right == nullptr){
            T->right = N;
            return true;
        }
        else return insert(&(T->right), N);
    }
}

int main(){
    
    return 0;
}

