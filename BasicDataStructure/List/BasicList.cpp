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
#include <iomanip>
#include <cmath>
#include <cstring>
#include <string>

using std:: cin;
using std:: cout;
using std:: endl;
using std:: string;

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = nullptr; // global variable

void Insert(int x) {
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->data = x;
    temp->next = head; // temp->next = nullptr
                       // if(head != nullptr) temmp->next = head;
    head = temp;
}

void Print() {
    Node *temp = head;
    while(temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main(int argc, char* argv[]) {
    Node *head = nullptr; // empty list
    cout << "How many numbers " << endl;
    int n,i,x;
    cin >> n;
    for (int j = 0; j < n; ++j) {
        cout << "enter the number " << endl;
        cin >> x;
        Insert(x);
        Print();
    }
}


Output:

How many numbers 
3
enter the number 
1
1 enter the number 
3
3 1 enter the number 
5
5 3 1 
Process finished with exit code 