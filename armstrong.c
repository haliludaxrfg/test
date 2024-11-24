#include <stdio.h>
int main()
{
    int a=100;
    int h,t,s;

    for(;a<=999;a++){
     
     h=(a/100)%10;//百位
     t=(a/10)%10;//十位
     s=a%10;//个位
     
     if(a==h*h*h+s*s*s+t*t*t)
       printf("%d ",a);
   }
    return 0;
}