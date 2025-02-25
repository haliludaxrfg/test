#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int>> A(n,vector<int>(m));
    vector<vector<int>> B(m,vector<int>(k));
    vector<vector<int>> C(n,vector<int>(k));

    // 填充A矩阵
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }

    // 填充B矩阵
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < k; j++) {
            cin >> B[i][j];
        }
    }
    //计算C矩阵
    for(int i = 0;i<n;i++){
        for(int j =0;j<k;j++){
            for(int p = 0;p<m;p++){
                C[i][j]+=A[i][p]*B[p][j];
            }
        }
    }
    //输出C矩阵
    for(int i= 0;i<n;i++){
        for(int j=0;j<k;j++){
            cout<<C[i][j]<<" ";
        }cout<<endl;
    }
    return 0;
}