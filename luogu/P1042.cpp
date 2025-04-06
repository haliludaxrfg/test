#include <bits/stdc++.h>
using namespace std;

//W对于0 L对于1

void system_11(vector <char> a){
    int currentScore[2]={0};

    int i=0;
    while (a[i]!='E')
    {
        currentScore[a[i++] == 'W' ? 0 : 1]++;
        if(currentScore[0]>=11&&currentScore[0]-currentScore[1]>=2){
            cout << currentScore[0] <<":"<<currentScore[1]<<endl;
            currentScore[0]=0;currentScore[1]=0;
            
        }
        if(currentScore[1]>=11&&currentScore[1]-currentScore[0]>=2){
            cout << currentScore[0] <<":"<<currentScore[1]<<endl;
            currentScore[0]=0;currentScore[1]=0;
            
        }
    }
    cout <<currentScore[0]<<":"<<currentScore[1]<<endl;
} 

void system_22(vector <char> a){
    
    int currentScore[2]={0};

    int i=0;
    while(a[i]!='E')
    {
        currentScore[a[i++] == 'W' ? 0 : 1]++;
        if(currentScore[0]>=21&&currentScore[0]-currentScore[1]>=2){
            cout << currentScore[0] <<":"<<currentScore[1]<<endl;
            currentScore[0]=0;currentScore[1]=0;
            
        }
        if(currentScore[1]>=21&&currentScore[1]-currentScore[0]>=2){
            cout << currentScore[0] <<":"<<currentScore[1]<<endl;
            currentScore[0]=0;currentScore[1]=0;
            
        }
    }
    cout <<currentScore[0]<<":"<<currentScore[1]<<endl;
}

int main(){
    vector <char> a;
    while (1)
    {
        char _;
        cin>>_;
        a.push_back(_);
        if(_=='E')
            break;
    }
    system_11(a);
    cout<<endl;
    system_22(a);
}