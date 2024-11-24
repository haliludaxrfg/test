#include <stdio.h>
#define N 100
int main()
{
    int n=1;
    float s=0.0,t=0.0;
    while (n<=N)
    {if(n%2!=0){
        t=1.0/n;
    }else{
        t=-1.0/n;
    }
     s=s+t;
     n=n+1;
    }
    printf("s=%f\n",s);

    return 0;
}