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