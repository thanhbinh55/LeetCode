class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // solution 1: 2 for loop -> time exceeded
        // solution 2: two pointers
            int L = 0;
            int R = numbers.size() - 1;
            while (L < R){
                int sum = numbers[L] + numbers[R];
                if (sum > target){
                    R--;
                }else if(sum < target){
                    L++;
                }else{
                    return {L + 1, R + 1};
                }
            }
        return {};
    }
};