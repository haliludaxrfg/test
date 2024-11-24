#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n ;
    vector <int> a(n);
    vector <int> cmp(n);
        
    for(auto p = a.begin();p!=a.end();p++ ){
        cin >> *p;
    }
    
    for(int i=0;i<n;i++){
        for(int k=0;k<i;k++){
            if(a[k]<a[i])
            cmp[i]++;
        }
    }
    for(auto p = cmp.begin();p!=cmp.end();p++ )
        cout << *p << ' ';
    cout <<endl;
}