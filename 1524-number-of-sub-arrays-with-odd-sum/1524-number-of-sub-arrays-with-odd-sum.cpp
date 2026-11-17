class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        long long even = 1, odd = 0;
        long long count = 0;
        int sum = 0;

        for(int x : arr) {
            sum = (sum + x) % 2;

            if (sum == 1){
                count = (count + even) % MOD;
                odd++;
            } else {
                count = (count + odd) % MOD;
                even++;
            }
        }
        return count;
    }
};