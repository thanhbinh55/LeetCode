/*
 * @lc app=leetcode id=3532 lang=cpp
 *
 * [3532] Path Existence Queries in a Graph I
 */

// @lc code=start
class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> pref(n, 0);

        for (int i = 1; i < n; i++) {
            pref[i] = pref[i - 1];
            if (nums[i] - nums[i - 1] > maxDiff)
                pref[i]++;
        }

        vector<bool> ans;

        for (auto &q : queries) {
            int u = q[0];
            int v = q[1];

            if (u > v)
                swap(u, v);

            ans.push_back(pref[u] == pref[v]);
        }

        return ans;
    }
};
// @lc code=end

