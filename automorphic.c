/*题目编号：Exp03-Extend01，GJBook3-12-04

题目名称：自守数

题目描述：若一个正整数a满足条件 a^2 的尾数等于a，则称a为自守数，例如：

25^2=625 、76^2=5776 、9376^2=87909376 都是自守数。

编写程序，求小于等于n的所有自守数。

输入：从键盘随机输入一个正整数n（不超过10000000）。

输出：输出小于等于n的所有自守数，每个数之间以一个西文空格间隔。*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	long long i, a, k, m, x;
    scanf("%lld", &x);			
	for (i = 1; i < x; i++)			
	{
		a = i;						//把i的值赋给a
		a *= a;						//求出a的平方即i的平方
		k = log10(i) + 1;			//求出i的位数k
		for (m = 1; k; k--)
			m *= 10;
		a %= m;                     //通过取余求出尾数
		if (a == i)                 //判断i的平方的尾数是否等于i
			printf("%lld ", i);   //输出所有自守数
	}
	
	return 0;
}