class Solution {
public:
    int smallestNumber(int n, int t) {
        int res = n;
        while(true){
            int pr = 1;
            int k = res;
            while(k > 0){
                pr *= k % 10;
                k /= 10;
            }
            if (pr % t == 0) return res;
            res ++;
        }
    }
};