#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

const string DECIMAL_TO_CHAR = "0123456789";
const string LETTER_TO_DECIMAL = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

char mapDecimalToChar(int decimal){ 
    return LETTER_TO_DECIMAL[decimal]; // 映射到对应的大写字母
}

int main(){
    unsigned int N;
    int b;
    cin >> N >> b;
    string TR;

    do{
        int r = N%b;
        TR += mapDecimalToChar(r);
        N/=b;
    }while(N>0);
    reverse(TR.begin(),TR.end());

    cout << TR;

    return 0;
}