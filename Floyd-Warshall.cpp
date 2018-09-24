/*********************************************************************************
  *@copyright (C) 2018 san All Rights Reserved
  *@file    Floyd-Warshall.cpp
  *@date    Sep 2018
  *@author  san
  *@CMAKE_CXX_STANDARD 17
  *@IDE:    Clion 2018.3
  *@OS:     macOS High Sierra 10.13.6
  *
  *@brief: the Floyd-Warshall algorithm
  *@function_lists:
  *  1.

  *@warning:
  *@history:
     1.Date:
       Author:
       Modification:
**********************************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;
const int inf = 99999999;  // use inf（infinity）to store a value which we consider positive infinity. 两个正无穷相加也小于2147483647(the max of int)

int main() {
    int e[10][10],k,i,j,n,m,t1,t2,t3;

    // read n and m, N represents the number of vertices and M represents the number of edges.
    cin >> n >> m;
    // Initialization
    for (i = 1; i <= n ; i++) {
        for (j = 1; j <= n ; j++) {
            if(i == j) e[i][j] =0;
            else e[i][j] = inf;
        }
    }

    // Read the edge
    for (i = 1; i <= m ; i++) {
        cin >> t1 >> t2 >> t3;
        e[t1][t2] = t3;
    }
    // core code of Floyd-Warshall algorithm
    for (k = 1; k <= n; ++k) {
        for (i = 1 ; i <= n; ++i) {
            for (j = 1; j <= n; ++j) {
                if(e[i][j] > e[i][k] + e[k][j])
                    e[i][j] = e[i][k] + e[k][j];
            }
        }
    }
    // output the result
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            cout << setw(10) << e[i][j];
        }
        cout << endl;
    }
}

Input:
4 8
1 2 2 
1 3 6
1 4 4
2 3 3
3 1 7
3 4 1
4 1 5
4 3 12
 
Output:
         0         2         5         4
         9         0         3         4
         6         8         0         1
         5         7        10         0
