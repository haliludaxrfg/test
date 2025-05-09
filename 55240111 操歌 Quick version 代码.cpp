#include <bits/stdc++.h>
using namespace std;

// 计算单个数字字符串的数字累加和
long long digitSum(const string& n) {
    long long sum = 0;
    for (char c : n) {
        sum += c - '0';  // 将字符转换为整数并累加
    }
    return sum;
}

// 计算大数阶乘
string factorial(int n) {
    vector<int> result(1, 1); // 用容器存储结果，初始为1
    for (int i = 2; i <= n; ++i) {
        int carry = 0;
        for (size_t j = 0; j < result.size(); ++j) {
            int product = result[j] * i + carry; // 计算乘积
            result[j] = product % 10; // 取个位数
            carry =product / 10; // 取进位
        }
        while (carry) {
            result.push_back(carry % 10); // 一位一位返回
            carry /= 10;
        }
    }
    string factorialResult;
    for (auto it = result.rbegin(); it != result.rend(); ++it) {
        factorialResult += to_string(*it);
    }
    return factorialResult;
}

// 测试代码
int main() {
    // 测试数字累加和
    string number;
    cout << "Enter numbers to calculate their digit sums : ";
    cin >> number;
    cout << digitSum(number) << endl;

    // 计算大数阶乘
    int n;
    cout << "Enter a number to calculate its factorial: ";
    cin >> n;
    if (n < 0) {
        cout << "Factorial is not defined for negative numbers." << endl;
        return 1;
    }
    string fact = factorial(n);
    cout << "Factorial of " << n << " :  " << fact << endl;
    cout << "Length of " << n << "! :  " << fact.size() << endl;
    return 0;
}