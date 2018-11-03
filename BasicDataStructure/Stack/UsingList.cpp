/*********************************************************************************
  * @copyright (C)  2018 sanner All Rights Reserved
  * @license: GPL
  * @version:
  * @file:
  * @brief:
  *
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
  * @Revision:
     1.@date:
       @author:
       @modification: Original
     2.@date:
       @author:
       @modification:
**********************************************************************************/
#include <iostream>

using std:: cout  ;
using std:: endl  ;
using std:: string;

class  Node {   // a structure to represent a stack
public:
    Node() ;
    void Push(int x);
    void Pop();
    bool IsEmpty(){ return !top; }
private:
    int data;
    Node *nextaddress;
    Node *top ; 
};

Node::Node() { 
    Node *top = NULL; //Null can also be the value of a pointer, which is the same as zero unless the CPU supports a special bit pattern for a null pointer.
    // Note: In C, the null macro may have the type void* but this is not allowed in C++.
}

void Node::Push(int x) {
    Node *temp = new Node;  // malloc() nead headfile <stdlib.h>
    printf("%d pushed into the stack\n", x);
    temp->data = x;
    temp->nextaddress = top;
    top = temp;
}

void Node::Pop() {
    Node *temp = new Node;
    if(top == NULL) {  // if(IsEmpty())
        printf("The stack is Empty now, can't pop any element\n");
        return;   // stack is empty now
    }
    printf("%d popped from stack\n", top->data);
    temp = top;
    top = top->nextaddress;
    free(temp);
}

int main(void) {
    Node test;
    test.Push(3);
    test.Pop();
    test.Pop();
}
