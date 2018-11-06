/*********************************************************************************
  * @copyright (C)  2018 sanner All Rights Reserved
  * @file:   QueueUsingList.cpp
  * @brief:  when it is a RingQueue :
  *          if current position = i
  *          next position = (i + 1) % N
  *          previous position = (i - 1 + N) % N
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
// #include <cstdlib>
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
    rear = NULL;
    front = NULL;
}

void Node::EnQueue(int x) {
    Node * temp = new Node(); // Node *temp = (Node*)malloc(sizeof(Node));
    temp->data = x;   
    temp->next = NULL;
    cout << x << " enqueue" << endl;   // for test
    if(front == NULL && rear == NULL) {  // no element in the queue
        front = rear = temp;
    } else {     // more than one element in the queue
        temp = rear->next;   
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
    node1.DeQueue();    // Only the last element is left in the queue
    node1.DeQueue();    // Queue is empty now
}

