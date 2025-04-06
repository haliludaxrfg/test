^/*有一个书店老板，他的书店开了 n 分钟。每分钟都有一些顾客进入这家商店。给定一个长度为 n 的整数数组 customers ，其中 customers[i] 是在第 i 分钟开始时进入商店的顾客数量，所有这些顾客在第 i 分钟结束后离开。

在某些分钟内，书店老板会生气。 如果书店老板在第 i 分钟生气，那么 grumpy[i] = 1，否则 grumpy[i] = 0。

当书店老板生气时，那一分钟的顾客就会不满意，若老板不生气则顾客是满意的。

书店老板知道一个秘密技巧，能抑制自己的情绪，可以让自己连续 minutes 分钟不生气，但却只能使用一次。

请你返回 这一天营业下来，最多有多少客户能够感到满意 。
 

示例 1：

输入：customers = [1,0,1,2,1,1,7,5], grumpy = [0,1,0,1,0,1,0,1], minutes = 3
输出：16
解释：书店老板在最后 3 分钟保持冷静。
感到满意的最大客户数量 = 1 + 1 + 1 + 1 + 7 + 5 = 16.
示例 2：

输入：customers = [1], grumpy = [0], minutes = 1
输出：1
 

提示：

n == customers.length == grumpy.length
1 <= minutes <= n <= 2 * 10^4
0 <= customers[i] <= 1000
grumpy[i] == 0 or 1*/
#include <bits/stdc++.h>
using namespace std;
//先计算总的，然后计算叠加的部分，最后加上叠加的部分
// LeetCode 1052. Grumpy Bookstore Owner
// https://leetcode.cn/problems/grumpy-bookstore-owner/description/?envType=study-plan-v2&envId=leetcode-75
class Solution {
    public:
        int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
            int NotechSatisfied = 0;
            int n = customers.size();//total number of minutes
            for (int i = 0; i < n; i++)
            {
                if (grumpy[i] == 0)//如果不生气
                {
                    NotechSatisfied += customers[i];//直接加上
                }
            }
            
            int curadd=0,maxadd=0;
            //intialize the first window
            for (int i = 0; i < minutes; ++i)
            {
                if (grumpy[i] == 1)curadd += customers[i];//加上                               
            }
            maxadd = curadd;
            //sliding window
            for (int i = minutes; i < n; ++i)
            {
                if (grumpy[i] == 1)curadd += customers[i];//加上tail
                if (grumpy[i - minutes] == 1)curadd -= customers[i - minutes];//减去head
                maxadd = max(maxadd, curadd);//更新最大值
            }
             return NotechSatisfied + maxadd;//返回总的满意人数
        }
    };