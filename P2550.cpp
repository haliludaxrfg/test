#include <iostream>
#include <set>
#include <vector>
using namespace std;

int Ac[7]= {0};//���ռ�������ٽ�
set <int> a;//�н�����
vector <set<int>> b; //����Ĳ�Ʊ����

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

    vector <int> cnt(n);//��ÿһ�����ͬ��������
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