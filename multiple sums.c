#include <stdio.h>
int main()
{
   int a,arr[5],i;
   int sum=0;
   scanf("%d",&a);

   for(i=0;i<5;i++){
    scanf("%d",&arr[i]);
   }
   for(i=0;i<5;i++){
    if(arr[i]%a==0)
     sum +=arr[i];
   }
  printf("%d",sum);
  getchar();
  return 0;   
}