class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;

        int n = nums.size();
        for(int i = 0; i < n-3; i++){
            if(i>0 && nums[i] == nums[i - 1]) continue;
            
            for(int j = i + 1; j < n-2; j++){
                if(j>i+1 && nums[j] == nums[j - 1]) continue;

                int L = j + 1;
                int R = n - 1;
                long long need = (long long)target - nums[i] - nums[j];
                
                while(L < R){
                    long long sum = nums[L] + nums[R];
                    if(sum > need){
                        R--;
                    }else if(sum < need){
                        L++;
                    }else{
                        ans.push_back({nums[i], nums[j],nums[L],nums[R]});
                        L++;
                        R--;

                        while (L < R && nums[R] == nums[R+1])
                            R--;

                        while (L < R && nums[L] == nums[L-1])
                            L++;
                    }
                }
            }
        }
       
        return ans;
    }
};