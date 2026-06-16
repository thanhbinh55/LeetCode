# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
The integer square root is the largest number whose square is less than or equal to `x`. We can keep checking numbers from `0` until the square becomes greater than `x`.

# Approach
<!-- Describe your approach to solving the problem. -->
1. Initialize `i = 0`.
2. Increase `i` while `i * i <= x`.
3. When the loop stops, `i` is already too large.
4. Return `i - 1`.
5. Use `long long` to avoid overflow when calculating `i * i`.

# Complexity
- Time complexity: `O(sqrt(x))`
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity: `O(1)`
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
```cpp []
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
```

# Results:
- **Runtime:** 19 ms (beats 6.56 % of C++ submissions)
- **Memory Usage:** 8.5 MB (beats 86.19 % of C++ submissions)
