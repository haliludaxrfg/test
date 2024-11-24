#include <bits/stdc++.h>
using namespace std;

set<int> prime;

void fun(int n) {
    for (int j = 2; j *j <= n; j++) {
        while (n % j == 0) {
            prime.insert(j);
            n /= j;
            if (n == 1) break; // 如果 n 已经被完全分解，则停止循环
        }
    }
}

int main() {
    int m;
    cin >> m;
    fun(m);
    for (auto p = prime.begin(); p != prime.end(); p++) {
        cout << *p << " ";
    }
    cout << endl; // 换行，以便清晰地显示质因数和质因数之和
    cout << accumulate(prime.begin(), prime.end(), 0);
    return 0;
}
