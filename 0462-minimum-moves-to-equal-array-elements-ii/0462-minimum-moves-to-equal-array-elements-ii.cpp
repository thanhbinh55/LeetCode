class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int median = nums.size() / 2;
        int res = 0;
        for(auto n : nums) {
            res += abs(n - nums[median]);
        }
        return res;
    }
};