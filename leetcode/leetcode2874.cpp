class Solution {
    public:
    //假设存在最优三元组(i, j, k)，则当遍历到j时，leftMax[j]必定≥nums[i]，rightMax[j]必定≥nums[k]。
    //因此，(leftMax[j] - nums[j]) * rightMax[j] ≥ (nums[i] - nums[j]) * nums[k]，即该方法不会漏掉最优解。
        long long maximumTripletValue(vector<int>& nums) {
            int n = nums.size();
            vector<int> leftMax(n), rightMax(n);
            for (int i = 1; i < n; i++) {
                leftMax[i] = max(leftMax[i - 1], nums[i - 1]);
                rightMax[n - 1 - i] = max(rightMax[n - i], nums[n - i]);
            }
            long long res = 0;
            for (int j = 1; j < n - 1; j++) {
                res = max(res, (long long)(leftMax[j] - nums[j]) * rightMax[j]);
            }
            return res;
        }
    };
    