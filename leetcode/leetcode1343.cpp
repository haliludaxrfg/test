/*给你一个整数数组 arr 和两个整数 k 和 threshold 。
请你返回长度为 k 且平均值大于等于 threshold 的子数组数目。

示例 1：

输入：arr = [2,2,2,2,5,5,5,8], k = 3, threshold = 4
输出：3
解释：子数组 [2,5,5],[5,5,5] 和 [5,5,8] 的平均值分别为 4，5 和 6 。其他长度为 3 的子数组的平均值都小于 4 （threshold 的值)。
示例 2：

输入：arr = [11,13,17,23,29,31,7,5,2,3], k = 3, threshold = 5
输出：6
解释：前 6 个长度为 3 的子数组平均值都大于 5 。注意平均值不是整数。
 

提示：

1 <= arr.length <= 10^5
1 <= arr[i] <= 10^4
1 <= k <= arr.length
0 <= threshold <= 10^4*/
using namespace std;
#include <bits/stdc++.h>

class Solution {
    public:
        int numOfSubarrays(vector<int>& arr, int k, int threshold) {
            long long thresholdSum = k * static_cast<long long>(threshold);//阈值和
            int cnt = 0;
            long long sum = accumulate(arr.begin(),arr.begin()+k,0LL);
            //前k个元素的和
            if(sum >= thresholdSum) cnt++;//first window
            //滑动窗口，前k-1个元素的和减去第一个元素，加上第k个元素
            for(int i=1;i<=arr.size()-k;i++){
                sum = sum - arr[i-1] + arr[i+k-1];//滑动窗口，前k-1个元素的和减去第一个元素，加上第k个元素
                if(sum >= thresholdSum) cnt++; 
            }          
            return cnt;
    }
};