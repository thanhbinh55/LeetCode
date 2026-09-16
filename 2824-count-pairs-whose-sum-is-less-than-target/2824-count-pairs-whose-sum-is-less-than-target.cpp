class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        // solution 1: 2 for loop
        // solution 2: sort + two pointers
        int L = 0;
        int R = nums.size() - 1;
        long long ans = 0;
        sort(nums.begin(), nums.end());
        while(L < R) {
            if(nums[L] + nums[R] < target){
                ans += R - L;
                L++;
            }else{
                R--;
            }
        }
        return ans;
    }
};