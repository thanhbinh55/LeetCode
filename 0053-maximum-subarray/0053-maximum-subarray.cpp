class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long current_prefix = 0;
        long long min_prefix = 0; // prefix_sum[-1] = 0
        long long max_so_far = nums[0];
        
        for(int x: nums){
            current_prefix += x;

            max_so_far = max(max_so_far, current_prefix - min_prefix);

            min_prefix = min(min_prefix, current_prefix);
        }
        
        return (int)(max_so_far);
    }
};