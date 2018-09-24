/*********************************************************************************
  *@copyright (C) 2018 san All Rights Reserved
  *@file    Bellman-Ford.cpp
  *@date    Sep 2018
  *@author  san
  *@CMAKE_CXX_STANDARD 17
  *@IDE:    Clion 2018.3
  *@OS:     macOS High Sierra 10.13.6
  *
  *@brief:
  *@function_lists:
  *  1.

  *@ Time complexity: O(NM)
  *@warning:
  *@history:
     1.Date:
       Author:
       Modification:
**********************************************************************************/

#include <iostream>
#include <cstdio>
using namespace std;

const int inf = 99999999; // use inf（infinity）to store a value which we consider positive infinity. 两个正无穷相加也小于2147483647(the max of int)

int main() {
    int dis[10],i,k,n,m,u[10],v[10],w[10];
    // read n and m, N represents the number of vertices and M represents the number of edges.
    cin >> n >> m;

    // Read the edge
    for (i = 1; i <= m ; i++) {
        cin >> u[i] >> v[i] >> w[i];
    }

    // Initialization of dis array,This is the initial distance from vertex 1 to the rest of the vertices.
    for(i = 1; i <= n; i++){
        dis[i] = inf;
    }
    dis[1] = 0;

    // core code of Bellman-Ford
    for (k = 1; k <= n-1 ; k++) {
        for (i = 1; i <= m ; i++) {
            if(dis[v[i]] > dis[u[i]] + w[i])
                dis[v[i]] = dis[u[i]] + w[i];
        }
    }

    // output the result
    for (i = 1; i <= n ; i++) {
        cout << dis[i] << " ";
    }
}

Input:
5 5 
2 3 2
1 2 -3
1 5 5
4 5 2
3 4 3
 
Output:
0 -3 -1 2 4 
