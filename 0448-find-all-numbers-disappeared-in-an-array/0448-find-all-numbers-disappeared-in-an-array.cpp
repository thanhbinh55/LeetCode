class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {

        vector<bool> check(nums.size(), false);

        for (int i = 0; i < nums.size(); i++) {
            check[nums[i] - 1] = true;
        }

        vector<int> missing;

        for (int i = 0; i < nums.size(); i++) {
            if (!check[i]) {
                missing.push_back(i + 1);
            }
        }

        return missing;
    }
};