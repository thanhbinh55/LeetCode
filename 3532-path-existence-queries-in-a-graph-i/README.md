# Intuition

The graph is built on a line of nodes. For every adjacent pair $(i-1, i)$, there is an edge only when:

$$
|nums[i] - nums[i-1]| \le maxDiff
$$

So the graph is simply a set of connected segments. For a query $(u, v)$, there exists a path between them if and only if both nodes belong to the same segment.

# Approach

We can compress the problem into a prefix-based component labeling:

1. Create an array `pref` where `pref[i]` represents the component id of node `i`.
2. Start with `pref[0] = 0`.
3. For each `i` from `1` to `n - 1`:
   - Copy the previous component id.
   - If `abs(nums[i] - nums[i - 1]) > maxDiff`, then a new component starts, so increment `pref[i]`.
4. For each query `(u, v)`:
   - If `u > v`, swap them.
   - Answer is `true` if `pref[u] == pref[v]`, otherwise `false`.

Why this works:
- An edge exists between consecutive nodes only when the difference is small enough.
- Every time the difference is too large, the path breaks and a new connected component begins.
- Therefore, nodes in the same component are connected, and nodes in different components are not.

# Complexity

- Time complexity: `O(n + q)`
- Space complexity: `O(n)`

Where:
- `n` is the number of nodes
- `q` is the number of queries

# Code

```cpp
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
```

# Results
- **Test cases:** 550/550 passed
- **Runtime:** 14 ms (beats 64.92 % of C++ submissions)
- **Memory Usage:** 224.1 MB (beats 78.73 % of C++ submissions)