class Solution {
public:
    void backtrack(vector<vector<int>> &ans, vector<int> &path, vector<int> nums, vector<bool> &visited){
        if(path.size() == nums.size()){
            ans.push_back(path);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(visited[i]) continue;

            visited[i] = true;
            path.push_back(nums[i]);

            backtrack(ans,path,nums,visited);

            visited[i] = false;
            path.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<bool> visited(nums.size(), false);
        vector<int> path;
        
        backtrack(ans, path, nums, visited);
        return ans;
    }
};