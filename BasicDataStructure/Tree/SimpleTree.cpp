/******************************************************************
  * @copyright (C)  2018 sanner All Rights Reserved
  * @file:  SimpleTree.cpp
  * @brief: 
  *
  *
  * @date: Nov 2018
  * @bug :
  * @author: sanner
  *
  * @CMAKE_CXX_STANDARD 14
  * @IDE:  Clion 2018.2
  * @OS:   macOS 10.14
  *
  * @function_lists:  2 steps
  *  1. printPreorder    ->    <root><left-subtree><right-subtree>
     2.
  * @history:
     1.@date:
       @author:
       @modification:
     2.@date:
       @author:
       @modification:
******************************************************************/
#include <iostream>

class Tree {
public:
    Tree (int data) ;
    void printPreorder(Tree *node) ;
    Tree *left;
    Tree *right;
private:
    int data;
};

Tree::Tree(int data){
    this->data = data;
    left = right = NULL;
}

void Tree::printPreorder(Tree *node) {
    if(node == NULL) return;
    std::cout << node->data << " ";
    printPreorder(node->left);
    printPreorder(node->right);
}

int main(int argc, char* argv[]) {
    Tree *root = new Tree(1);
    root->left = new Tree(4);
    root->right = new Tree(6);
    root->printPreorder(root);   // 1 4 6
}
