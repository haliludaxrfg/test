#include<stdio.h>//二项式系数
int f(int m,int n){
	if(m<n&&m>0&&n>0){
		return 0;
	}
	else if(m==n&&m>0&&n>0){
		return 1;
	}
	else if(m>n&&m>0&&n>0){
	long long int a=1,b=1,c=1,i;
		for(i=1;i<=m;i++){
			a*=i;
		}
		for(i=1;i<=n;i++){
			b*=i;
		}
		for(i=1;i<=(m-n);i++){
			c*=i;
		}
		return a/(b*c);
	}
	else{
		return -1;
	}
}
int main(){
	int m,n,result;
	scanf("%d",&m);
	scanf("%d",&n);
	result=f(m,n);
	return 0;
}