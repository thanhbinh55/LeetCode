class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails;

        for(int i = 0; i < nums.size(); i++){
            auto it = lower_bound(tails.begin(), tails.end(), nums[i]);
            int idx = it - tails.begin();
            if(it == tails.end()){
                tails.push_back(nums[i]);
            }else{
                tails[idx] = nums[i];
            }
        }

        return tails.size();
    }
};