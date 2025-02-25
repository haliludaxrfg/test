// 正整数n，按第一项递减的顺序依次输出其和等于n的所有不增的正整数和式
// 数字和运算符间无符号，最后一行结尾有一个回车换行符。
#include <iostream>
#include <vector>
#include <string>

void decomposeNumber(int n, int start, std::vector<int> &path, std::vector<std::string> &results)
{
    if (n == 0)
    {
        std::string result = std::to_string(path[0]);
        for (size_t i = 1; i < path.size(); ++i)
        {
            result += "+" + std::to_string(path[i]);
        }
        results.push_back(result);
        return;//结算！
    }

    for (int i = start; i > 0; --i)
    {
        if (i > n)
            continue;
        path.push_back(i);
        decomposeNumber(n - i, i, path, results);
        path.pop_back();
    }
}

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> path;
    std::vector<std::string> results;

    decomposeNumber(n, n, path, results);

    for (const auto &result : results)
    {
        if (result != std::to_string(n))
        {
            std::cout << n << "=" << result << std::endl;
        }
    }

    return 0;
}
