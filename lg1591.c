/*# 阶乘数码
## 题目描述
求 $n!$ 中某个数码出现的次数。
## 输入格式
第一行为 $t(t \leq 10)$，表示数据组数。接下来 $t$ 行，每行一个正整数 $n(n \leq 1000)$ 和数码 $a$。
## 输出格式
对于每组数据，输出一个整数，表示 $n!$ 中 $a$ 出现的次数。
## 样例 #1
### 样例输入 #1
```
2
5 2
7 0
```
### 样例输出 #1
```
1
2
```*/
#include <stdio.h>

#include<stdio.h>
#define max 2570//1000！的位数大致在这里
int a[max]={0};
int main()
{
    int n;
    scanf("%d",&n);
	a[0]=1;
	for(int i=2;i<=n;i++)
	{
		int carry=0;
		for(int j=0;j<max;j++)
		{
			int s=a[j]*i+carry;
			a[j]=s%10;
			carry=s/10;
 
		}
	}
	int i=0;
	for(i=max-1;i>0;i--)
	{	
		if(a[i]!=0)
		{
			break;
		}
	}
	for(int j=i;j>=0;j--)
	{
		printf("%d",a[j]);
	}
	printf("\n");
	
}


