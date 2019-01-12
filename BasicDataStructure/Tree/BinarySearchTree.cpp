/******************************************************************
  * @copyright (C)  2018 sanner All Rights Reserved
  * @file: BinarySearchTree.cpp
  * @brief:
  * @date: Jan 2019
  * @bug :
  * @author: sanner
  *
  * @CMAKE_CXX_STANDARD 14
  * @IDE:  Clion 2018.2
  * @OS:   macOS 10.14
  *
  * @function_lists:  2 steps
  *  1.   bool Search(BstNode* root, int data)  -> search a number in the tree
     2.BstNode *Insert(BstNode *root, int data) -> insert a number, return BstNode*
  * @history:
     1.@date: Jan 2019
       @author:
       @modification: choose root->Insert(root,15) to root=root->Insert(root,15);
     2.@date:
       @author:
       @modification:
******************************************************************/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class BstTree{
public:
    BstTree();
    BstTree *GetNewNode(int data);
    BstTree *Insert(BstTree *root,int data);
    bool Search(BstTree *root,int data);
private:
    int data;
    BstTree *left, *right;
};

BstTree::BstTree() {
    left = right = nullptr;
}

BstTree* BstTree::GetNewNode(int data) {
    BstTree *newnode = new BstTree();
    newnode->data = data;
    newnode->left = newnode->right = nullptr;
    return newnode;
}

BstTree* BstTree::Insert(BstTree *root, int data) {
    if(root == nullptr) {
        return  GetNewNode(data);
    } else if(data <= root->data) {
        root->left = Insert(root->left, data);
    } else {
        root->right = Insert(root->right, data);
    }
    return root;
}

bool BstTree::Search(BstTree *root, int data) {
    if(root == nullptr) return false;
    else if(data == root->data) return true;
    else if(data <= root->data) return Search(root->left, data);
    else return Search(root->right,data);
}

int main(int argc, char* argv[]) {
    BstTree *root = nullptr;   // create an empty tree
    root = root->Insert(root,15);
    root = root->Insert(root,223);
    root = root->Insert(root,123);

    int number;
    cout << "Enter a number: ";
    cin >> number;
    if(root->Search(root,number)) {
        cout << "found"  << endl;
    } else {
        cout << "not found"  << endl;
    }
}
