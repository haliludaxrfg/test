#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <numeric>
#include <string>
#include <stdio.h>

int Cbnt(int m,int n){
    if(n<0) {return 0;}
    else if(n==0) {return 1;}
    else if(n==1) {return m;}
    else if(m<2*n){ return Cbnt(m,m-n);}
    else return (Cbnt(m-1,n-1)+Cbnt(m-1,n));
}    
int main(){
    int n,m;
    scanf_s("%d %d",&m,&n);
    printf("%d",Cbnt(m,n));
}