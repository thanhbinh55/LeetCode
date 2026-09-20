# 9. Palindrome Number

**Difficulty:** Easy  
**Link:** https://leetcode.com/problems/palindrome-number/

## Summary

Given an integer `x`, determine whether it reads the same forward and backward.

Negative numbers are not palindromes because of the leading minus sign.

## Examples

```text
Input: x = 121
Output: true
```

```text
Input: x = -121
Output: false
```

```text
Input: x = 10
Output: false
```

## Approach

Reverse the digits of `x` and compare the reversed value with the original number.

## Complexity

- Time: `O(log10 n)`
- Space: `O(1)`
