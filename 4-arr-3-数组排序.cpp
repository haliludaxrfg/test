#include<stdio.h>
#include<string.h>  						//数组需要复制，所以需要包含头文件string.h
int a[10];          						//声明数组
int y1=0, y2=0, y3=0;						//函数只能返回一个值，所以需要全局变量来存储比较次数
//以下是主元排序部分
int zhuyuan(){
	int sum=0;
	int b[10],i,j,k,r;
	memcpy(b,a,sizeof(a));     				//调用函数将a数组复制给b数组
	for ( i = 0; i < 9; i++){
		j = i;
		for ( k = i+1; k < 10; k++){
		
			y1++;							//记录比较的次数		

			if (b[k] < b[j]) j = k;
		}
		r = b[i]; b[i] = b[j]; b[j] = r; 
		sum++;    							//记录移动次数
	}
	return sum;
}
//以下是冒泡排序部分
int maopao() {
	int sum=0;
	int b[10], i,r,flag=1;
	memcpy(b, a, sizeof(a));
	while (flag){
		flag = 0;
		for (i = 0; i < 9; i++){
			y2++;						//记录比较次数
			if (b[i]>b[i+1]){
				r = b[i]; b[i] = b[i + 1]; b[i + 1] = r; 
				sum++;					//记录移动次数
				flag = 1;
			}
		}
	}
	return sum;
}
//以下是逐步增加递增子序列法
int zhubu() {
	int sum=0;
	int b[10], i, j, k, r,flag;
	memcpy(b, a, sizeof(a));
	for (i = 1; i < 10; i++) {
		flag = 0;
		j = i - 1;
		while ((b[j] > b[i]) && (j >= 0)) {
			j = j - 1; 
			flag = 1; 				//用于判断是否有移动
			y3++; 					//记录比较的次数中进入while部分
		}
		r = b[i];
		for (k = i - 1; k >= j + 1; k--) {
			b[k + 1] = b[k];
			if (flag) sum++;		//记录移动次数中部分移动
		}
		if (flag) sum++; 			//移动次数加上未在循环中的部分
		b[j + 1] = r; 
	}
	y3 = y3 + 9;					//比较中有9次条件不成立未进入循环
	return sum;
}
int main() {
	int x1,x2,x3;
	int i;
	for ( i = 0; i < 10; i++){
		scanf("%d", &a[i]);
	}
	x1 = zhuyuan();
	x2 = maopao();
	x3 = zhubu();
	printf("%d %d %d %d %d %d", y1, x1, y2, x2, y3, x3);
	return 0;
}
