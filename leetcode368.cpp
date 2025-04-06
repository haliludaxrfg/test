// LeetCode 368. Largest Divisible Subset
// https://leetcode.com/problems/largest-divisible-subset/description/
//最大整除子集
//dfs+memo
class Solution {
    public:
        vector<int> largestDivisibleSubset(vector<int>& nums) {
            ranges::sort(nums);
            int n = nums.size();
            vector<int> memo(n), from_(n, -1);
    
            auto dfs = [&](this auto&& dfs, int i) -> int {
                int& res = memo[i]; // 注意这里是引用
                if (res) { // 之前计算过
                    return res;
                }
                for (int j = 0; j < i; j++) {
                    if (nums[i] % nums[j]) {
                        continue;
                    }
                    int f = dfs(j);
                    if (f > res) {
                        res = f;
                        from_[i] = j; // 记录最佳转移来源
                    }
                }
                res++; // 加上 nums[i] 自己
                return res;
            };
    
            int max_f = 0, max_i = 0;
            for (int i = 0; i < n; i++) {
                int f = dfs(i);
                if (f > max_f) {
                    max_f = f;
                    max_i = i; // 最长合法子序列的最后一个数的下标
                }
            }
    
            vector<int> path;
            for (int i = max_i; i >= 0; i = from_[i]) {
                path.push_back(nums[i]);
            }
            return path; // 不需要 reverse，任意顺序返回均可
        }
    };
//resection+memo
class Solution {
    public:
        vector<int> largestDivisibleSubset(vector<int>& nums) {
            ranges::sort(nums);
    
            int n = nums.size();
            vector<int> f(n), from_(n, -1);
            int max_i = 0;
    
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < i; j++) {
                    if (nums[i] % nums[j] == 0 && f[j] > f[i]) {
                        f[i] = f[j];
                        from_[i] = j; // 记录最佳转移来源
                    }
                }
                f[i]++;
                if (f[i] > f[max_i]) {
                    max_i = i; // 最长合法子序列的最后一个数的下标
                }
            }
    
            vector<int> path;
            for (int i = max_i; i >= 0; i = from_[i]) {
                path.push_back(nums[i]);
            }
            return path; // 不需要 reverse，任意顺序返回均可
        }
    };
//Dp
class Solution {
    public:
        vector<int> largestDivisibleSubset(vector<int>& nums) {
            int len = nums.size();
            sort(nums.begin(), nums.end());
    
            // 第 1 步：动态规划找出最大子集的个数、最大子集中的最大整数
            vector<int> dp(len, 1);
            int maxSize = 1;
            int maxVal = dp[0];
            for (int i = 1; i < len; i++) {
                for (int j = 0; j < i; j++) {
                    // 题目中说「没有重复元素」很重要
                    if (nums[i] % nums[j] == 0) {
                        dp[i] = max(dp[i], dp[j] + 1);
                    }
                }
    
                if (dp[i] > maxSize) {
                    maxSize = dp[i];
                    maxVal = nums[i];
                }
            }
    
            // 第 2 步：倒推获得最大子集
            vector<int> res;
            if (maxSize == 1) {
                res.push_back(nums[0]);
                return res;
            }
    
            for (int i = len - 1; i >= 0 && maxSize > 0; i--) {
                if (dp[i] == maxSize && maxVal % nums[i] == 0) {
                    res.push_back(nums[i]);
                    maxVal = nums[i];
                    maxSize--;
                }
            }
            return res;
        }
    };
    
    