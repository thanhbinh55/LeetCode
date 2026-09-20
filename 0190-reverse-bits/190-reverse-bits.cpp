/*
 * @lc app=leetcode id=190 lang=cpp
 *
 * [190] Reverse Bits
 */

// @lc code=start
class Solution {
public:
    int reverseBits(int n) {
        int s = 0;
        for (int i = 0; i < 32; i++) {
            int c = n & 1;
            n >>= 1;
            s |= c << (31 - i);
        }
        return s;
    }
};
// @lc code=end
