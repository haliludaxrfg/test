#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main(){
    vector <int> a;
    int _;
    while (1)
    {
        cin>>_;
        if(_!=0){
            a.push_back(_);
        }else{
            break;
        }
    }

    for (int i = a.size()-1;i>=0;i--)
    {
       cout <<a[i]<<" ";
    }
    
}