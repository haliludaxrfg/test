//寻找最长子数组
// 1658. 最小操作数使数组的和等于目标值
// https://leetcode.cn/problems/minimum-operations-to-reduce-x-to-zero/description/?envType=study-plan&id=algorithm-i&planid=algorithm-i&languageTags=cpp
class Solution {
    public:
        int minOperations(vector<int>& nums, int x) {
            int target = accumulate(nums.begin(), nums.end(), 0) - x;
            if (target < 0) return -1; // If target is negative, it's impossible to reach x
            if (target == 0) return nums.size(); // If target is zero, we need to remove all elements
            int max_length = 0,left = 0, right= 0, current_sum = 0;
            for(;right<nums.size();right++){
                current_sum += nums[right];
                while(current_sum > target){
                    current_sum -= nums[left++];
                }
                if(current_sum == target){
                    max_length = max(max_length, right - left + 1);
                }
            }
            return max_length == 0 ? -1 : nums.size() - max_length; // If no valid subarray found, return -1
        }
    };