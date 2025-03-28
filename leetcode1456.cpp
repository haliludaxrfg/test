#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int maxVowels(string s, int k) {
            //in
            int ans =0,vowels = 0;
            for(int i =0;i<s.length();i++){
                if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                    vowels++;
                }
                if(i<k-1) continue;
                ans = max(ans,vowels);
                if(s[i-k+1] == 'a' || s[i-k+1] == 'e' || s[i-k+1] == 'i' || s[i-k+1] == 'o' || s[i-k+1] == 'u'){
                    vowels--;
                }
            }
            return ans;
        }
    };