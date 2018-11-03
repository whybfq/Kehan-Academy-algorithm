reference: https://www.youtube.com/watch?v=sFVxsglODoo 

Array implementation of stack Using C98

#include <stdio.h>

#define MAX 101

int A[MAX] ;
int top = -1;
void Push(int x) {
    if(top > MAX - 1){ printf("Error, stack overflow!");
    top += 1;   // you can also use A[++top] = x;
    A[top] = x;
}

void Pop(){
    if(top == -1) {
        printf( "No element\n");
    }
    --top;
}

int Top(){ return  A[top]; }

bool IsEmpty() {    // or just use return (top < 0);
    if(top == -1) {
        printf("The stack is Empty now!\n" );
        return  true;
    }
    else return false;
}

void Print() {
    printf( "Stack: ");
    for (int j = 0; j <= top; ++j) {
        printf("%d " , A[j]);
    }
    printf("\n");
}

int main(void) {
    Push(2); Print();   // Stack: 2
    Push(5); Print();
    Pop(); Print();
    Pop(); Print();
    IsEmpty();
//    Push (12); Print();
}