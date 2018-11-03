/*********************************************************************************
  * @copyright (C)  2018 sanner All Rights Reserved
  * @file:   QueueUsingArray.c
  * @brief:  the basic implemention of queue using array
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

#define MAX 11

int A[MAX] = {0} ;
int front = -1 ;
int rear  = -1 ;

void EnQueue(int x) {
    if(rear == MAX - 1) {
        printf(" Queue is full now \n" );
        return;
    } else if(rear == -1 && front == -1) {
        front = rear =0;
    } else {
        ++rear ;
    }
    A[rear] = x;
    printf("%d enqueue\n",x ) ;
}

void DeQueue() {
    if(rear == -1 && front == -1) {
        printf( "Queue is empty now \n" );
        return;
    } else if( front == rear) {
        printf("%d dequeue\n", A[front] ) ;   // only one element stil should be output 
        front = rear = -1;    // then no element in the queue
    } else
    {
        ++front ;
    }
}

void Print() {
    if(front == -1 && rear == -1) {
        cout << " empty now \n" ;
        return ;
    }
    for (int i = front; i <= rear; ++i) {
        printf("Queue now: %d ",A[i]);
    }
}

int main(int argc, char* argv[]) {
    EnQueue(4);  // 4 enqueue
    DeQueue();   // 4 dequeue
    DeQueue();   // Queue is empty now
}

