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
       Modification: 在未大道n-1轮松弛前就已经计算出最段路，so add an array to store array dis.
                     如果新一轮的松弛中数组dis没有发生变化，则可以提前跳出循环
**********************************************************************************/

#include <iostream>
#include <cstdio>
using namespace std;

const int inf = 99999999; // use inf（infinity）to store a value which we consider positive infinity. 两个正无穷相加也小于2147483647(the max of int)

int main() {
    int dis[10],bak[10],i,k,n,m,u[10],v[10],w[10],check = 0,flag = 0;
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

/*
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
    */

    // modify improve
    for (k = 1; k <= n-1 ; k++) {
        // 就dis数组备份至bak数组
        for(i = 1; i <= n; i++) bak[i] = dis[i];
        // 进行一轮松弛
        for (i = 1; i <= m ; i++) {
            if(dis[v[i]] > dis[u[i]] + w[i])
                dis[v[i]] = dis[u[i]] + w[i];
        }
        // 松弛完毕后检测dis数组是否有更新
        check = 0;
        for (i = 1; i <= n ; i++) {
            if(bak[i] != dis[i]){
                check = 1;
                break;
            }
            if(check == 0){
                break;  // 如果新一轮的松弛中数组dis没有发生变化，则可以提前跳出循环
            }
        }
    }

    // 检测负权回路
    flag = 0;
    for (i = 1; i <= m; i++) {
        if(dis[v[i]] > dis[u[i]] + w[i])
            flag = 1;
    }
    if(flag == 1) cout << "This graph contains a negative weight loop. " << endl;
    else {  // output the result
        for (i = 1; i <= n ; i++) {
            cout << dis[i] << " ";
        }
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
