#include <bits/stdc++.h>
using namespace std;

const int NUM = 5;

int main(){
    vector <int> ratings(NUM);
    vector <string> titles(NUM);
    
    cout <<"You will do exactly as told.You will enter\n "
        << NUM << "book titles and your ratings (0-10).\n";
    int i;
    for(i=0;i<NUM;i++){
        cout << "Enter title #" << i+1 << ": ";
        getline(cin,titles);
        cout << "Enter your rating (0-10):";
        cin >> ratings
    }
}