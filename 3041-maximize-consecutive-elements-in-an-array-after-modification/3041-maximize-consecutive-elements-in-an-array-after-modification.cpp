class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        unordered_map<int, int> dp;
        int ans = 0;

        for(int x:nums){
            int old = dp[x];
            // Th1: x giu nguyen
            dp[x] = max(dp[x], dp[x - 1] + 1);
            // Th1: x tang 1
            dp[x + 1] = max(dp[x + 1], old + 1);

            ans = max({ans, dp[x], dp[x + 1]});
        }
        return ans;
    }
};