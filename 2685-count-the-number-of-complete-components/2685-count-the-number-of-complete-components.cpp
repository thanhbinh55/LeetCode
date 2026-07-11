/*
 * @lc app=leetcode id=2685 lang=cpp
 *
 * [2685] Count the Number of Complete Components
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> graph;
    vector<bool> visited;
    void dfs(int u, int &vertices, int &edg){
        visited[u] = true;
        for(int v: graph[u]){
            if(!visited[v]){
                dfs(v, vertices, edg);
            }
        }
        vertices++;
        edg += graph[u].size();
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        visited.assign(n, false);
        graph.assign(n,{});
        for(auto &e: edges){
            int u = e[0];
            int v = e[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        int ans=0;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                int vertices = 0;
                int edg = 0;
                dfs(i, vertices, edg);
                edg /= 2;
                if( edg == (vertices*(vertices-1)*0.5)){
                    ans++;
                }
            }
        }
        return ans;
        
    }
};
// @lc code=end

