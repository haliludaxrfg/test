/*
 * @lc app=leetcode.cn id=1287 lang=cpp
 * @lcpr version=30005
 *
 * [1287] 有序数组中出现次数超过25%的元素
 *
 * https://leetcode.cn/problems/element-appearing-more-than-25-in-sorted-array/description/
 *
 * algorithms
 * Easy (58.25%)
 * Likes:    114
 * Dislikes: 0
 * Total Accepted:    46.4K
 * Total Submissions: 78.9K
 * Testcase Example:  '[1,2,2,6,6,6,6,7,10]'
 *
 * 给你一个非递减的 有序 整数数组，已知这个数组中恰好有一个整数，它的出现次数超过数组元素总数的 25%。
 * 
 * 请你找到并返回这个整数
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：arr = [1,2,2,6,6,6,6,7,10]
 * 输出：6
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= arr.length <= 10^4
 * 0 <= arr[i] <= 10^5
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
// @lcpr-template-end
// @lc code=start
class Solution {
    public:
        int findSpecialInteger(vector<int>& arr) {
            int n = arr.size();
            if (n == 1) return arr[0];
            int threshold = n / 4;
            int count = 1;
            for (int i = 1; i < n; ++i) {
                if (arr[i] == arr[i-1]) {
                    ++count;
                    if (count > threshold) {
                        return arr[i];
                    }
                } else {
                    count = 1;
                }
            }
            return arr.back();
        }
    };
// @lc code=end



/*
// @lcpr case=start
// [1,2,2,6,6,6,6,7,10]\n
// @lcpr case=end

 */

