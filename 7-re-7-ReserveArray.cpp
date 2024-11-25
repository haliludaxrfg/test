#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    vector <int> a(n);

    for(auto p = a.begin();p!=a.end();p++ ){
        cin >> *p;
    }

    for(auto p = a.end()-1;p!=a.begin()-1;p-- ){
        cout << *p << ' ';//rend,rebegin
    }
}