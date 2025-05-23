/*给你一个字符串 s ，请找出满足每个字符最多出现两次的最长子字符串，并返回该子字符串的 最大 长度。

示例 1：
输入： s = "bcbbbcba"
输出： 4
解释：
以下子字符串长度为 4，并且每个字符最多出现两次："bcbbbcba"。

示例 2：
输入： s = "aaaa"
输出： 2
解释：
以下子字符串长度为 2，并且每个字符最多出现两次："aaaa"。

提示：

2 <= s.length <= 100
s 仅由小写英文字母组成。*/
class Solution {
    public:
        int maximumLengthSubstring(string s) {
            int ans = 0, left = 0, cnt[26]{};
            for (int i = 0; i < s.length(); i++) {
                int b = s[i] - 'a';
                cnt[b]++;
                while (cnt[b] > 2) {
                    cnt[s[left++] - 'a']--;
                }
                ans = max(ans, i - left + 1);
            }
            return ans;
        }
    };
    
    //作者：灵茶山艾府
    //链接：https://leetcode.cn/problems/maximum-length-substring-with-two-occurrences/solutions/2704776/on-hua-dong-chuang-kou-pythonjavacgo-by-hl44d/
    //来源：力扣（LeetCode）
    //著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。