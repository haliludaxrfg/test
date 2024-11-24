#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    char M[100][100];
    memset(M,'*',sizeof(M));

        
    

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << M[i][j];
        }
        cout << endl;
    }
}