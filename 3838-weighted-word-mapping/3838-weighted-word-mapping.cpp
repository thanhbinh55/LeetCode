/*
 * @lc app=leetcode id=3838 lang=cpp
 *
 * [3838] Weighted Word Mapping
 */

// @lc code=start
class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans;
        ans.reserve(words.size());
        for (string word : words) {
            int s = 0;
            for (char c : word) {
                s += weights[c - 'a'];
            }
            ans += 'z' - s % 26;
        }
        return ans;
    }
};
// @lc code=end

