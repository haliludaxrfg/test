class Solution {
    public:
        int minSizeSubarray(vector<int>& nums, int target) {
            long long total = reduce(nums.begin(), nums.end(), 0LL);
            int n = nums.size();
            int ans = INT_MAX;
            int left = 0;
            long long sum = 0;
            for (int right = 0; right < n * 2; right++) {
                sum += nums[right % n];
                while (sum > target % total) {
                    sum -= nums[left++ % n];
                }
                if (sum == target % total) {
                    ans = min(ans, right - left + 1);
                }
            }
            return ans == INT_MAX ? -1 : ans + target / total * n;
        }
    };
    /*
    作者：灵茶山艾府
    链接：https://leetcode.cn/problems/minimum-size-subarray-in-infinite-array/solutions/2464878/hua-dong-chuang-kou-on-shi-jian-o1-kong-cqawc/
    来源：力扣（LeetCode）
    著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    */