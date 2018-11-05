/*********************************************************************************
  * @copyright (C)  2018 sanner All Rights Reserved
  * @file:   Tree.cpp
  * @brief:  Traversals (Inorder, Preorder and Postorder
  *          Reference: https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/
  *
  * @date:   Nov 2018
  * @bug :
  * @author: sanner
  *
  * @CMAKE_CXX_STANDARD 14
  * @IDE:    Clion 2018.2
  * @OS:     macOS 10.14
  *
  * @function_lists:
  *  1.      fg: void Swap(int A[] , int i, int j   -- exchange A[i] and A[j],dtype=int
     2.
  * @history:
     1.@date:
       @author:
       @modification: 
     2.@date:
       @author:
       @modification:
**********************************************************************************/
#include <iostream>

using std:: cin ;
using std:: cout;
using std:: endl;

/* A binary tree node has data, pointer to left child
and a pointer to right child */
struct Node
{
    int data;
    struct Node* left, *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

/* Given a binary tree, print its nodes according to the
"bottom-up" postorder traversal. */
void printPostorder(struct Node* node)    // <root> <left-subtree> <right-subtree>
{
    if (node == NULL)
        return;

    // first recur on left subtree
    printPostorder(node->left);

    // then recur on right subtree
    printPostorder(node->right);

    // now deal with the node
    cout << node->data << " ";
}

/* Given a binary tree, print its nodes in inorder*/
void printInorder(struct Node* node)    // <left-subtree> <root> <right-subtree>
{
    if (node == NULL)
        return;

    /* first recur on left child */
    printInorder(node->left);

    /* then print the data of node */
    cout << node->data << " ";

    /* now recur on right child */
    printInorder(node->right);
}

/* Given a binary tree, print its nodes in preorder*/
void printPreorder(struct Node* node)
{
    if (node == NULL)
        return;

    /* first print data of node */
    cout << node->data << " ";

    /* then recur on left sutree */
    printPreorder(node->left);

    /* now recur on right subtree */
    printPreorder(node->right);
}

/* Driver program to test above functions*/
int main()
{
    struct Node *root = new Node(1);
    root->left			 = new Node(2);
    root->right		 = new Node(3);
    root->left->left	 = new Node(4);
    root->left->right = new Node(5);

    cout << "\nPreorder traversal of binary tree is \n";
    printPreorder(root);

    cout << "\nInorder traversal of binary tree is \n";
    printInorder(root);

    cout << "\nPostorder traversal of binary tree is \n";
    printPostorder(root);
}

Output:

Preorder traversal of binary tree is 
1 2 4 5 3 
Inorder traversal of binary tree is 
4 2 5 1 3 
Postorder traversal of binary tree is 
4 5 2 3 1
