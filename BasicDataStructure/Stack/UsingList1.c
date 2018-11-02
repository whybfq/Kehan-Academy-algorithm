#include <cstdio>
#include <stdlib.h>

struct Node {   // a structure to represent a stack
    int data;
    Node *nextaddress;
};

Node *top = NULL;    // insert from the head and the time should be O(1) if insert from the end of the list the time should be O(n)

void Push(int x) {
    printf("%d pushed into the stack\n", x);
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node*));  // malloc() nead headfile <stdlib.h>
    temp->data = x;
    temp->nextaddress = top;
    top = temp;
}

void Pop() {
    Node *temp;
    if(top == NULL) {
        printf("The stack is Empty now, can't pop any element\n");
        return;   // stack is empty now
    }
    printf("%d popped from stack\n", top->data);
    temp = top;
    top = top->nextaddress;
    free(temp);
}

//int IsEmpty(struct Node *top) {
//    return !top;
//}

int main(void) {
    Push(3);
    Push(5);
    Pop();
    Pop();
}
