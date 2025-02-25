#include <stdio.h>

int road(int n,int m){
    if(n==1||m==1)
        return 1;
    return road(n-1,m)+road(n,m-1);
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int k=road(n,m);
    printf("%d",k);
}