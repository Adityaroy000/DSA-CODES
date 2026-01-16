class Solution {
public:
    int hammingDistance(int x, int y) {
        int xorNum = x^y;
        int cnt = __builtin_popcount(xorNum);
        return cnt;
    }
};