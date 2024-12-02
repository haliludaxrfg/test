#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPrime(int num)
{
    // С��2������������
    if (num < 2)
    {
        return false;
    }
    // 2����С������
    if (num == 2)
    {
        return true;
    }
    // �ų�����ż��
    if (num % 2 == 0)
    {
        return false;
    }
    // ֻ���鵽 sqrt(num) ����
    int root = static_cast<int>(sqrt(num));
    for (int i = 3; i <= root; i += 2)
    {
        if (num % i == 0)
        {
            return false; // ����ܱ���������������
        }
    }
    return true; // ���϶������㣬��������
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