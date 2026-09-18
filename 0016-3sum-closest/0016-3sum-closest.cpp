class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int sum = nums[0] + nums[1] + nums[n - 1];

        for(int i = 0; i < n - 2; i++){
            int L = i + 1;
            int R = n - 1;

            while(L<R){
                int new_sum = nums[i] + nums[L] + nums[R];
                int delta_sum = abs(sum - target);
                int delta_new_sum = abs(new_sum - target);

                if(delta_new_sum < delta_sum){
                    sum = new_sum;
                }

                if(new_sum > target) R--;
                else if (new_sum < target) L++;
                else{
                    R--;
                    L++;

                    while(L < R && nums[R] == nums[R+1]) R--;
                    while(L < R && nums[L] == nums[L-1]) L++;
                }
            }
        }
        return sum;
    }
};