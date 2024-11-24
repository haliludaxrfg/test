#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >>n;

    vector <int> a(n);
    for(auto p=a.begin();p!=a.end();p++)
        cin >> *p ;
    
    int key;
    cin >> key;

    vector<int>::iterator f;
    f = find(a.begin(),a.end(),key);

    if(f == a.end())
        cout << "NULL";
    else
        cout << f-a.begin()+1;        
}
