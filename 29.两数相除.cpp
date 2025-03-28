class Solution {
    public:
        int divide(int dividend, int divisor) {
            // 处理边界情况
            if (dividend == INT_MIN) {
                if (divisor == 1) return INT_MIN;
                if (divisor == -1) return INT_MAX;
            }
            if (divisor == INT_MIN) {
                return dividend == INT_MIN ? 1 : 0;
            }
            if (dividend == 0) return 0;
    
            // 转换为负数处理
            bool rev = false;
            if (dividend > 0) {
                dividend = -dividend;
                rev = !rev;
            }
            if (divisor > 0) {
                divisor = -divisor;
                rev = !rev;
            }
    
            // 快速乘法：判断 y * z >= x（y、x为负数，z为正数）
            auto quickAdd = [](int y, int z, int x) {
                int result = 0, add = y;
                while (z) {
                    if (z & 1) {
                        // 确保 result + add >= x（否则溢出）
                        if (result < x - add) return false;
                        result += add;
                    }
                    if (z >>= 1) { // 准备处理下一位，检查翻倍是否溢出
                        if (add < x - add) return false;
                        add += add;
                    }
                }
                return true;
            };
    
            // 二分查找范围：left=1, right=上限（避免溢出）
            int left = 1, right = (dividend == INT_MIN && divisor == -1) ? INT_MAX : -dividend;
            int ans = 0;
            while (left <= right) {
                int mid = left + ((right - left) >> 1);
                bool check = quickAdd(divisor, mid, dividend);
                if (check) {
                    ans = mid;
                    if (mid == INT_MAX) break; // 防止溢出
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
    
            return rev ? -ans : ans;
        }
    };