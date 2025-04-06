#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int max_length = 0;
        int left = 0;
        int count_T = 0, count_F = 0;

        for (int right = 0; right < answerKey.size(); ++right) {
            if (answerKey[right] == 'T') {
                count_T++;
            } else {
                count_F++;
            }

            // Determine the minimum number of flips needed
            int min_flips = min(count_T, count_F);

            // If the minimum flips exceed k, move the left pointer
            if (min_flips > k) {
                if (answerKey[left] == 'T') {
                    count_T--;
                } else {
                    count_F--;
                }
                left++;
            }

            // Update the maximum length
            max_length = max(max_length, right - left + 1);
        }

        return max_length;
    }
}; 