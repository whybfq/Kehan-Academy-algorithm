/*********************************************************************************
  *@copyright (C) 2018 san All Rights Reserved
  *@file    Kruskal.cpp
  *@date    Sep 2018
  *@author  san
  *@CMAKE_CXX_STANDARD 17
  *@IDE:    Clion 2018.3
  *@OS:     macOS High Sierra 10.13.6
  *
  *@time_complexity:  O(MlogM + MlogN) 对边进行快排O(MlogM), M条边中找出n-1条边O(MlogN)  M >> N so
  *                  ≈ 约等于）O(MlogM)
  *@brief:
  *@function_lists:
  *  1.
  *@warning:
  *@history:
     1.Date:
       Author:
       Modification:
**********************************************************************************/

#include <iostream>
#include <stdlib.h>
using namespace std;

struct edge{  // 创建一个数组用来存储边的关系
    int u;
    int v;
    int w;
};

struct edge e[10];  //数组大小根据实际情况，要比m的最大值大1
int n,m;
int f[7] = {0},sum = 0 ,count1 = 0; //并查集需要用到的一些变量 f数组大小根据实际情况设置，要比n的最大值大1

void quicksort(int left,int right){
    int i,j;
    struct edge t;
    if(left > right) {
        return;
    }
    i = left;
    j = right;
    while(i != j){
        // 顺序很重要，先从右边开始找
        while (e[j].w >= e[left].w && i < j) {
            j--;
        }
        while (e[i].w <= e[left].w && i < j) {
            i++;
        }

        // swap
        if(i < j){
            swap(e[i],e[j]);
        }
    }

    // 最终将基准数归位，将left和i互换
    swap(e[left],e[i]);
    quicksort(left,i - 1);  // 继续处理左边的
    quicksort(i+1,right);   // 继续处理右边的
    return;
}

// 并查集寻找祖先的函数
int getf(int v){
    if(f[v] == v){
        return v;
    }
    else {
        // 路径压缩
        f[v] = getf(f[v]);
        return f[v];
    }
}

// 并查集合并两子集合的函数
int merge(int v,int u){
    int t1,t2;
    t1 = getf(v);
    t2 = getf(u);
    if( t1 != t2){  // 判断两个点是否在同一个集合中
        f[t2] = t1;
        return 1;
    }
    return 0;
}
int main(int argc, char const *argv[]) {
//    cout << R"(This is Kruskal algorithm  \n , haha)";  // 原生字符串，所见即所得

    int i;
    cin >> n >> m;  // n顶点个数，m边的条数
    for (i = 0; i <= m ; ++i) {   // 读入边的信息
        cin >> e[i].u >> e[i].v >> e[i].w;
    }

    quicksort(1,m);    // 按照权值大小对边进行快排

    // 并查集初始化
    for (i = 0; i <= n ; ++i) {
        f[i] = i;
    }

    // core code of Kruskal code
    for (i = 1; i <= m ; ++i) {  // 开始从小到大枚举每一条边
        // 判断一条边的两个顶点是否连通，即判断是否在同一个集合中
        if(merge(e[i].u,e[i].v)){  // 如果目前商不连通，则选用这条边
            count1++;
            sum += e[i].w;
        }
        if(count1 == n - 1){   // 直到选用了n-1条边之后退出循环
            break;
        }
    }

    cout << sum << endl;  // print the result
    getchar();
}

Input:
6 9
2 4 11
3 5 13
4 6 3
5 6 4
2 3 6
4 5 7
1 2 1
3 4 9
1 3 2

Output:
19
