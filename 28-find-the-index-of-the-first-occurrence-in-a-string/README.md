# 28. Find the Index of the First Occurrence in a String

**Difficulty:** Easy  
**Link:** https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/

## Summary

Given two strings `needle` and `haystack`, return the index of the first occurrence of `needle` in `haystack`, or `-1` if `needle` is not part of `haystack`.

## Examples

```text
Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.
```

```text
Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.
```

## Approach

Use a sliding window of size equal to the length of `needle`:
1. Iterate through `haystack` from index `0` up to `haystack_len - needle_len`.
2. Extract the substring of length `needle_len` starting at the current index.
3. Compare the substring with `needle`. If they match, return the current index.
4. If the loop completes without finding a match, return `-1`.

## Complexity

- Time: `O((N - M + 1) * M)` where `N` is the length of `haystack` and `M` is the length of `needle`, because of substring generation and comparison at each position.
- Space: `O(M)` due to the creation of the temporary substring of length `M` in each iteration.

## Results

- **Runtime:** 3 ms (beats 20.03% of C++ submissions)
- **Memory Usage:** 9.1 MB (beats 46.12% of C++ submissions)

