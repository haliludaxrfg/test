#define _CRT_SECURE_NO_WARNINGS
/*6
题目编号 ：Exp04-Basic06，GJBook3-06-04
题目名称：循环右移
题目描述：编写程序，不使用其它辅助数组，把一维整型数组中的各个元素循环右移j位。
输入：
第一行输入两个整数，n表示数组长度（0<n<=100），j表示循环右移的位数（j>=0）；
第二行依次从键盘随机输入n个整数作为数组元素值。
输出：
循环右移后的整数数组，各元素间以一个西文空格间隔，最后一个元素后无字符。
样例1：
输入：
10 2
1 2 3 4 5 6 7 8 9 0
输出：
9 0 1 2 3 4 5 6 7 8
样例2：
输入：
10 23
1 2 3 4 5 6 7 8 9 0
输出：
8 9 0 1 2 3 4 5 6 7*/
#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int r;
    scanf("%d",&r);
    r%=n;

    int i,t;
    int a[100]={0};
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    
    for(i=n-r;i<n;i++)
       printf("%d ",a[i]);

    for(i=0;i<n-r;i++)
       printf("%d ",a[i]);

    return 0;
    
}