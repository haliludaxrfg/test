#include <iostream>
#include <algorithm>
using namespace std;

int GCD(int m,int n){
    if(m%n==0)
        return n;
    else
        return GCD(n,m%n);
}

int main(){
    int m,n;
    cin >> m >> n;

    cout << GCD(m,n);
}