/*********************************************************************************
  * @copyright (C)  2018 sanner All Rights Reserved
  * @file: StackUsingArray.cpp {-bor}
  * @brief:
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

#include <iostream>

using namespace std;

const int MAX = 100;

class Stack {
public:
    Stack() { top = -1; stack[MAX] = {0}; }
    void push(int x);
    void pop();
    bool isEmpty();
    void Print();
    ~Stack() { };
private:
    int stack[MAX];
    int top;
};

void Stack::push(int x) {
    if(top >= (MAX-1)) {
        cout << "Stack Overflow";
    }
    else {
        cout << x << " pushed into stack" << endl;
        stack[++top] = x;
    }
}

void Stack::pop() {
    if(top < 0) {
        cout << "Stack Underflow";
    }
    cout << x << " poped fron the stack" << endl;
    --top;
}

bool Stack::isEmpty() {
    return (top < 0);
}

void Stack::Print() {
    if(top == -1) { cout << "\nempty now" ; }
    for (int i = 0; i <= top; ++i) {
        cout << "Stack now: "<< stack[i] << " ";
    }
}

int main(int argc, char* argv[]) {
    Stack s;
    s.push(10);  // 10 pushed into stack
    s.Print();   // Stack noe: 10
    s.pop();
    s.Print();   // empty now
}
