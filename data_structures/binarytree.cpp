#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class BinaryTreeNode {
    public:
        char iData;
        BinaryTreeNode* left;
        BinaryTreeNode* right;

        BinaryTreeNode(char data);
};

class BinaryTree{
    public:
        BinaryTreeNode* root;
        int depth();
        void BFT();
        void DFT();
        char BFS();
        char DFS();
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

BinaryTreeNode::BinaryTreeNode(char data):iData(data),left(NULL),right(NULL){}

int BinaryTree::depth(){
    Height(root);
}

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

// Depth first
// go through each branch
void BinaryTree::DFT(){
    if (root == NULL){
        cout << "Tree is empty" << endl;
        return;
    }
    // PreOrder (root, left, then right)
    stack<char> pre;
    DFTPre(root, pre);
    cout << endl;
    // InOrder (left, root, then right)
    stack<char> in;
    DFTIn(root, in);
    cout << endl;
    // PostOrder (left, right, then root)
    stack<char> post;
    DFTPost(root, post);
    cout << endl;
    
}

void DFTPre(BinaryTreeNode* T, stack<char> S){
    if(T == NULL) return;
    S.push(T->iData);
    cout << T->iData << " ";
    DFTPre(T->left, S);
    DFTPre(T->right, S);
}

void DFTIn(BinaryTreeNode* T, stack<char> S){
    if (T == NULL) return;
    DFTIn(T->left, S);
    S.push(T->iData);
    cout << T->iData << " ";
    DFTIn(T->right, S);
}

void DFTPost(BinaryTreeNode* T, stack<char> S){
    if (T == NULL) return;
    DFTPost(T->left, S);
    DFTPost(T->right, S);
    S.push(T->iData);
    cout << T->iData << " ";
}

int main(){
    return 0;
}