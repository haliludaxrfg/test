#include <bits/stdc++.h>
using namespace std;

struct Students
{
    string name;
    int sc1;
    int sc2;
    int sc3;
    int sum() const{
        return sc1+sc2+sc3;
    }
};


int main(){
    int N;
    cin >> N;
    vector <Students> students(N);
    for(int i=0;i<N;++i){
        cin >>students[i].name >>students[i].sc1 >>students[i].sc2 >>students[i].sc3 ;
    }
    
    Students best = students[0];
    for(const auto& s:students)
        if(s.sum() >best.sum())
            best = s;
    
    cout <<best.name <<" "<<best.sc1 <<" "<<best.sc2 <<" "<<best.sc3 ;    
}

