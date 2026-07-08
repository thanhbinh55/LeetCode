# Intuition

We need to solve a range query problem. For each range [L, R]:
1. Concatenate all non-zero digits into a single number
2. Calculate the sum of all digits (including zeros)
3. Multiply the results from steps 1 and 2, then take modulo 10^9 + 7

Use **prefix arrays** to quickly compute the sum and concatenated number for any range.

# Approach

1. Calculate `pow10[i]` = 10^i mod (10^9 + 7) to support adjusting the concatenated number.

2. Build three prefix arrays:
   - `pref_sum[i]`: Sum of digits from index 0 to i-1
   - `pref_num[i]`: Number formed by non-zero digits from 0 to i-1 (mod 10^9 + 7)
   - `non_zero_count[i]`: Count of non-zero digits from 0 to i-1

3. For each query [L, R]:
   - Calculate digit sum: `sum = pref_sum[R+1] - pref_sum[L]`
   - Count non-zero digits: `k = non_zero_count[R+1] - non_zero_count[L]`
   - If k = 0, return 0
   - Calculate concatenated number: `x = (pref_num[R+1] - pref_num[L] * pow10[k]) mod (10^9 + 7)`
   - Result: `(x * sum) mod (10^9 + 7)`

# Complexity

- Time complexity: `O(m + q)` 
  
  m is the string length (preprocessing), q is the number of queries.

- Space complexity: `O(m)`

  Storage for three prefix arrays and the power of 10 array.

# Code

```cpp
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
```

# Results
- **Test cases:** 523/523 passed
- **Runtime:** 48 ms (beats 44.04 % of C++ submissions)
- **Memory Usage:** 155.2 MB (beats 67.36 % of C++ submissions)

