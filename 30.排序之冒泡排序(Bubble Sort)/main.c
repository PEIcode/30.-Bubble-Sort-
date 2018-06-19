//
//  main.c
//  30.排序之冒泡排序(Bubble Sort)
//
//  Created by sunny&pei on 2018/6/19.
//  Copyright © 2018年 sunny&pei. All rights reserved.
//
/**
 Bubble Sort ：两两比较相邻记录的关键字，如果反序则交换，直到没有反序的记录为止。
 */
#include <stdio.h>
#define MAXSIZE 10 /* 用于要排序数组个数最大值，可根据需要修改*/
typedef struct{
    int r[MAXSIZE+1];/* 用于存储要排序的数组，r[0]用作哨兵或临时变量*/
    int length; /* 用于记录顺序表的长度*/
}Sqlist;

/**
 交换L中 下标为i和j的数组
 */
void swap(Sqlist *L,int i,int j){
    int temp = L->r[i];
    L->r[i] = L->r[j];
    L->r[j] = temp;
}
void BubbleSort(Sqlist *L){
    int i,j;
    for (i = 0; i<L->length-1;i++) {
        for (j = L->length-1; j>=1; j--) {
            if (L->r[j]>L->r[j+1]) {
                swap(L, j, j+1);
            }
        }
    }
    //打印
    for (i = 1; i<L->length; i++) {
        printf("%d\n",L->r[i]);
    }
    
}

/**
 冒泡排序的优化：针对 顺序表有序情况，添加一个flag，避免已经有序的情况下，进行无意义的循环判断
 */
void BubbleSortOptimize(Sqlist *L){
    int i,j;
    int flag = 1;
    for (i = 0; i<L->length-1 && flag ;i++) {
        flag = 0;
        for (j = L->length-1; j>=1; j--) {
            if (L->r[j]>L->r[j+1]) {
                swap(L, j, j+1);
                flag = 1;
            }
        }
    }
    //打印
    for (i = 1; i<L->length; i++) {
        printf("%d\n",L->r[i]);
    }
}

/**
 总结：冒泡排序的时间复杂度
 当最好的情况下，有序，需要n-1次比较，为O[n];
 当最坏的情况下，逆序，n(n-1)/2次，O[n*n];
 */
int main(int argc, const char * argv[]) {
    // insert code here...
    Sqlist ll ;
    ll.length = 11;
    ll.r[1] = 9;
    ll.r[2] = 3;
    ll.r[3] = 2;
    ll.r[4] = 5;
    ll.r[5] = 1;
    ll.r[6] = 7;
    ll.r[7] = 8;
    ll.r[8] = 4;
    ll.r[9] = 6;
    BubbleSort(&ll);
    return 0;
}


