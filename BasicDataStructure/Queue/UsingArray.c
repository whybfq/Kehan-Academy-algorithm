#include <cstdio>

#define MAX 11

int A[MAX] = {0} ;

int front = -1 ;
int rear  = -1 ;

//bool IsEmpty() {
//    if(front == -1 && rear == -1) {
//        cout << "Queue is empty now " << endl;
//        return true;
//    }
//    else return false;
//}
//
//bool IsFull() {
//    if(rear == MAX - 1) {
//        cout << " Queue is full ";
//        return true;
//    } else
//    {
//        return false;
//    }
//}

void EnQueue(int x) {
    if(rear == MAX - 1) {
        printf("Queue is full now " );
        return;
    } else if(rear == -1 && front == -1) {
        front = rear =0;
    } else {
        rear += 1;
    }
    A[rear] = x;
    printf("%d enqueue",x ) ;
}

void DeQueue() {
    if(rear == -1 && front == -1) {
        printf( "Queue is empty now " );
        return;
    } else if( front == rear) {
        front = rear = -1;
    } else
    {
        printf("%d dequeue", A[front] ) ;
        front += 1;
    }
}

int main(int argc, char* argv[]) {
    EnQueue(4);  // 4 enqueue
    EnQueue(2);  // 2 enqueue
    DeQueue();   // 4 dequeue
}

