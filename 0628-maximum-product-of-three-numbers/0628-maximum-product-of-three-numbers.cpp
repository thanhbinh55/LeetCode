class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        int maximum1 = nums[n - 1] * nums[n - 2] * nums[n - 3];
        int maximum2 = nums[0] * nums[1]*nums[n - 1];
        if(maximum1 > maximum2) return maximum1;
        return maximum2;
    }
};