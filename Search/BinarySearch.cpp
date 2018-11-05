/*********************************************************************************
  * @copyright (C)  2018 sanner All Rights Reserved
  * @file:   BinarySearch.cpp
  * @brief:  Traversals (Inorder, Preorder and Postorder
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
       @modification:
     2.@date:
       @author:
       @modification:
**********************************************************************************/
#include <iostream>

using std:: cin ;
using std:: cout;
using std:: endl;

//using std:: unique_ptr;
//using std:: shared_ptr;
//using std:: make_unique;
//using std:: make_shared;

int BinarySearch(int A[], int n, int x) {
    int low = 0, high = n - 1;
    while (low <= high)  // attention <=
    {
        int mid = low + (high - low) / 2;   // int mid = (low + high) / 2; (low+high) may overflow
        if(x == A[mid]) return mid;
        else if(x < A[mid]) high = mid - 1;
        else low = mid + 1;
    }
    cout << "not found x ine A[]" << endl;
    return -1;
}

int main() {
    int A[] = {2,4,5,6,19};
    int n;
    cout << "Enter a number: ";
    cin >> n;
    int index = BinarySearch(A,5,n);
    if(index != -1) {
        cout <<  "number " << n << " is at " << index << endl;
    } else {
        cout << "not found" << endl;
    }
}

Input:

Enter a number: 5

Output:

number 5 is at 2
