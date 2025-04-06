/*给定一个字符串 s ，请你找出其中不含有重复字符的 最长 子串 的长度。

示例 1:

输入: s = "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: s = "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: s = "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 
提示：

0 <= s.length <= 5 * 10^4
s 由英文字母、数字、符号和空格组成*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> last_seen;
        int left = 0, max_len = 0;
        for (int right = 0; right < s.size(); right++) {
            if (last_seen.find(s[right]) != last_seen.end() && last_seen[s[right]] >= left) {
                left = last_seen[s[right]] + 1;
            }
            last_seen[s[right]] = right;
            max_len = max(max_len, right - left + 1);
        }
        return max_len;
    }
};
