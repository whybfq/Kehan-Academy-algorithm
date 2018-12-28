/******************************************************************
  * @copyright (C)  2018 sanner All Rights Reserved
  * @file:  QueueUsingList.cpp
  * @brief: Using list to implement the queue
  *         First in First out   / FIFO
  *         when it is a RingQueue :
  *            if current position = i
  *            next position = (i + 1) % N
  *            previous position = (i - 1 + N) % N
  *
  * @date:  Nov 2018
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
     3.   void Print()            -> print the elements in queue
  * @history:
     1.@date:
       @author:
       @modification:
     2.@date:
       @author:
       @modification:
******************************************************************/
#include <iostream>

using std:: cout;
using std:: endl;

class Node {
public:
    Node() ;
    void EnQueue(int x);
    void DeQueue();
    void Print();
    ~Node(){}
private:
    int data;
    Node *next;
    Node *rear;
    Node *front;
};

Node::Node(){
    rear = front = next = NULL;
}

void Node::EnQueue(int x) {
    Node * temp = new Node(); // Node *temp = (Node*)malloc(sizeof(Node));
    temp->data = x;   
    temp->next = NULL;
    cout << x << " enqueue" << endl;   // for test
    if(front == NULL && rear == NULL) {  // no element in the queue
        front = rear = temp;
    } else {     // more than one element in the queue
        temp = rear->next;   // temp = NULL;
        rear = temp;
    }
}

void Node::DeQueue() {
    Node *temp = front;
    if(front == NULL ){
        cout << "Queue is empty now" << endl;
    } else if(front == rear ){
        cout <<"The last element in queue: " << front->data << " dequeue" << endl;
        front = rear = NULL;
    } else {      // more than one element in the queue
        cout << front->data << " dequeue" << endl;
        front = front->next;
    }
    free(temp);
}

void Node::Print() {
    if(front == NULL) {
        cout << "empty" << endl;
    } else if(front == rear) { 
        cout << "only one element: " << front->data << endl;
    } else {
        while(front->next != NULL) {
            cout << front->data << " " ;
            front = front->next;
        }
    }
}

int main(int argc, char* argv[]) {
    Node node1;
    node1.EnQueue(5);   // 5 enqueue
    node1.Print();      // only one element: 5
    node1.DeQueue();    // The last element in queue
    node1.DeQueue();    // Queue is empty now

    node1.DeQueue();    // Queue is empty no
    node1.DeQueue();    // Queue is empty now
    node1.DeQueue();    // Queue is empty now
}
