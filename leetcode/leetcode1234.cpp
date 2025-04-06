class Solution {
    public:
        int balancedString(string s) {
            int n = s.length(), m = n / 4, cnt['X']{}; // 初始化字符计数数组
            for (char c : s) ++cnt[c]; // 统计所有字符的出现次数
            if (cnt['Q'] == m && cnt['W'] == m && cnt['E'] == m && cnt['R'] == m)
                return 0; // 已经平衡，无需替换
            
            int ans = n, left = 0;
            for (int right = 0; right < n; ++right) { // 遍历右指针
                --cnt[s[right]]; // 将当前字符归入窗口内，减少窗口外计数
                // 当窗口外所有字符的计数 ≤ m 时，缩小窗口
                while (cnt['Q'] <= m && cnt['W'] <= m && cnt['E'] <= m && cnt['R'] <= m) {
                    ans = min(ans, right - left + 1); // 更新最短窗口长度
                    ++cnt[s[left++]]; // 移动左指针，将字符归回窗口外
                }
            }
            return ans;
        }
    };