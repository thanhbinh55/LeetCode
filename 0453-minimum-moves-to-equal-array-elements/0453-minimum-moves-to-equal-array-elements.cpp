class Solution {
public:
    int minMoves(vector<int>& nums) {
        int count = 0;
        sort(nums.begin(), nums.end());
        for(auto n : nums) {
            count += n - nums[0];
        }
        return count;
    }
};