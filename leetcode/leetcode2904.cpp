#include <deque>
#include <string>
using namespace std;

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        deque<int> ones_pos; // 保存窗口中'1'的索引
        int min_len = INT_MAX;
        string ans = "";
        int left = 0;

        for (int right = 0; right < s.size(); ++right) {
            if (s[right] == '1') {
                ones_pos.push_back(right);
            }

            // 当队列中的'1'数量超过k时，移除最前面的'1'并调整左边界
            while (ones_pos.size() > k) {
                if (ones_pos.front() >= left) {
                    left = ones_pos.front() + 1;
                }
                ones_pos.pop_front();
            }

            // 当恰好有k个'1'时，计算当前窗口信息
            if (ones_pos.size() == k) {
                int start = ones_pos.front();
                int current_len = right - start + 1;

                // 如果找到更短的子串，或者同样长度但字典序更小的子串
                if (current_len < min_len || (current_len == min_len && s.substr(start, current_len) < ans)) {
                    min_len = current_len;
                    ans = s.substr(start, current_len);
                }
            }
        }

        return ans;
    }
};