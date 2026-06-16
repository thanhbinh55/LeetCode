/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        long long i = 0;
        while (i*i <= x){
            i++;
        }
        return i - 1;
    }
};
// @lc code=end

