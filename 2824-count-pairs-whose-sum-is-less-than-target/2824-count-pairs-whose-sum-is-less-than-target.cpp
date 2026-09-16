class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        // solution 1: 2 for loop
        int count = 0;
        for(int i = 0; i < nums.size() - 1; i++){
            for(int j = i + 1; j < nums.size(); j++){
                int sum = nums[i] + nums[j];
                if(sum < target){
                    count ++;
                }
            }
        }
        return count;
    }
};