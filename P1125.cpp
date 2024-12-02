#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPrime(int num)
{
    // 小于2的数不是质数
    if (num < 2)
    {
        return false;
    }
    // 2是最小的质数
    if (num == 2)
    {
        return true;
    }
    // 排除所有偶数
    if (num % 2 == 0)
    {
        return false;
    }
    // 只需检查到 sqrt(num) 即可
    int root = static_cast<int>(sqrt(num));
    for (int i = 3; i <= root; i += 2)
    {
        if (num % i == 0)
        {
            return false; // 如果能被整除，则不是质数
        }
    }
    return true; // 以上都不满足，则是质数
}

int main()
{
    string s;
    cin >> s;
    vector<int> AlphaCnt(26, 0);
    for (const auto &ch : s)
    {
        AlphaCnt[static_cast<int>(ch - 'a')]++;
    }
    sort(AlphaCnt.begin(), AlphaCnt.end());
    int max = *(AlphaCnt.rbegin());
    // for(const auto& num:AlphaCnt)
    //     cout <<num<<" ";
    // cout << endl;
    int min = 0;
    for (int i = 0; i < 26; i++)
    {
        if (AlphaCnt[i] != 0)
        {
            min = AlphaCnt[i];
            break;
        }
    }

    int deference = max - min;

    // cout <<max<<" "<<min<<endl;
    // cout <<deference<<endl;

    if (isPrime(deference))
    {
        cout << "Lucky Word" << endl
             << deference;
    }
    else
    {
        cout << "No Answer" << endl
             << "0";
    }
}