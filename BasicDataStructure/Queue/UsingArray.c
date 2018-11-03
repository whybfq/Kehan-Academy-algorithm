#include <cstdio>

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

int main(int argc, char* argv[]) {
    EnQueue(4);  // 4 enqueue
    DeQueue();   // 4 dequeue
    DeQueue();   // Queue is empty now
}

