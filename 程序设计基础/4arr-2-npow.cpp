#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <numeric>
#include <string>
#include <stdio.h>

int main()
{
    int n = 0;
    scanf_s("%d", &n);

    int arr[20][100] = { 0 };     // 存储输入数据
    int menmory[20] = { 0 };     // 记录每行录入数字个数（不包括0）
    int total = 0;              // 记录输入行数
    int answer[20] = { 0 };    //记录配对数
    int i = 0;
    int j = 0;
    int ch = 0;

    while (scanf_s("%d", &ch) && ch != -1)
    {
        if (ch != 0)
        {
            arr[i][j++] = ch;
            menmory[i]++;
        }
        else
        {
            i++;
            j = 0;
            total++;
        }
    }

    // 计算配对数
    for (i = 0; i < total; i++)
    {
        for (j = 0; j < menmory[i] - 1; j++)
        {
            for (int k = j + 1; k < menmory[i]; k++)
            {
                if ((arr[i][j] * n == arr[i][k]) || (arr[i][k] * n == arr[i][j]) && (arr[i][j] != arr[i][k]))
                    answer[i]++;
            }
        }
    }

    // 输出结果
    for (i = 0; i < total; i++)
    {
        printf("%d", answer[i]);

        if (i < total - 1)
        {
            printf("\n");
        }
    }

    return 0;
}