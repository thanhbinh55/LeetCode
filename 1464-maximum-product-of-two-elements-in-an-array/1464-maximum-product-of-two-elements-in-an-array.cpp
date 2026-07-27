class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // for(int i = 0; i < nums.size(); i++){
        //     nums[i] = nums[i] - 1;
        // }
        sort(nums.begin(), nums.end());
        return (nums[nums.size() - 1] - 1) * (nums[nums.size() - 2] - 1);
    }
};