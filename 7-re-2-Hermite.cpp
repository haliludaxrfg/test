#include <stdio.h>

double Hn(int n,double x){
    if(n==0){
         return 1;
    }else if(n==1){
        return 2*x;
    }else{
        return (2*x*Hn(n-1,x)-2*(n-1)*Hn(n-2,x));
    }
}

int main(){
    
    int n;
    double x;
    scanf("%d %lf",&n,&x);
    printf("%.2lf",Hn(n,x));
}