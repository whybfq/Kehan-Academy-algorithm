/*********************************************************************************
  * @copyright (C)  2018 sanner All Rights Reserved
  * @license: GPL
  * @version:
  * @data:    Jan 2019
  * @file:    BasicList.cpp
  * @related:
  * @reference:
  * @brief:
  * @bug :
  * @author:  sanner
  *
  * @CMAKE_CXX_STANDARD 14
  * @IDE:     Clion 2018.3
  * @OS:      macOS 10.14
  *
  * @function_lists:
  *  1.
  * @Revision:
     1.@date:
       @author:
       @modification:
**********************************************************************************/

#include <iostream>

using std:: cin;
using std:: cout;
using std:: endl;
using std:: swap;
const int MAX = 10;

class Node {
public:
    Node();
    void Insert(int x);
    void Remove();
    void Print();
private:
    int A[MAX];
    int top;
};

Node::Node(){
    top = -1;
//    A[MAX] = {0};
}

void Node::Insert(int x) {
    if(top > MAX - 1) {
        cout << "it is full size now" << endl;
        return;
    }
    cout <<  x << " being inserted " << endl;
    A[++top] = x;
}

void Node::Remove() {
    if(top < 0) {
        cout << "It is alreay empty " << endl;
        return;
    }
    cout << A[top] << " is popped " << endl;
    --top;
}

void Node::Print() {
    if(top == -1) {
        cout << "the link is empty now " << endl;
    }
    for (int i = 0; i <= top; ++i) {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main(int argc, char* argv[]) {
    Node test;
    test.Insert(32);
    test.Insert(54);
    test.Remove();
    test.Print();
    test.Remove();
    test.Remove();

}
