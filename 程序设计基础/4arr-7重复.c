#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <numeric>
#include <string>/*7
题目编号：Exp04-Basic07，GJBook3-06-01
题目名称：检验矩阵重复元素
题目描述：编写程序判断任意给定n*n的两维整型数组中是否有相同元素。
输入：第一行输入数组行数n（≤10），第二行随机输入n*n个整数作为数组元素值。
输出：如果数组中有相同元素，则输出YES；否则，输出NO。
样例1：
输入：
3
1 2 3 4 5 6 7 8 9
输出：
NO
样例2：
输入：
3
1 1 2 3 4 5 6 7 8
输出：
YES*/
#include <stdio.h>
int main(){
    int n,i;
    int yn=0;
    int a[100]={0};
    scanf("%d",&n);

    n*=n;
    for(i=0;i<n;i++)
      scanf("%d",&a[i]);
    
    for(i=0;i<n;i++){
        for(int k=i+1;k<n;k++){
            if(a[i]==a[k])
               yn=1;
              break;
        }if(yn==1)
        break;
    }

    if(yn==1)
      printf("YES");
    else
      printf("NO");

    return 0;
}