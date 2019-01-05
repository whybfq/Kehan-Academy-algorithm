    
  /*********************************************************************************
  * @copyright (C)  2018 sanner All Rights Reserved
  * @license: GPL
  * @version:
  * @data:    Jan, 2019
  * @file:    StackUsingArray.c
  * @remark:
  * @related: https://www.youtube.com/watch?v=sFVxsglODoo
  * @brief:   Array implementation of stack Using C98
  * @bug :
  * @author:  sanner
  *
  * @CMAKE_CXX_STANDARD 14
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

#include <stdio.h>

const int MAX = 100;

int stack[MAX] ;
int top = -1;

void Push(int x) {
    if(top > MAX - 1) {
        printf("Error, stack is overflow.\n");
    }
    stack[++top] = x;  // top += 1;  A[top] = x ;
}

void Pop() {
    if(top == -1) {
        printf("No element now\n");
    }
    --top;
}

int Top() { return  stack[top]; }

bool IsEmpty() {
    return top < 0;// if(top == -1){ printf("the stack is empty now\n"); return  true; }  return  false;
}

void Print() {
    printf("The Stack is: ");
    for (int i = 0; i <= top; ++i) {
        printf("%d ",stack[i]);
    }
    printf("\n");
}

int main(int argc, char* argv[]) {
    Push(2); Print();
    Push(14); Print();
    Pop(); Print();
    Pop(); Print();
    if(IsEmpty()) printf("The stack is empty now\n");
}
