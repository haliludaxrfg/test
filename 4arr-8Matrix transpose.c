#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <numeric>
#include <string>
/*8
��Ŀ���: Exp04-Basic08,GJBook3-06-03
��Ŀ����: ����ת��
��������: ��д���򣬽��������n*n����ά��������ת�á�
���룺��һ��������������n����10�����ڶ����������n��n��������Ϊ����Ԫ��ֵ��
����������к��С��������ҵ�˳�����ת�ú������ڵ�����Ԫ�أ�ÿ��n��Ԫ�أ�ͬһ���ڵĸ�Ԫ�ؼ���һ�����Ŀո�����ÿ�����һ��Ԫ�س���Ҫ�Ļس����з����������ַ���
����1��
���룺
3
1 2 3
1 2 3
1 2 3
�����
1 1 1
2 2 2
3 3 3
����2��
���룺
3
1 1 1
2 2 2
3 3 3
�����
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