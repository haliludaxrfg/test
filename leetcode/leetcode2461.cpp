/*给你一个整数数组 nums 和一个整数 k 。请你从 nums 中满足下述条件的全部子数组中找出最大子数组和：

子数组的长度是 k，且
子数组中的所有元素 各不相同 。
返回满足题面要求的最大子数组和。如果不存在子数组满足这些条件，返回 0 。

子数组 是数组中一段连续非空的元素序列。

示例 1：

输入：nums = [1,5,4,2,9,9,9], k = 3
输出：15
解释：nums 中长度为 3 的子数组是：
- [1,5,4] 满足全部条件，和为 10 。
- [5,4,2] 满足全部条件，和为 11 。
- [4,2,9] 满足全部条件，和为 15 。
- [2,9,9] 不满足全部条件，因为元素 9 出现重复。
- [9,9,9] 不满足全部条件，因为元素 9 出现重复。
因为 15 是满足全部条件的所有子数组中的最大子数组和，所以返回 15 。
示例 2：

输入：nums = [4,4,4], k = 3
输出：0
解释：nums 中长度为 3 的子数组是：
- [4,4,4] 不满足全部条件，因为元素 4 出现重复。
因为不存在满足全部条件的子数组，所以返回 0 。
 

提示：

1 <= k <= nums.length <= 10^5
1 <= nums[i] <= 10^5*/
class Solution {
    public:
        long long maximumSubarraySum(vector<int>& nums, int k) {
            unordered_map<int, int> freq;
            int unique_count = 0;
            long long current_sum = 0;
            long long max_sum = 0;

            int n = nums.size();
            for (int i = 0; i < n; ++i) {
                current_sum += nums[i];
                freq[nums[i]]++;

                if (freq[nums[i]] == 1) {
                    unique_count++;
                }

                if (i >= k) {
                    current_sum -= nums[i - k];
                    freq[nums[i - k]]--;

                    if (freq[nums[i - k]] == 0) {
                        unique_count--;
                    }
                }

                if (i >= k - 1 && unique_count == k) {
                    max_sum = max(max_sum, current_sum);
                }
            }
            return max_sum;
        }
    };