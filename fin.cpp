#include <bits/stdc++.h>
using namespace std;

unsigned long long int Fac(int x){
    if(x==1)return 1;
    return x * Fac(x-1);
}

int main(){
    double sum=0;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        sum+=1.0*i/((i+1)*Fac(i+2));
    }
    cout <<sum;
}