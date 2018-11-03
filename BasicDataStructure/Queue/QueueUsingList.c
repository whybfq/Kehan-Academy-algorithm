/*********************************************************************************
  * @copyright (C)  2018 sanner All Rights Reserved
  * @file:  QueueUsingList.c   
  * @brief: RingQueue if current position = i
  *          next position = (i + 1) % N
  *          previous position = (i - 1 + N) % N
  *
  * @date: Nov 2018
  * @bug :
  * @author: sanner
  *
  * @CMAKE_CXX_STANDARD 98
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
#include <stdio.h>
#include <stdlib.h>

struct Node { // Queue - Liked list implementation
    int data;
    Node *next;
};

Node *front = NULL;
Node *rear = NULL;

void EnQueue(int x) {
    Node *temp = (Node*)malloc(sizeof(Node));
    printf( "%d enqueue \n",x);
    temp->data = x;
    temp->next = NULL;    // the end should be NULL
    if(front == NULL && rear == NULL) {  // There is no element
        front = rear = temp;
        return;
    } else{
        temp = rear->next;
        rear = temp;
    }
}

void DeQueue() {
    Node* temp = front;
    if(front == NULL) return;
    if(front == rear) {
        printf("The last element in the queue, %d dequeue\n",front->data);   
        front = rear = NULL;
    } else {
        printf("%d dequeue\n",front->data);
        front = front->next;
    }
    free(temp);
}

int main(int argc, char* argv[]) {
    EnQueue(2); // 2 enqueue
    EnQueue(6); // 6 enqueue
    DeQueue();  // 2 dequeue
}

