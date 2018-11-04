/*********************************************************************************
  * @copyright (C)  2018 sanner All Rights Reserved
  * @file:  BinarySearchTree.cpp
  * @brief:
  *
  * @date: Nov 2018
  * @bug :
  * @author: sanner
  *
  * @CMAKE_CXX_STANDARD 14
  * @IDE: Clion 2018.2
  * @OS:  macOS 10.14
  *
  * @function_lists:
  *  1.  fg: void Swap(int A[] , int i, int j   -- exchange A[i] and A[j],dtype=int
     2.
  * @history:
     1.@date:
       @author:
       @modification: Original
     2.@date:
       @author:
       @modification:
**********************************************************************************/
#include <iostream>

using std:: cin ;
using std:: cout;
using std:: endl;

struct BstNode {
    int data;
    BstNode *left;
    BstNode *right;
};

// setting tree as empty
//BstNode *root = NULL; // store the address of root node

// using array or Linked List are the same
bool Search(BstNode* root, int data)  // O(n)
{
    if(root == NULL) return false;
    else if(root->data == data) return true;
    else if(data <= root->data) return Search(root->left, data);
    else return Search(root->right, data);
}

BstNode *GetNewNode(int data) {  // the first node
    BstNode *newNode = new BstNode();
    (*newNode).data = data; // newNode->data = data
    newNode->left = newNode->right = NULL;
    return newNode;
}

BstNode *Insert(BstNode *root, int data) {   // O(1) // this root is local variable
    if(root == NULL){ // empty tree
        root = GetNewNode(data);  // the first node
        return root;
    } else if (data <= root->data) { // data is less or equal (<=) than the root
        root->left = Insert(root->left,data);
    } else { // data is larger than root
        root->right = Insert(root->right,data);
    }
    return root;
}

int main(int argc, char* argv[]) {
     BstNode *root = NULL; // creat an empty tree
     root = Insert(root,15);
     root = Insert(root,10);
     root = Insert(root,20);

     int number;
    cout << "Enter number be searched\n";
    cin >> number;
    if(Search(root,number) == true)
        cout << "Found" << endl;
    else {
        cout << "not found" << endl;
    }
}

