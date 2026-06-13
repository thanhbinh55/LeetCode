# Intuition
We can directly simulate the process described in the problem.

For each word in `words`, we iterate through all of its characters and accumulate their corresponding weights from the `weights` array.

Let the total weight be `w`. We compute `w % 26` and map it to a character in reverse alphabetical order by subtracting the remainder from `'z'`. Therefore, the resulting character is `'z' - (w % 26)`.

# Approach
For each word in `words`:

1. Initialize `w = 0`.
2. Traverse all characters in the word and add their corresponding weights to `w`.
3. Compute `w %= 26`.
4. Append the character `'z' - w` to the answer string.

Finally, return the constructed string.

# Complexity
Let `n` be the number of words and let `m` be the average length of a word.

- Time complexity: `O(Σ|words[i]|)`
- Space complexity: `O(1)` (excluding the output string).

# Results
- **Runtime:** 0 ms (beats 100% of C++ submissions)
