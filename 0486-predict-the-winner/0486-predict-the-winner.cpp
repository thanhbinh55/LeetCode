class Solution {
public:
    vector<vector<int>> memo;

    int dfs(int i, int j, vector<int>& nums) {
        // Chỉ còn 1 số
        if (i == j) return nums[i];

        if (memo[i][j] != INT_MIN)
            return memo[i][j];

        // Lấy bên trái
        int takeLeft = nums[i] - dfs(i + 1, j, nums);

        // Lấy bên phải
        int takeRight = nums[j] - dfs(i, j - 1, nums);

        return memo[i][j] = max(takeLeft, takeRight);
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        memo.assign(n, vector<int>(n, INT_MIN));

        return dfs(0, n - 1, nums) >= 0;
    }
};