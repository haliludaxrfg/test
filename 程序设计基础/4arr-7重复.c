#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <numeric>
#include <string>/*7
��Ŀ��ţ�Exp04-Basic07��GJBook3-06-01
��Ŀ���ƣ���������ظ�Ԫ��
��Ŀ��������д�����ж��������n*n����ά�����������Ƿ�����ͬԪ�ء�
���룺��һ��������������n����10�����ڶ����������n*n��������Ϊ����Ԫ��ֵ��
������������������ͬԪ�أ������YES���������NO��
����1��
���룺
3
1 2 3 4 5 6 7 8 9
�����
NO
����2��
���룺
3
1 1 2 3 4 5 6 7 8
�����
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