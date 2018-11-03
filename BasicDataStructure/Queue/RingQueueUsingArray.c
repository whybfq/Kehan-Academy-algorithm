/*********************************************************************************
  * @copyright (C)  2018 sanner All Rights Reserved
  * @file: RingQueueUsingArray.c   / QueueUsingArray2.c
  * @brief:  if current position = i
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
     1.@date: Nov 2018
       @author: sanner
       @modification: this modify the file QueueUsingArray.c
     2.@date:
       @author:
       @modification:
**********************************************************************************/
#include <stdio.h>

//struct Node {
//    int data;
//    Node *next;
//};
//
//Node *front = NULL;
//Node *rear = NULL;
//
//void EnQueue(int x) {
//    Node *temp = (Node*)malloc(sizeof(Node*));
//    temp->data = x;
//    temp->next = NULL;
//    if(front == NULL && rear == NULL) {
//        front= rear = temp;
//        return;
//    }
//    rear->next = temp;
//    rear = temp;
//}

const int MAX = 11;  // the number of array

int A[MAX] = {0};
int front = -1 ;
int rear  = -1 ;

void EnQueue(int x) {
    if((rear + 1) % MAX == front) {
        printf("Queue is full now " );
        return;
    } else if(rear == -1 && front == -1) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX ;
    }
    A[rear] = x;
    printf("%d enqueue\n",x ) ;
}

void DeQueue() {
    if(rear == -1 && front == -1) {
        printf( "Queue is empty now " );
        return;
    } else if( front == rear) {
        printf("%d dequeue\n", A[front] ) ;
        front = rear = -1;
    } else
    {
        front = (front + 1) % MAX;
    }
}

//int Front() { return A[front]; }

int main(int argc, char* argv[]) {
    EnQueue(5);  // 5 enqueue
    DeQueue();   // 5 dequeue
    DeQueue();   // Queue is empty now
}

