#include <iostream>
#include <cmath>
using namespace std;

int CutWood(int n,int k){
    if(n<=k)
        return 1;
    int CutP = round(n*2.0/5.0);
    return CutWood(CutP,k)+CutWood(n-CutP,k);

}

int main(){
    int n,k;
    cin >> n >> k;
    cout << CutWood(n,k);
}