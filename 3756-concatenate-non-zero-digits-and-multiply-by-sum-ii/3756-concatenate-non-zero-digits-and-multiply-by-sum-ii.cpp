/*
 * @lc app=leetcode id=3756 lang=cpp
 *
 * [3756] Concatenate Non-Zero Digits and Multiply by Sum II
 */

// @lc code=start
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int m = s.length();
        int q = queries.size();
        long long MOD = 1e9 + 7;

        vector<long long> pow10(m + 1, 1);
        for (int i = 1; i <= m; i++) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }

        vector<long long> pref_sum(m + 1, 0);       
        vector<long long> pref_num(m + 1, 0);      
        vector<int> non_zero_count(m + 1, 0);    

        for (int i = 0; i < m; i++) {
            int digit = s[i] - '0';
            
            pref_sum[i + 1] = pref_sum[i] + digit;

            if (digit != 0) {
                pref_num[i + 1] = (pref_num[i] * 10 + digit) % MOD;
                non_zero_count[i + 1] = non_zero_count[i] + 1;
            } else {
                pref_num[i + 1] = pref_num[i];
                non_zero_count[i + 1] = non_zero_count[i];
            }
        }

        vector<int> answer(q);
        for (int j = 0; j < q; j++) {
            int L = queries[j][0];
            int R = queries[j][1];

            long long sum = pref_sum[R + 1] - pref_sum[L];

            int k = non_zero_count[R + 1] - non_zero_count[L];

            if (k == 0) {
                answer[j] = 0;
                continue;
            }

            long long x = (pref_num[R + 1] - (pref_num[L] * pow10[k]) % MOD + MOD) % MOD;

            answer[j] = (x * (sum % MOD)) % MOD;
        }

        return answer;
    }
};

// @lc code=end

