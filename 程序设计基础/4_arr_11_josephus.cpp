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
 
        a[i]=i+1;//��������Ϊn����Ȼ������
 
    num=i;//numΪ������Ԫ�ظ���
 
    k=s-1;//��1��ʼ����������Ҫ��һ
 
    while(num>=1)
 
    {
 
        k=k+m-1;//��1��ʼ�������ߵ���һ������������һ
 
        while(k>=num)//��kȡģ
 
            k%=num;
 
        if(flag)//���ƿո�
 
            printf(" ");
 
        printf("%d",a[k]);
 
        flag=1;
 
        for(j=k+1;j<n;j++)//ɾȥ��������
 
            a[j-1]=a[j];
 
        num--;
 
    }
 
 
 
}