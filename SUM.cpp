#include <iostream>
using namespace std;

int main() {
    const int MOD = 1000000000; // 10^9
    long long sum = 0;
    long long factorial = 1;

    for (int i = 1; i <= 39; ++i) {
        factorial = (factorial * i) % MOD; // 计算 i! 并取模
        sum = (sum + factorial) % MOD;    // 累加并取模
    }

    cout << "S 的最后九位数是: " << sum << endl;
    return 0;
}