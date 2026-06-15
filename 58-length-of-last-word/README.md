# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
The last word may be followed by trailing spaces. Skip those spaces first, then count the characters of the first word encountered from the end of the string.
# Approach
<!-- Describe your approach to solving the problem. -->
1. Reverse the string.
2. Skip all leading spaces in the reversed string (which are trailing spaces in the original string).
3. Count consecutive letters until reaching a space or the end of the string.
4. Return the count.
# Complexity
- Time complexity: `O(n)`
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity: `O(1)` (ignoring the in-place reverse operation)
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
```cpp []
class Solution {
public:
    int lengthOfLastWord(string s) {
        reverse(s.begin(), s.end());
        int count = 0;
        int i = 0;
        while(s[i] == ' '){
            i++;
        }
        while('a' <= s[i] && s[i] <= 'z' || 'A' <= s[i] && s[i] <= 'Z'){
            i++;
            count++;
        }
        return count;
    }
};
```

# Results

- **Runtime:** 0 ms (beats 100 % of C++ submissions)
- **Memory Usage:** 8.7 MB (beats 91.77 %  of C++ submissions)