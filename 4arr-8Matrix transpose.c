#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <numeric>
#include <string>
/*8
题目编号: Exp04-Basic08,GJBook3-06-03
题目名称: 矩阵转置
问题描述: 编写程序，将任意给定n*n的两维整型数组转置。
输入：第一行输入数组行数n（≤10），第二行随机输入n×n个整数作为数组元素值。
输出：按先行后列、从左至右的顺序输出转置后数组内的所有元素，每行n个元素，同一行内的各元素间以一个西文空格间隔；每行最后一个元素除必要的回车换行符外无其它字符。
样例1：
输入：
3
1 2 3
1 2 3
1 2 3
输出：
1 1 1
2 2 2
3 3 3
样例2：
输入：
3
1 1 1
2 2 2
3 3 3
输出：
1 2 3
1 2 3
1 2 3*/
#include <stdio.h>
int main(){
    int n,r,c;
    int Matrix[10][10];
    scanf("%d",&n);
    for(r=0;r<n;r++){
        for(c=0;c<n;c++){
            scanf("%d",&Matrix[r][c]);
        }
    }

    for(r=0;r<n;r++){
        for(c=0;c<n;c++){
            printf("%d%c",Matrix[c][r]," \n"[c==n-1]);            
 /*     if (c < n-1)
            printf(" ");        
        if (c == n-1)
            printf("\n");
        }*/
    }
}
}