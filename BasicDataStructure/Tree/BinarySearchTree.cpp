/******************************************************************
  * @copyright (C)  2018 sanner All Rights Reserved
  * @file: BinarySearchTree.cpp
  * @brief:
  *
  *
  * @date: Nov 2018
  * @bug : there seems to be some errors in the program. The root is always NULL 
  * .      and if you input 15 output expected is "found" while it would be "not found"
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
     1.@date:
       @author:
       @modification:
     2.@date:
       @author:
       @modification:
******************************************************************/
#include <iostream>

class BstNode {
public:
    bool Search(BstNode*root, int data);
    BstNode *Insert(BstNode *root, int data);
    BstNode *GetNewNode(int data);
private:
    int data;
    BstNode *left, *right;
};

bool BstNode::Search(BstNode*root, int data) {
    if(root == NULL) return false   ;
    else if(root->data == data) return true;
    else if(root <= root->left) return Search(root->left, data);
    else return Search(root->right, data);
}

BstNode *BstNode::GetNewNode(int data)
{
    BstNode *newnode = new BstNode();
    newnode->data = data;
    newnode->left = newnode->right = NULL  ;
    return newnode;
}

BstNode *BstNode::Insert(BstNode *root, int data)
{
    if(root == NULL) {
        BstNode *newnode = new BstNode();
        newnode->data = data;
        newnode->left = newnode->right = NULL;
        return newnode;
    }
    else if(data <= root->data) {
        root->left = Insert(root->left, data);
    } else {
        root->right = Insert(root->right,data);
    }
    return root;
}

int main(int argc, char* argv[]) {
    BstNode *root = NULL    ; // create an empty tree
    root->Insert(root,15);
    root->Insert(root,225);
    root->Insert(root,123);

    int number;
    std::cout << "Enter a number: ";
    std::cin >> number;
    if(root->Search(root,number)) {
        std::cout << "found" << std::endl;
    } else {
        std::cout << "not found" << std::endl;
    }
}
