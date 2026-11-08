class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> countRow(m, 0);
        vector<int> countCol(n, 0);

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if (grid[i][j] == 1){
                    countRow[i] ++;
                    countCol[j] ++;
                }
            }
        }
        
        int countConnected = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if (grid[i][j] == 1){
                    if(countRow[i] > 1 || countCol[j] > 1){
                        countConnected++;
                    }
                }
            }
        }
        return countConnected;
    }
};