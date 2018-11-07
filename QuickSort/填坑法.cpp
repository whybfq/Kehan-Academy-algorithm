/******************************************************************
  * @copyright (C)  2018 sanner All Rights Reserved
  * @file: QuickSort2.cpp
  * @brief:Using 填坑法 to implement the QuickSort()
  *
  *
  * @date: Nov 2018
  * @bug :
  * @author: sanner
  *
  * @CMAKE_CXX_STANDARD 14
  * @IDE:  Clion 2018.2
  * @OS:   macOS 10.14
  *
  * @function_lists:  2 steps
  *  1. partition(int *A, int s,int e)    -> partition 分割
     2. QuickSort(int *A, int s, int e)   -> recursion 递归
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
template <typename T>
T swap(T &a, T &b) {
    T c(a);
    a = b;
    b = c;
}

int partition(int *A, int s,int e){
    int pivot = e;
    while(s < e) {
        while(A[s] < A[pivot] && s < e) ++s;
        swap(A[s],A[pivot]);  pivot = s;
        while(A[e] >= A[pivot] && s < e) --e;
        swap(A[e],A[pivot]); pivot = e;
    }
//    A[e] = A[pivot];
    return pivot ;
}
                                               
void QuickSort(int *A, int s, int e) {
    if(s < e) {
        int pIndex = partition(A,s,e);
        QuickSort(A, s,pIndex-1);
        QuickSort(A,pIndex+1,e);
    }
}

int main(int argc, char* argv[]) {
    int A[] = {3,4,23,1,56};
    int n = sizeof(A) / sizeof(int);
    QuickSort(A,0,n);

    for (int i = 0; i < n; ++i) {
        cout << A[i] << " ";    // 1 3 4 23 56 
    }
}
