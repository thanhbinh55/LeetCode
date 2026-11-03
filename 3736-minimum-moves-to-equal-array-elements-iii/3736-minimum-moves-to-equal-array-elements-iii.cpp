class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count = 0;
        for(auto n : nums) {
            count += nums[nums.size() - 1]  - n;
        }
        return count;
    }
};