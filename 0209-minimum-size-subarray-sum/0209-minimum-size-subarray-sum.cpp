class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int L = 0;
        int cur_sum = 0;
        int min_len = nums.size() + 1;

        for(int R = 0; R < n; R++){
            cur_sum += nums[R];
            
            if(cur_sum >= target){
                while(cur_sum >= target){
                    min_len = min(min_len, R - L + 1);
                    cur_sum -= nums[L];
                    L++;
                }
            }
        }
        return min_len != n + 1 ? min_len : 0;
    }
};