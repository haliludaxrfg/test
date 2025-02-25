#include <iostream>
using namespace std;

// 快速幂函数
long long fastPow(long long a, long long b,long long c) {
    long long result = 1;
    a%=c;
    while (b > 0) {
        // 如果当前二进制位为1，累乘到结果
        if (b & 1) {
            result = (a*result)%c;
        }
        // a自乘，相当于a^(2^k)
        a = (a*a)%c;
        // 右移一位，处理下一个二进制位
        b >>= 1;
    }
    return result;
}

int main() {
    long long a;
    long long b;
    long long c;
    cin >>a>>b>>c;
    cout <<a<<'^'<<b<<" mod "<<c<<'='<< fastPow(a, b, c) << endl;
    return 0;
}