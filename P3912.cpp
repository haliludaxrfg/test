#include <bits/stdc++.h>
using namespace std;

int primenum(int N){
    if(N==1) return 0;
    vector <bool> Isprime(N+1,1);
    Isprime[0]=Isprime[1]=0;
    int cnt=0;
   for (unsigned long long int p = 2; p*p <= N; p++)
   {
        if(Isprime[p]==1){
            for(int i =p*p;i<=N;i+=p){
                Isprime[i]=0;
            }
        }    
   }
   for (int i = 2; i <= N; i++) {
        if (Isprime[i]) cnt++;
    }
   return cnt;
}

int main(){
    int N;
    cin>>N;
    cout<<primenum(N);
}