#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <numeric>
#include <string>
#include <stdio.h>
 
int main()
 
{
    int a[10000],n,k,s,m,i,j,num,flag=0;
    scanf_s("%d %d %d",&n,&s,&m);
    for(i=0;i<n;i++)
 
        a[i]=i+1;//构建个数为n的自然数数组
 
    num=i;//num为数组中元素个数
 
    k=s-1;//从1开始计数，所以要减一
 
    while(num>=1)
 
    {
 
        k=k+m-1;//从1开始计数或者弹出一个数，计数减一
 
        while(k>=num)//将k取模
 
            k%=num;
 
        if(flag)//控制空格
 
            printf(" ");
 
        printf("%d",a[k]);
 
        flag=1;
 
        for(j=k+1;j<n;j++)//删去弹出的数
 
            a[j-1]=a[j];
 
        num--;
 
    }
 
 
 
}