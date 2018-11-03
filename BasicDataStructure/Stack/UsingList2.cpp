/*********************************************************************************
  * @copyright (C)  2018 sanner All Rights Reserved
  * @license: GPL
  * @version:
  * @file:  StackUsingList2.cpp
  * @brief:
  * @date: Nov 2018
  *
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
  * @Revision:
     1.@date:
       @author:
       @modification: Original
     2.@date:
       @author:
       @modification:
**********************************************************************************/
#include <iostream>

using std:: cin   ;
using std:: cout  ;
using std:: endl  ;
using std:: string;

class Node {
public:
    Node() ;
    void Push(int x);
    void Pop();
    bool IsEmpty();
    void Print();
private:
    int data;
    Node *nextaddress;
    Node *top;
};

Node::Node() {
    Node *top = NULL;
}

void Node::Push(int x) {
    Node *temp = (Node*)malloc(sizeof(Node*));
    cout << x << " pushed into the stack" << endl;

    temp->data = x;
    temp->nextaddress = top;
    top = temp;
}

bool Node::IsEmpty() {
    if(top == NULL) {
        cout << "the stack is empty now" << endl;
        return true;
    }
    else return false;
}

void Node::Pop() {
    Node *temp = (Node*)malloc(sizeof(Node*)) ;
    if(top == NULL) { cout << "stack underflow " << endl; }
    else {
        cout << top->data << " poped from the stack " << endl;
        temp = top;
        top = top->nextaddress;
    }
    free(temp);
}

void Node::Print() {
    Node *ptr;
    if(top == NULL) {
        cout << "stack is empty" << endl;
    } else {
        ptr = top;
        cout << "Stack elements are : " ;
        while(ptr != NULL) {
            cout << ptr->data << " ";
            ptr = ptr->nextaddress;
        }
    }
    cout << endl;
}

int main() {
    int choice, value;
    Node node1;
    cout<<"1) Push in stack"<<endl;
    cout<<"2) Pop from stack"<<endl;
    cout<<"3) Display stack"<<endl;
    cout<<"4) Exit"<<endl;
    do {
        std::cin >> choice;
        switch(choice) {
            case 1:
            {
                cout<<"Enter value to be pushed:"<<endl;
                cin>>value;
                node1.Push(value);
                break;
            }
            case 2:
            {
                node1.Pop();
                break;
            }
            case 3:
            {
                node1.Print();
                break;
            }
            case 4:
            {
                 cout << "Exit now" << endl;
                 break;
            }
            default:
            {
                cout << "Invalid Choice" << endl;
            }

        }
    } while(choice != 4);
}
