/*Given two strings s and t of lengths m and n respectively, 
return the minimum window substring of s such that every character 
in t (including duplicates) is included in the window. 
If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC" Output: "BANC" Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

Input: s = "a", t = "a" Output: "a" Explanation: The entire string s is the minimum window. Example 3:

Input: s = "a", t = "aa" Output: "" Explanation: Both 'a's from t must be included in the window. Since the largest window of s only has one 'a', return empty string.

Constraints:

m == s.length n == t.length 1 <= m, n <= 105 s and t consist of uppercase and lowercase English letters.

Follow up: Could you find an algorithm that runs in O(m + n) time?*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if(s.empty() || t.empty()) return "";

        unordered_map<char, int> t_count, s_count;
        for(char c : t) {
            t_count[c]++;
        }
        int required = t_count.size();
        int formed = 0;
        int left = 0, right = 0;
        int min_len = INT_MAX, min_left = 0;
        while(right < s.size()) {
            char c = s[right];
            s_count[c]++;
            if(t_count.count(c) && s_count[c] == t_count[c]) {
                formed++;
            }
            while(left <= right && formed == required) {
                if(right - left + 1 < min_len) {
                    min_len = right - left + 1;
                    min_left = left;
                }
                char left_char = s[left];
                s_count[left_char]--;
                if(t_count.count(left_char) && s_count[left_char] < t_count[left_char]) {
                    formed--;
                }
                left++;
            }
            right++;
        }
        return min_len == INT_MAX ? "" : s.substr(min_left, min_len);
        
    }
};
