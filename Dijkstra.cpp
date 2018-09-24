/*********************************************************************************
  *@copyright (C) 2018 san All Rights Reserved
  *@file    Dijkstra.cpp
  *@date    Sep 2018
  *@author  san
  *@CMAKE_CXX_STANDARD 17
  *@IDE:    Clion 2018.3
  *@OS:     macOS High Sierra 10.13.6
  *
  *@brief:
  *@function_lists:
  *  1.

  *@Time complexity: O(N^)2
  *@warning:
  *@history:
     1.Date:
       Author:
       Modification:
**********************************************************************************/

#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

const int inf = 99999999; // use inf（infinity）to store a value which we consider positive infinity. 两个正无穷相加也小于2147483647(the max of int)

int main() {
    int e[10][10],dis[10],book[10],i,j,n,m,t1,t2,t3,u,v,min;
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

    // Initialization of dis array,This is the initial distance from vertex 1 to the rest of the vertices.
    for(i = 1; i <= n; i++){
        dis[i] = e[1][i];
    }

    // Initialization of book array
    for(i = 1; i <= n; i++){
        book[i] = 0;
    } book[1] = 1;

    // core code of Dijkstra algorithm
    for (i = 1;  i <= n-1 ; i++) {
        // Find the nearest vertex from vertex 1.
        min = inf;
        for (j = 1; j <= n ; j++) {
            if(book[j] == 0 && dis[j] < min){
                min = dis[j];
                u = j;
            }
        }
        book[u] = 1;
        for(v = 1; v <= n; v++){
            if(e[u][v] < inf){
                if(dis[v] > dis[u] + e[u][v])
                    dis[v] = dis[u] + e[u][v];
            }
        }
    }

    // output the result
    for (i = 1; i <= n ; i++) {
        cout << dis[i] << " ";
    }
}

Input:
6 9
1 2 1
1 3 12
2 3 9 
2 4 3
3 5 5
4 3 4
4 5 13
4 6 15
5 6 4

Output:
0 1 8 4 13 17 
