class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        // dp[j]: min cost tu 1 -> j

        vector<long long> dp(n + 1, 1e18);
        dp[0] = 0;

        for(int j = 1; j <= n; j++) {
            for(int i = 1; i <= 3; i++) {
                if(j - i >= 0) {
                    dp[j] = min(dp[j], dp[j - i] + costs[j - 1] + 1LL*i*i);
                }
            }
        }
        
        return dp[n];
    }
};