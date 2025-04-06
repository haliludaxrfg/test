class Solution {
    // m 在 l 和 r 之间（写不写等号都可以）
    bool in_between(int l, int m, int r) {
        return min(l, r) < m && m < max(l, r);
    }

public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        if (a == e && (c != e || !in_between(b, d, f)) || // 车直接攻击到皇后（同一行）
            b == f && (d != f || !in_between(a, c, e)) || // 车直接攻击到皇后（同一列）
            c + d == e + f && (a + b != e + f || !in_between(c, a, e)) || // 象直接攻击到皇后
            c - d == e - f && (a - b != e - f || !in_between(c, a, e))) {
            return 1;
        }
        return 2;
    }
};

//作者：灵茶山艾府
//链接：https://leetcode.cn/problems/minimum-moves-to-capture-the-queen/solutions/1/fen-lei-tao-lun-jian-ji-xie-fa-pythonjav-aoa8/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。