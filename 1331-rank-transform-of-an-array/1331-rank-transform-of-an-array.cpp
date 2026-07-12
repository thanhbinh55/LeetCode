/*
 * @lc app=leetcode id=1331 lang=cpp
 *
 * [1331] Rank Transform of an Array
 */

// @lc code=start
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<pair<int,int>> p;
        
        for(int i = 0; i < arr.size(); i++){
            p.push_back({arr[i], i}); // (val2,idx2), (val1, idx1)
        }
        
        sort(p.begin(), p.end()); // (val1 < val2)-> (val1,idx1), (val2, idx2)
        
        vector<int> ans(arr.size(),1);
        int rank = 1;
        for(int i = 1; i < p.size(); i++){
            if(p[i].first == p[i-1].first){
                ans[p[i].second] = rank;
            }else{
                rank++;
                ans[p[i].second] = rank;
            }
        }
        return ans;
    }
};
// @lc code=end

