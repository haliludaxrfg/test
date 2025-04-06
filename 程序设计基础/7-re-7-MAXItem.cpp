#include <iostream>
#include <set>
using namespace std;

int main(){
    int n;
    int e;
    cin >> n;
    set <int> s;
    for(int i=0;i<n;++i){
        cin >> e;
        s.insert(e); 
    }
    auto p = s.rbegin();
    cout << *p;   
}