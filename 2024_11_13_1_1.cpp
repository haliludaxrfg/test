#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <numeric>
#include <string>
#include <iostream>
#include <set>
#include <algorithm>
#include<numeric>
using namespace std;

set<int> prime;

void fun(int n) {
    for (int j = 2; j *j <= n; j++) {
        while (n % j == 0) {
            prime.insert(j);
            n /= j;
            if (n == 1) break; // ��� n �Ѿ�����ȫ�ֽ⣬��ֹͣѭ��
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
    cout << endl; // ���У��Ա���������ʾ��������������֮��
    cout << accumulate(prime.begin(), prime.end(), 0);
    return 0;
}
