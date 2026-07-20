class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid[0].size();
        int m = grid.size();
        vector<vector<int>> ans(m, vector<int>(n));

        vector<int> gridArr(grid.size());
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int newIdx = ((i*n + j + k) % (n*m));
                ans[newIdx/n][newIdx%n] = grid[i][j];

            }
        }

        return ans;
    }
};