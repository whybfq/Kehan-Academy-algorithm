/*********************************************************************************
  * @copyright (C)  2018 sanner All Rights Reserved
  * @file:   BinarySearchTree.cpp
  * @brief:  setting tree as empty
  * .        BstNode *root = NULL; // store the address of root node
  *
  * @date: Nov 2018
  * @bug :
  * @author: sanner
  *
  * @CMAKE_CXX_STANDARD 14
  * @IDE:    Clion 2018.2
  * @OS:     macOS 10.14
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
    struct BstNode *left, *right;
};

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
    if(root == NULL){ // empty tree    // (root->left == NULL && root->right=NULL) means maybe only one node
        return GetNewNode(data); // the first node//  root is local variable so return type of insert function will not be void
    } else if (data <= root->data) { // data is less or equal (<=) than the root
        root->left = Insert(root->left,data);  // !!Note the root->left in the beginning
    } else { // data is larger than root
        root->right = Insert(root->right,data);  // Note the root->right in the beginning
    }
    return root;
}

// another way to implement Insert() or you can use root as global variable
//void Insert1(BstNode** root, int data) { // using ** and The following call would be Insert(&root,25);
//    if(*root == NULL) {
//        *root = GetNewNode(data);
//    }
//}

int main(int argc, char* argv[]) {
     BstNode *root = NULL; // creat an empty tree
     root = Insert(root,15);
     root = Insert(root,10);
     root = Insert(root,20);

     int number;
     cout << "Enter number be searched\n";
     cin >> number;
     if(Search(root,number) )
         cout << "Found" << endl;
     else {
         cout << "not found" << endl;
     }
}

