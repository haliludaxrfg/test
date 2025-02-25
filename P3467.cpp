//单调栈入门题
//宽度是没用数据
#include <bits/stdc++.h>
using namespace std;

stack <int> stk;
int n,sum,a[250010];


int main(){
    int n;
    cin>>n;

    for(int i=1;i<=n;i++){
        int x;
        cin>>x>>a[i];
    }
    for(int i=1;i<=n;i++){
        while (!stk.empty()&&stk.top()>a[i])
        {
            stk.pop();
        }
        if(stk.empty()||stk.top()!=a[i]){
            sum++;
        }
        stk.push(a[i]);
    }
    cout <<sum;
    return 0;
}