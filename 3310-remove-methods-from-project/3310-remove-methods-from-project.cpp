class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {

        vector<vector<int>> g(n);

        for (auto &e : invocations)
            g[e[0]].push_back(e[1]);

        vector<bool> suspicious(n, false);

        function<void(int)> dfs = [&](int u) {
            suspicious[u] = true;

            for (int v : g[u]) {
                if (!suspicious[v])
                    dfs(v);
            }
        };

        dfs(k);

        // Có cạnh từ ngoài vào trong -> không xóa được
        for (auto &e : invocations) {
            int u = e[0];
            int v = e[1];

            if (!suspicious[u] && suspicious[v]) {
                vector<int> ans;
                for (int i = 0; i < n; i++)
                    ans.push_back(i);
                return ans;
            }
        }

        // Xóa được
        vector<int> ans;
        for (int i = 0; i < n; i++)
            if (!suspicious[i])
                ans.push_back(i);

        return ans;
    }
};