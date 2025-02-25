#include <bits/stdc++.h>
using namespace std;

int main (){
    int n;
    cin >> n;
    vector <int> Dec(n);
    vector <int> binanum(n);
    for (int i = 0; i < n; i++)
    {
        cin >> Dec[i];   
    }
    
    for(int i = 0;i<n;i++){
        int temp = Dec[i];
        while(temp>0){
            binanum[i]+=temp&1;
            temp>>=1;
        }
    }

    for(const auto &num:binanum){
        cout <<num<<" ";
    }
}