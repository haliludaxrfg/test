#include <bits/stdc++.h>
using namespace std;

int Ac[7]= {0};//最终计算出多少奖
set <int> a;//中奖号码
vector <set<int>> b; //购买的彩票号码

int main(){
    int n;
    cin>>n;
    b.resize(n);
    for(int k = 0;k<7;k++){
        int _;cin >> _;
        a.insert(_);
    }
    b.resize(n);
    for(int i = 0;i<n;i++){
        for(int k = 0;k<7;k++){
            int _;cin >> _;
            b[i].insert(_);
        }
    }

    /*
    cout <<endl;
    cout << n <<endl;

    for(const auto& p:a){
        cout << p <<" ";
    }
    cout <<endl;

    for(int i = 0;i<n;i++){
        for(const auto& p:b[i]){
            cout << p << " ";
        }cout <<endl;
    }*/

    vector <int> cnt(n);//对每一组的相同个数计数
    for(int i = 0;i<n;i++){
        for(const auto& num :a){
            if(b[i].find(num)!=b[i].end())
                cnt[i] ++;
        }
        Ac[7-cnt[i]]++;
    }

    for(const auto& p:Ac)
        cout << p <<" ";

    return 0;
}