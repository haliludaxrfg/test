/*给你一个二进制数组 nums ，你需要从中删掉一个元素。
请你在删掉元素的结果数组中，返回最长的且只包含 1 的非空子数组的长度。
如果不存在这样的子数组，请返回 0 。

输入：nums = [1,1,0,1]
输出：3
解释：删掉位置 2 的数后，[1,1,1] 包含 3 个 1 。
示例 2：

输入：nums = [0,1,1,1,0,1,1,0,1]
输出：5
解释：删掉位置 4 的数字后，[0,1,1,1,1,1,0,1] 的最长全 1 子数组为 [1,1,1,1,1] 。
示例 3：

输入：nums = [1,1,1]
输出：2
解释：你必须要删除一个元素。*/
#include <bits/stdc++.h>
using namespace std;
//不定长滑动窗口，且允许存在一个0
class Solution {
    public:
        int longestSubarray(vector<int>& nums) {
            int n=nums.size(), cnt=0,left=0, right=0;//cnt表示0的个数 左右指针
            while(right<n){
                if(nums[right]==0) cnt++;
                if(cnt>1){//多于一个0，左指针右移
                    if(nums[left]==0) cnt--;
                    left++;
                }
                right++;
            }
            return right-1-left;
        }
    };