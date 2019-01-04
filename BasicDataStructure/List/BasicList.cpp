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
using std:: string;

struct Node {
    int data;
    Node *next;  // in C: struct Node *next
};

struct Node *head = nullptr; // global variable

void Insert(int x) {
    Node *temp = new Node(); //in C : Node *temp = (Node*)malloc(sizeof(Node));
    temp->data = x;
    temp->next = head; // temp->next = nullptr
                       // if(head != nullptr) temmp->next = head;
    head = temp;
}

////  if head is local variable
//void Insert1(Node **head,int x) {  // The following will become: Insert1(&head,x)
//    Node *temp = (Node*)malloc(sizeof(Node));
//    temp -> data = x;
//    temp -> next = *head;
//    *head = temp;
//}


// Node *Insert2(Node *head,int x) {  // The following will becom: head = Insert(head,x)
//     Node *temp = (Node*)malloc(sizeof(Node));
//     temp->data = x;
//     temp->next = head; // temp->next = nullptr
//                        // if(head != nullptr) temmp->next = head;
//     head   = temp;
//     return head;
// }

void Print() { //if we modify the haed will lose the reference of the first
    Node *temp = head;
    while(temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main(int argc, char* argv[]) {
    head = nullptr; // empty list
    cout << "How many numbers:" << endl;
    int n,i,x;
    cin >> n;
    for (int j = 0; j < n; ++j) {
        cout << "\nenter the number:\n" ;
        cin >> x;
        Insert(x);
        Print();
    }
}

Output:

How many numbers:
3

enter the number:
12
12 
enter the number:
23
23 12 
enter the number:
34
34 23 12 
