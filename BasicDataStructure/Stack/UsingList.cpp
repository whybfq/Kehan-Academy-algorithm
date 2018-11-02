#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

class  Node {   // a structure to represent a stack
public:
    void Push(int x);
    void Pop();
private:
    int data;
    struct Node *nextaddress;
    struct Node *top = NULL;
};

void Node::Push(int x) {
    printf("%d pushed into the stack\n", x);
    struct Node *temp = new(struct Node);  // malloc() nead headfile <stdlib.h>
    temp->data = x;
    temp->nextaddress = top;
    top = temp;
}

void Node::Pop() {
    struct Node *temp;
    if(top == NULL) {
        printf("The stack is Empty now, can't pop any element\n");
        return;   // stack is empty now
    }
    printf("%d popped from stack\n", top->data);
    temp = top;
    top = top->nextaddress;
    free(temp);
}

int main(void) {
    Node test;
    test.Push(5);
    test.Push(3);
    test.Pop();
}


