/******************************************************************
  * @copyright (C)  2018 sanner All Rights Reserved
  * @file: QueueUsingArray.cpp
  * @brief:Using array to implement the queue
  *        First in First out   / FIFO
  *
  * @date: Nov 2018
  * @bug :
  * @author: sanner
  *
  * @CMAKE_CXX_STANDARD 14
  * @IDE:  Clion 2018.2
  * @OS:   macOS 10.14
  *
  * @function_lists:
  *  1.   void EnQueue(int x)     -> an element enter  the queue
     2.   void DeQueue()          -> an element out of the queue
  * @history:
     1.@date:
       @author:
       @modification:
     2.@date:
       @author:
       @modification:
******************************************************************/
#include <iostream>

//using std:: cin ;
using std:: cout;
using std:: endl;
//using std:: swap;

const int MAX = 101;

class Queue{
public:
    Queue();
    void EnQueue(int x);
    void DeQueue();
private:
    int front;
    int rear;
    int queue[MAX];
};

Queue::Queue(){
    front = rear = -1;
}

void Queue::EnQueue(int x) {
    if(rear == MAX-1) {
        cout << "Queue is full now " << endl;
        return;
    } else if (front == -1 && rear == -1){
        front = rear = 0;
    } else {
        ++rear;
    }
    cout << x << " enqueue " << endl; 
    queue[rear] = x;    //common steps of the above two steps
}

void Queue::DeQueue() {
    if(front == -1) {
        cout << "empty,can't dequeue" << endl; return;
    } else if(front == rear) {
        cout << queue[front] << " dequeue" << endl;
        front = rear = -1;
    } else {
        cout << queue[front] << " dequeue" << endl;
        ++front;
    }
}

int main(int argc, char* argv[]) {
    Queue queue1;
    queue1.EnQueue(5);   // 5 enqueue 
    queue1.EnQueue(4);   // 4 enqueue
    queue1.DeQueue();    // 5 dequeue
    return 0;
}
