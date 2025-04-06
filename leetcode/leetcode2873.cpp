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
    
    //作者：力扣官方题解
    //链接：https://leetcode.cn/problems/maximum-value-of-an-ordered-triplet-i/solutions/3610891/you-xu-san-yuan-zu-zhong-de-zui-da-zhi-i-y6zb/
    //来源：力扣（LeetCode）
    //著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。