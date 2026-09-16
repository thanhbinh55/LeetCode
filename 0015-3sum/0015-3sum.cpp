class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // solution 1: 3 for loop -> Time Limit Exceeded
        // solution 2: sort -> unique value
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        // fix i -> 2 pointers
        for(int i = 0; i < nums.size() - 2; i++){
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int L = i + 1;
            int R = nums.size() - 1;
            while (L < R){
                int sum = nums[L] + nums[R];
                if(sum > -nums[i]){
                    R--;
                }else if(sum < -nums[i]){
                    L++;
                }else{
                    ans.push_back({nums[i],nums[L],nums[R]});
                    L++;
                    R--;

                    while(L<R && nums[L] == nums[L-1]) L++;
                    while(L<R && nums[R] == nums[R+1]) R--;
                }
            }
        }
        return ans;
    }
};