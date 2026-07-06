# Intuition
Ta can dao nguoc 32 bit cua so `n`. Cach don gian la lay tung bit tu phai sang trai cua `n`, roi dat bit do vao vi tri doi xung trong ket qua.

Vi du bit cuoi cung cua `n` se tro thanh bit dau tien cua ket qua.

# Approach
1. Khoi tao `s = 0` de luu ket qua sau khi dao bit.
2. Lap 32 lan vi de bai yeu cau dao nguoc dung 32 bit.
3. Dung `n & 1` de lay bit cuoi cung cua `n`.
4. Dung `n >>= 1` de dich `n` sang phai 1 bit, tuc la bo bit vua lay.
5. Dung `c << (31 - i)` de dua bit vua lay sang vi tri doi xung.
6. Dung `s |= ...` de gan bit do vao ket qua.
7. Sau 32 lan lap, tra ve `s`.

# Complexity
- Time complexity: `O(1)`

Vi vong lap luon chay dung 32 lan, khong phu thuoc vao gia tri cua `n`.

- Space complexity: `O(1)`

Chi dung mot vai bien phu.

# Code
```cpp
class Solution {
public:
    int reverseBits(int n) {
        int s = 0;
        for (int i = 0; i < 32; i++) {
            int c = n & 1;
            n >>= 1;
            s |= c << (31 - i);
        }
        return s;
    }
};
```

# Results
# Results
- **Test cases:** 600/600 passed
- **Runtime:** 2 ms (beats 35.92 % of C++ submissions)
- **Memory Usage:** 8.2 MB (beats 45.98 % of C++ submissions)

