/*给你一个下标从 0 开始的字符串 s ，重复执行下述操作 任意 次：

在字符串中选出一个下标 i ，并使 c 为字符串下标 i 处的字符。并在 i 左侧（如果有）和 右侧（如果有）各 删除 一个距离 i 最近 的字符 c 。
请你通过执行上述操作任意次，使 s 的长度 最小化 。

返回一个表示 最小化 字符串的长度的整数。

示例 1：

输入：s = "aaabc"
输出：3
解释：在这个示例中，s 等于 "aaabc" 。我们可以选择位于下标 1 处的字符 'a' 开始。
接着删除下标 1 左侧最近的那个 'a'（位于下标 0）以及下标 1 右侧最近的那个 'a'（位于下标 2）。
执行操作后，字符串变为 "abc" 。继续对字符串执行任何操作都不会改变其长度。因此，最小化字符串的长度是 3 。
示例 2：

输入：s = "cbbd"
输出：3
解释：我们可以选择位于下标 1 处的字符 'b' 开始。
下标 1 左侧不存在字符 'b' ，但右侧存在一个字符 'b'（位于下标 2），
所以会删除位于下标 2 的字符 'b' 。执行操作后，字符串变为 "cbd" 。
继续对字符串执行任何操作都不会改变其长度。
因此，最小化字符串的长度是 3 。
示例 3：

输入：s = "dddaaa"
输出：2
解释：我们可以选择位于下标 1 处的字符 'd' 开始。
接着删除下标 1 左侧最近的那个 'd'（位于下标 0）以及下标 1 右侧最近的那个 'd'（位于下标 2）。
执行操作后，字符串变为 "daaa" 。继续对新字符串执行操作，可以选择位于下标 2 的字符 'a' 。
接着删除下标 2 左侧最近的那个 'a'（位于下标 1）以及下标 2 右侧最近的那个 'a'（位于下标 3）。
执行操作后，字符串变为 "da" 。继续对字符串执行任何操作都不会改变其长度。因此，最小化字符串的长度是 2 。
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimizedStringLength(string s){
       int mask=0;
       for(char c:s){
              mask|=(1<<(c-'a'));//将字符c对应的位设为1 
       }
       return __builtin_popcount(mask);//返回mask中1的个数
       //*__builtin_popcount(mask)是gcc内置函数，返回mask中1的个数
       //也可以用__builtin_popcountll(mask)来处理64位整数
         //或者用std::bitset<26>(mask).count()来处理
         //或者用std::count_if(s.begin(),s.end(),[&](char c){return mask&(1<<(c-'a'));})来处理
         //或者用std::unordered_set<char> set(s.begin(),s.end());return set.size();来处理
         //或者用std::set<char> set(s.begin(),s.end());return set.size();来处理
            //或者用std::unordered_map<char,int> map;for(char c:s)map[c]++;return map.size();来处理
            //或者用std::map<char,int> map;for(char c:s)map[c]++;return map.size();来处理
            //或者用std::vector<int> vec(26,0);for(char c:s)vec[c-'a']++;return std::count_if(vec.begin(),vec.end(),[](int i){return i>0;});来处理
            //或者用std::array<int,26> arr;for(char c:s)arr[c-'a']++;return std::count_if(arr.begin(),arr.end(),[](int i){return i>0;});来处理
            //或者用std::unordered_set<char> set(s.begin(),s.end());return set.size();来处理
            //或者用std::set<char> set(s.begin(),s.end());return set.size();来处理
            //或者用std::unordered_map<char,int> map;for(char c:s)map[c]++;return map.size();来处理
            //或者用std::map<char,int> map;for(char c:s)map[c]++;return map.size();来处理
            //或者用std::vector<int> vec(26,0);for(char c:s)vec[c-'a']++;return std::count_if(vec.begin(),vec.end(),[](int i){return i>0;});来处理
            //或者用std::array<int,26> arr;for(char c:s)arr[c-'a']++;return std::count_if(arr.begin(),arr.end(),[](int i){return i>0;});来处理
            //或者用std::unordered_set<char> set(s.begin(),s.end());return set.size();来处理
            //或者用std::set<char> set(s.begin(),s.end());return set.size();来处理
            //或者用std::unordered_map<char,int> map;for(char c:s)map[c]++;return map.size();来处理
            //或者用std::map<char,int> map;for(char c:s)map[c]++;return map.size();来处理
            //或者用std::vector<int> vec(26,0);for(char c:s)vec[c-'a']++;return std::count_if(vec.begin(),vec.end(),[](int i){return i>0;});来处理
            //或者用std::array<int,26> arr;for(char c:s)arr[c-'a']++;return std::count_if(arr.begin(),arr.end(),[](int i){return i>0;});来处理
            //或者用std::array<int,26> arr;for(char c:s)arr[c-'a']++;return std::count_if(arr.begin(),arr.end(),[](int i){return i>0;});来处理
            //或者用std::unordered_set<char> set(s.begin(),s.end());return set.size();来处理
    }
};