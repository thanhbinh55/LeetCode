# LeetCode

Daily LeetCode practice solutions.

## Structure

- Each problem has its own folder.
- Folder format: `0009-palindrome-number`
- Solution file format: `0009-palindrome-number.cpp`
- Each folder includes a short `README.md` with the problem link, examples, approach, and complexity.

Example:

```text
0009-palindrome-number/
├── 0009-palindrome-number.cpp
└── README.md
```

## Daily Workflow

```bash
git status
git add .
git commit -m "Add solution for problem <number>"
git push
```

## VS Code LeetCode Extension

The VS Code LeetCode extension is configured to save new problems inside this repo.

After clicking `Code Now`, run:

```bash
python3 scripts/normalize_leetcode.py
```

This converts extension output such as:

```text
13-roman-to-integer/13-roman-to-integer.cpp
```

into the repo format:

```text
0013-roman-to-integer/
├── 0013-roman-to-integer.cpp
└── README.md
```

## Naming Checklist

1. Pad the problem number to 4 digits.
2. Use the lowercase LeetCode slug.
3. Keep the folder name and solution file name consistent.
