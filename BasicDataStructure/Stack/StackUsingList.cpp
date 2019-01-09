
/*********************************************************************************
  * @copyright (C)  2019 sanner All Rights Reserved
  * @license: GPL
  * @version:
  * @data:    January, 2019
  * @file:    StackUsingList.cpp
  * @remark:  set(CMAKE_CXX_STANDARD 14)
  * @related:
  * @brief:   List implementation of stack Using C14
  * @bug :
  * @author:  sanner
  * @IDE:     Clion 2018.3
  * @OS:      macOS 10.14
  *
  * @function_lists:
  *  1.

  * @Revision:
     1.@date:
       @author:
       @modification:
**********************************************************************************/

#include <iostream>

using std:: cin;
using std:: cout;
using std:: endl;

class  Stack {   // a structure to represent a stack
public:
    Stack() ;
    void Push(int x);
    void Pop();
    bool IsEmpty();
private:
    int data;
    Stack *nextaddress;
    Stack *top ;
};

Stack::Stack() {
    top = NULL; //Null can also be the value of a pointer, which is the same as zero unless the CPU supports a special bit pattern for a null pointer.
    // Note: In C, the null macro may have the type void* but this is not allowed in C++.
}

bool Stack::IsEmpty() {
    if(top == NULL) {
        cout << "The stack is empty now" << endl;
        return  true;
    }
    else return false;
}

void Stack::Push(int x) {
    auto *temp = new Stack;  // malloc() nead headfile <stdlib.h> // Stack *temp = new Stack;
    printf("%d pushed into the stack\n", x);
    temp->data = x;
    temp->nextaddress = top;
    top = temp;
}

void Stack::Pop() {
    auto *temp = new Stack;
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
    Stack test;
    test.Push(3);
    test.Pop();
    test.Pop();
}

Output:
3 pushed into the stack
3 popped from stack
The stack is Empty now, can't pop any element

