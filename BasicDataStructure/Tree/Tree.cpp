/*********************************************************************************
  * @copyright (C)  2018 sanner All Rights Reserved
  * @file:  Tree.cpp
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
       @modification: 
     2.@date:
       @author:
       @modification:
**********************************************************************************/
#include <iostream>

using std:: cin ;
using std:: cout;
using std:: endl;

// C program for different tree traversals

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
void printPostorder(struct Node* node)
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
void printInorder(struct Node* node)
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

    return 0;
}

