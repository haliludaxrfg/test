/*给定一个二进制数组 nums 和一个整数 k，假设最多可以翻转 k 个 0 ，则返回执行操作后 数组中连续 1 的最大个数 。关联题目：leetcode1493.cpp 
示例 1：

输入：nums = [1,1,1,0,0,0,1,1,1,1,0], K = 2
输出：6
解释：[1,1,1,0,0,1,1,1,1,1,1]
粗体数字从 0 翻转到 1，最长的子数组长度为 6。
示例 2：

输入：nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], K = 3
输出：10
解释：[0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
粗体数字从 0 翻转到 1，最长的子数组长度为 10。*/
#include <bits/stdc++.h>
using namespace std;
//不定长滑动窗口，且允许存在k个0
class Solution {
    public:
        int longestOnes(vector<int>& nums,int k) {
            int n=nums.size(), cnt=0,left=0, right=0;//cnt表示0的个数 左右指针
            while(right<n){
                if(nums[right]==0) cnt++;
                if(cnt>k){//多于K个0，左指针右移
                    if(nums[left]==0) cnt--;
                    left++;
                }
                right++;
            }
            return right-left;
        }
    };