/*********************************************************************************
  *@copyright (C) 2018 san All Rights Reserved
  *@file    Floyd-Warshall.cpp
  *@date    Sep 2018
  *@author  san
  *@CMAKE_CXX_STANDARD 17
  *@IDE:    Clion 2018.3
  *@OS:     macOS High Sierra 10.13.6
  *
  *@brief: the basic use of sqlite3
  *@function_lists:
  *  1.

  *@warning:
  *@history:
     1.Date:
       Author:
       Modification:
**********************************************************************************/

#include <iostream>
using namespace std;

int main() {
    int e[10][10],k,i,j,n,m,t1,t2,t3;
    int inf = 99999999;  // 用inf（infinity）store a 
    for (int k = 1; k <= n; ++k) {
        for (int i = 1 ; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if(e[i][j] > e[i][k] + e[k][j])
                    e[i][j] = e[i][k] + e[k][j];
            }
        }
    }
    return 0;
}
