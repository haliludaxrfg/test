#include <bits/stdc++.h>
using namespace std;

int sumofeachnum(int o){
    int total=0;
    while (o>0)
    {
        total+=o%10;
        o/=10;
        /* code */
    }
    return total;    
}

int max(int n){
    int m=0;
    for(int i=1;i<=n;i++){
        if(m<sumofeachnum(i)){
            m = sumofeachnum(i);
        }
    }
    return m;
}

int main(){
    system("chcp 65001");
    cout<<"输入好数范围："<<endl;
    int n;
    cin>>n;
    int sum=0;
    vector <int> Perfect_Square;
    int j=1;
    while (j*j<=max(n))
    {
        Perfect_Square.push_back(j*j);
        j++;
    }
    
    for(int i=1;i<=n;i++){
        if(binary_search(Perfect_Square.begin(),Perfect_Square.end(),i))sum++;
    }
    cout<<"一共有"<<sum<<"个好数"<<endl;
    return 0;
}