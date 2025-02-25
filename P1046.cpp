#include <bits/stdc++.h>
using namespace std;


int main(){
    vector <int> a;
    for(int i=0;i<10;i++){
        int _;
        cin>>_;
        a.push_back(_);
    }
    int l;
    cin>>l;
    int cnt =0;
    for(int i = 0;i<10;i++){
        if(a[i]<=l+30){
            cnt++;
        }
    }
    cout<<cnt;
}