/*********************************************************************************
  * @copyright (C)  2018 sanner All Rights Reserved
  * @file: StackUsingList.c
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

// C program for linked list implementation of stack
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// A structure to represent a stack
struct StackNode
{
    int data;
    struct StackNode* next;
};

struct StackNode* newNode(int data)
{
    struct StackNode* stackNode =
            (struct StackNode*) malloc(sizeof(struct StackNode));
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}

int isEmpty(struct StackNode *top)
{
    return !top;
}

void push(struct StackNode** top, int data)
{
    struct StackNode* stackNode = newNode(data);
    stackNode->next = *top;
    *top = stackNode;
    printf("%d pushed to stack\n", data);
}

int pop(struct StackNode** top)
{
    if (isEmpty(*top))
        return INT_MIN;
    struct StackNode* temp = *top;
    *top = (*top)->next;
    int popped = temp->data;
    free(temp);

    return popped;
}

int peek(struct StackNode* top)
{
    if (isEmpty(top))
        return INT_MIN;
    return top->data;
}

int main()
{
    struct StackNode* top = NULL;

    push(&top, 10);   // 10 pushed to stack
    push(&top, 20);   // 20 pushed to stack
    push(&top, 30);   // 30 pushed to stack

    printf("%d popped from stack\n", pop(&top));   // 30 popped from stack

    printf("Top element is %d\n", peek(top));    // Top element is 20

    return 0;
}
