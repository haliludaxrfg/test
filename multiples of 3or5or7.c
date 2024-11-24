#include <stdio.h>
int main()
{
    int a;scanf("%d",&a);

    if(a%3!=0&&a%5!=0&&a%7!=0)
      printf("NULL");
    if(a%3==0)
      printf("3");
    if((a%5==0||a%7==0)&&a%3==0)
      printf(",");
    if(a%5==0)
      printf("5");
    if(a%7==0&&(a%5==0||a%3==0))
      printf(",");         
    if(a%7==0)   
      printf("7");

    return 0;
}