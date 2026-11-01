class Solution {
public:
    int minMoves(vector<int>& nums) {
        int count = 0;
        int minv = nums[0];
        for(auto n : nums){
            minv = min(minv, n);
        }
        for(auto n : nums) {
            count += n - minv;
        }
        return count;
    }
};