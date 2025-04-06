/*
 * @lc app=leetcode.cn id=3291 lang=cpp
 * @lcpr version=20004
 *
 * [3291] 形成目标字符串需要的最少字符串数 I
 *
 * https://leetcode.cn/problems/minimum-number-of-valid-strings-to-form-target-i/description/
 *
 * algorithms
 * Medium (21.74%)
 * Likes:    14
 * Dislikes: 0
 * Total Accepted:    3K
 * Total Submissions: 11.1K
 * Testcase Example:  '["abc","aaaaa","bcdef"]\n"aabcdabc"'
 *
 * 给你一个字符串数组 words 和一个字符串 target。
 * 
 * 如果字符串 x 是 words 中 任意 字符串的 前缀，则认为 x 是一个 有效 字符串。
 * 
 * 现计划通过 连接 有效字符串形成 target ，请你计算并返回需要连接的 最少 字符串数量。如果无法通过这种方式形成 target，则返回
 * -1。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入： words = ["abc","aaaaa","bcdef"], target = "aabcdabc"
 * 
 * 输出： 3
 * 
 * 解释：
 * 
 * target 字符串可以通过连接以下有效字符串形成：
 * 
 * 
 * words[1] 的长度为 2 的前缀，即 "aa"。
 * words[2] 的长度为 3 的前缀，即 "bcd"。
 * words[0] 的长度为 3 的前缀，即 "abc"。
 * 
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入： words = ["abababab","ab"], target = "ababaababa"
 * 
 * 输出： 2
 * 
 * 解释：
 * 
 * target 字符串可以通过连接以下有效字符串形成：
 * 
 * 
 * words[0] 的长度为 5 的前缀，即 "ababa"。
 * words[0] 的长度为 5 的前缀，即 "ababa"。
 * 
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入： words = ["abcdef"], target = "xyz"
 * 
 * 输出： -1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= words.length <= 100
 * 1 <= words[i].length <= 5 * 10^3
 * 输入确保 sum(words[i].length) <= 10^5。
 * words[i] 只包含小写英文字母。
 * 1 <= target.length <= 5 * 10^3
 * target 只包含小写英文字母。
 * 
 * 
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <string>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int minValidStrings(vector<string>& words, string target) {
        
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["abc","aaaaa","bcdef"]\n"aabcdabc"\n
// @lcpr case=end

// @lcpr case=start
// ["abababab","ab"]\n"ababaababa"\n
// @lcpr case=end

// @lcpr case=start
// ["abcdef"]\n"xyz"\n
// @lcpr case=end

 */

