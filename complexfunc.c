#include <stdio.h>
int main()
{
   int i;
   float x,F;
   scanf("%f",&x);
   
   F=x;

   for(i=1;i<=5;i++){
     F=(1+1/F);
   } 
   printf("%.3f",F);

   return 0;
}
