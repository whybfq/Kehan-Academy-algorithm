/*********************************************************************************
  * @copyright (C)  2018 sanner All Rights Reserved
  * @file:   SimpleExample.cpp
  * @brief:  Using swap method to partition
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
  *  1.   int Partition(int *A, int start, int end)     -> partition
     2.   int QuickSort(int *A, int start, int end)     -> recursion
  * @history:
     1.@date:
       @author:
       @modification:
     2.@date:
       @author:
       @modification:
**********************************************************************************/
#include <iostream>

using std:: cin ;
using std:: cout;
using std:: endl;
using std:: swap;
int Partition(int *A, int start, int end) {
    int pivot = A[end];
    int partitionIndex = start; // set partition index as start initially
    for (int i = start; i < end; ++i) {
        if(A[i] <= pivot)
        {
            swap(A[i],A[partitionIndex]); // swap if element is lesser than pivot
            ++partitionIndex;
        }
    }
    swap(A[partitionIndex],A[end]); // swap pivot with element at partition index
    return partitionIndex;
}

int QuickSort(int *A, int start, int end) {
//    if(start > end) return -1;
    if(start <= end) {
        int partitionIndex = Partition(A,start,end);
        QuickSort(A,start,partitionIndex-1);
        QuickSort(A,partitionIndex+1,end);  // attention partiionIndex+1
    }
}

int main() {
    int A[] = {1,8,34,2};
    int n = sizeof(A)/ sizeof(A[0]);  // n = 4
    QuickSort(A,0,n-1);
    for (int i = 0; i < n; ++i) {
        cout << A[i] << " ";
    }
}

