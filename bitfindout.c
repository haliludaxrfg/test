#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <numeric>
#include <string>
#include <stdio.h>

int main()
{
    int x;
    int n =0;

    scanf("%d",&x);
    
    n++;
    x/= 10;
    while ((x>0))
    {
        n++;
        x/=10;
   }
    printf(":%d\n",n);
    return 0;
}