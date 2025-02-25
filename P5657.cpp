#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    unsigned long long k;
    cin>>n>>k;//n表示这个二进制数的位数
    vector <int> Bina(n);
    int bit=0;
    while (k>0)
    {        
        int remainder = k%2;
        Bina[bit++]=remainder;
        k/=2;
    }

    //for(int i = n;i>0;i--){
        //cout<<Bina[i-1];
    //}cout<<endl;

    vector <int> Gary(n);
    Gary[n-1]=Bina[n-1];
    for(int i =n-1;i>0;i--){
        Gary[i-1]=Bina[i]^Bina[i-1];
    }

    for(int i = n;i>0;i--){
        cout<<Gary[i-1];
    }cout<<endl;
}