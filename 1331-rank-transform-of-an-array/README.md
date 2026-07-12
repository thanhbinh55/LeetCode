# Intuition

We need to transform each value in the array into its rank based on its relative order.
- Smaller values should get smaller ranks.
- Equal values should get the same rank.

This can be solved by sorting the values while remembering their original indices.

# Approach

1. Create a list of pairs `(value, index)` from the array.
2. Sort the pairs by `value`.
3. Traverse the sorted pairs from left to right:
   - If the current value is the same as the previous one, assign the same rank.
   - Otherwise, increase the rank by 1 and assign the new rank.
4. Store the assigned rank back into the original position using the saved index.

Why this works:
- Sorting groups equal values together.
- Each distinct value appears in a contiguous block, so all elements in that block receive the same rank.
- When a new distinct value appears, the rank increases by exactly 1, which matches the problem requirement.

# Complexity

- Time complexity: `O(n log n)`
- Space complexity: `O(n)`

Where:
- `n` is the length of the array

# Code

```cpp
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<pair<int,int>> p;

        for (int i = 0; i < arr.size(); i++) {
            p.push_back({arr[i], i});
        }

        sort(p.begin(), p.end());

        vector<int> ans(arr.size(), 1);
        int rank = 1;

        for (int i = 1; i < p.size(); i++) {
            if (p[i].first == p[i - 1].first) {
                ans[p[i].second] = rank;
            } else {
                rank++;
                ans[p[i].second] = rank;
            }
        }

        return ans;
    }
};
```

# Results
- **Test cases:** 43/43 passed
- **Runtime:** 17 ms (beats 98.66 % of C++ submissions)
- **Memory Usage:** 39.8 MB (beats 89.54 % of C++ submissions)