#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int countSymmetricIntegers(int low, int high) {
            int ans = 0;
            for (int i = low; i <= high; i++) {
                string s = to_string(i);
                int n = s.size();
                if (n % 2 == 0) {
                    int left = 0, right = 0;
                    for (int j = 0; j < n / 2; j++) {
                        left += s[j] - '0';
                        right += s[n - j - 1] - '0';
                    }
                    if (left == right) ans++;
                }
            }
            return ans;
        }
    };