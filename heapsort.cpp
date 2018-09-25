/*********************************************************************************
  *@copyright (C) 2018 san All Rights Reserved
  *@file    heapsort.cpp
  *@date    Sep 2018
  *@author  san
  *@CMAKE_CXX_STANDARD 17
  *@IDE:    Clion 2018.3
  *@OS:     macOS High Sierra 10.13.6
  *@bug:  there is not right result should be output
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

int h[101]={0}; //to store heap
int n;   // to store the number of heap, the size of heap

void swap(int x,int y){
    int t;
    t = h[x];
    h[x] = h[y];
    h[y] = t;
}

void siftdown(int i){
    int t, flag = 0;  // flag 用来标记是否需要继续向下调整
    while(i * 2 <= n && flag == 0){  // 当i结点有儿子并且有需要继续调整的时候就循环执行
        if(h[i] < h[i * 2]){ // 首先判断它和左儿子的关系，并用t记录值较小的结点编号
            t = i * 2;
        }
        else{
            t = i;
        }
        // 如果它有右儿子，再对右儿子进行讨论
        if(i * 2 + 1 <= n){
            // 如果右儿子的值更小，更新较小的结点编号
            if(h[t] < h[i * 2 + 1]){
                t = i * 2 + 1;
            }
        }
        //如果发现最小的结点编号不是自己，说明子结点中有比父结点更小的
        if(t != i){
            swap(t,i);
            i = t;  // 更新i为刚才与它交换的儿子结点的编号，便于接下来继续向下调整
        }
        else {
            flag = 1; // 否则说明当前的父结点已经比两个子结点都要小了，不需要再进行调整了
        }
    }
}

void creat(){
    //从最后一个非叶结点到第一个结点依次进行向上调整
    for (int i = n/2; i >= 1 ; i--) {
        siftdown(i);
    }
}

int deletemax(){
    int t;
    t = h[1];  //用一个临时变量记录堆顶点的值
    h[1] = h[n]; // 将堆的最后一个点赋值到堆顶
    n--;  // 堆的元素减少1
    siftdown(1);  // 向下调整
    return t;   // 返回之前记录的堆顶点的最大值
}

void heapsort(){
    while (n > 1){
        swap(1,n);
        n--;
        siftdown(1);
    }
}

int main(int argc, char const *argv[]) {
    int i,num;
    //读入要排序的数字个数
    cin >> num;
    for (i = 1; i <= num ; i++) {
        cin >> h[i];
    }
    n = num;

    //建堆
    creat();

    // 堆排序
    heapsort();

    //删除顶部元素，连续删除n次，其实也是从大到小把数输出来
    for (i = 1; i <= num ; ++i) {
        cout << deletemax();
    }
}


Input:
14
99 5 36 7 22 17 46 12 2 19 25 28 1 92
 
Output:
1 2 5 7 12 17 19 22 25 28 36 46 92 99
