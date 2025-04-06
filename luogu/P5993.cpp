#include<bits/stdc++.h>//万能头文件
using namespace std;
long long a[50]={0,1,1};//斐波那契开头（如果不开longlong...）
int b[10001];//输入的数组
int main(){
  for(int i=2;i<=50;i++){//求斐波那契数列
	a[i]=a[i-1]+a[i-2];
  }
    long long n;//输入个数
    bool kkksc03=false;//判断是否符合标准 PS：膜拜kkk
    cin>>n;//输入n
    for(int i=1;i<=n;i++){//输入数组
    	cin>>b[i];
	}
	for(int i=1;i<=n;i++){//第一层循环是b数组的
    	for(int j=0;j<=46;j++){//第二三层是判断的
    		for(int k=0;k<=46;k++){
			if(a[k]*a[j]==b[i])//如果符合标准
				kkksc03=true;//则为真
				continue;//跳出循环
			}
		}
		if(kkksc03)//如果是真
			cout<<"TAK"<<endl;//输出TAK
		else//如果是假
			cout<<"NIE"<<endl;//输出NIE
		kkksc03=false;//重新恢复false状态
	}//结束循环
	return 0;//好习惯
}//完美结束
