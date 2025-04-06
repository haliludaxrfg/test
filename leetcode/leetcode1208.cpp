class Solution {
    public:
        int equalSubstring(string s, string t, int maxCost) {
            int result = 0, left = 0, right = 0, cost = 0;
            for(;right<s.size();++right){
                cost += abs(s[right]-t[right]);
                while(cost > maxCost){
                    cost -= abs(s[left]-t[left]);
                    left++;//overflow
                }
                result = max(result, right-left+1);
            }
            return result;
        }
    };