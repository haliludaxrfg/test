//寻找元素互斥的子数组最大和
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int maximumUniqueSubarray(vector<int>& nums) {
            int result = 0;
            int current_sum = 0;
            int left = 0;
            unordered_set<int> seen;
            
            for (int right = 0; right < nums.size(); ++right) {
                // If the current number is already in the window, move the left pointer
                while (seen.find(nums[right]) != seen.end()) {
                    seen.erase(nums[left]);
                    current_sum -= nums[left];
                    left++;
                }
                // Add the current number to the window
                seen.insert(nums[right]);
                current_sum += nums[right];
                // Update the result if the current window sum is larger
                result = max(result, current_sum);
            }
            
            return result;
        }
    };