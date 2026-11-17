
class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        const int INF = 1e9;

        // cost[l][r] -> so phep doi ky tu it nhat de s[l..r] thanh semi-palindrome
        vector<vector<int>> cost(n, vector<int>(n, INF));

        for (int l = 0; l < n; l++) {
            for (int r = l + 1; r < n; r++) {
                int len = r - l + 1;
                for (int d = 1; d < len; d++) {
                    if (len % d != 0) continue;
                    int changes = 0;
                    int groupLen = len / d;
                    for (int offset = 0; offset < d; offset++) {
                        for (int x = 0; x < groupLen / 2; x++) {
                            int i = l + offset + x * d;
                            int j = l + offset
                                  + (groupLen - 1 - x) * d;
                            if (s[i] != s[j]) {
                                changes++;
                            }
                        }
                    }

                    cost[l][r] = min(cost[l][r], changes);
                }
            }
        }

        // dp[p][i] -> chi phi nho nhat de chia i ky tu dau thanh p doan
        vector<vector<int>> dp(
            k + 1, vector<int>(n + 1, INF)
        );

        dp[0][0] = 0;
        for (int p = 1; p <= k; p++) {
            for (int i = 2 * p; i <= n; i++) {
                for (int j = 2 * (p - 1); j <= i - 2; j++) {
                    if (dp[p - 1][j] == INF) continue;
                    dp[p][i] = min(
                        dp[p][i],
                        dp[p - 1][j] + cost[j][i - 1]
                    );
                }
            }
        }

        return dp[k][n];
    }
};
