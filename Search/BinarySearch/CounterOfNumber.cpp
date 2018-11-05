/*********************************************************************************
  * @copyright (C)  2018 sanner All Rights Reserved
  * @file:   BinarySearch2.cpp / CounterOfNumber.cpp
  * @brief:  Counter of n, assume the array is sorted first and some elements will appear multiple times
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

int BinarySearch(int A[], int n, int x,bool searchFirst) {
    int low = 0, high = n - 1;
    int result = -1;
    while (low <= high)  // attention <=
    {
        int mid = low + (high - low) / 2;   // int mid = (low + high) / 2; (low+high) may overflow
        if(x == A[mid])
        {
            result = mid;
            if(searchFirst) high = mid - 1; // go on searching towards left
            else  low = mid + 1;  // go on searching towards right
        }
        else if(x < A[mid]) high = mid - 1;
        else low = mid + 1;
    }
//    cout << " not found " << x << " in A[] " << endl;
    return result;
}

int main() {
    int A[] = {1,1,3,3,5,5,5,5,9,9,11};
    int n;
    cout << "Enter a number: ";
    cin >> n;
    int Firstindex = BinarySearch(A,sizeof(A)/sizeof(A[0]),n,true);
    if(Firstindex == -1) {
        cout <<  "can't found " << n << endl;
    } else {
        int lastIndex = BinarySearch(A,sizeof(A)/sizeof(A[0]),n,false);
        cout << "Count of " << n << " is "  << (lastIndex-Firstindex+1) << endl;
    }
}

