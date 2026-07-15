class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        // sumOdd = 1 + 3 + 5 + ... + (2n-1) = n^2
        // sumEven= 2 + 4 + 6 + ... + 2n     = n(n-1)
        return gcd(n*n, n*(n-1));
    }
};