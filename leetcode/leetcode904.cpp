// LeetCode 904. Fruit Into Baskets
// https://leetcode.com/problems/fruit-into-baskets/description/
//相当于求两个不同的字符的最长子串
class Solution {
    public:
        int totalFruit(vector<int>& fruits) {
            int result = 0, left = 0, right = 0;
            unordered_map<int, int> fruits_type;
            for(;right<fruits.size();++right){
                fruits_type[fruits[right]]++;
                while(fruits_type.size() > 2){//more than 2 types of fruits
                    //remove the leftmost fruit from the basket
                    fruits_type[fruits[left]]--;
                    if(fruits_type[fruits[left]] == 0){//remove it from the basket
                        fruits_type.erase(fruits[left]);
                    }
                    left++;//overflow
                }
                result = max(result, right-left+1);//update the result
            }
            return result;
        }
    };