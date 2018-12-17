/*********************************************************************************
  * @copyright (C)  2018 sanner All Rights Reserved
  * @file:   BasicBinarySearch.cpp .  
  * @brief:  A simple example for binary search
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

int BinarySearch(int A[], int n, int x) {
    int low = 0, high = n - 1;
    while (low <= high)  // attention <=
    {
        int mid = low + (high - low) / 2;   // int mid = (low + high) / 2; (low+high) may overflow
        if(x == A[mid]) return mid;
        else if(x < A[mid]) high = mid - 1; // or use recursive:  return BinarySearch(A, low, mid-1);
        else low = mid + 1;    // return BinarySearch(A,mid+1,high)
    }
    return -1;   //  cout << "not found x in A[]" << endl;
}

int main() {
    int A[] = {2,4,5,6,19};
    int n;
    cout << "Enter a number: ";
    cin >> n;
    int index = BinarySearch(A,5,n);
    if(index != -1) 
    {
        cout <<  "one number equal to " << n << " is at " << index << endl;
    } else 
    {
        cout << "not found " << endl;
    }
}

Input:
Enter a number: 5

Output:
one number equal to 5 is at 2
