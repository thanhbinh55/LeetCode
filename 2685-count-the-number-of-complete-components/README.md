# Intuition

A connected component is a complete component if every pair of its vertices has an edge between them. For a component with $V$ vertices, that means it must contain exactly:

$$
\frac{V(V-1)}{2}
$$

undirected edges.

So the task becomes:
1. Find each connected component in the graph.
2. Count how many vertices and edges it has.
3. Check whether the edge count matches the complete-graph formula.

# Approach

Use DFS/BFS to traverse the graph component by component:

- `vertices`: number of nodes in the current component
- `edges`: total number of edges encountered in that component
- After DFS finishes, divide `edges` by 2 because each undirected edge is counted twice when exploring from both endpoints
- If

$$
edges = \frac{vertices \times (vertices - 1)}{2}
$$

then this component is complete and contributes to the answer.

# Why this works

A complete graph on $V$ vertices has every possible pair of vertices connected, so the number of undirected edges is fixed. If a connected component has that exact number of edges, then it must be a complete component. Conversely, any complete component will satisfy this condition.

# Complexity

- Time complexity: $O(n + m)$
- Space complexity: $O(n + m)$

Where:
- $n$ is the number of vertices
- $m$ is the number of edges

# Code

```cpp
class Solution {
public:
    vector<vector<int>> graph;
    vector<bool> visited;

    void dfs(int u, int &vertices, int &edges) {
        visited[u] = true;
        for (int v : graph[u]) {
            if (!visited[v]) {
                dfs(v, vertices, edges);
            }
        }
        vertices++;
        edges += graph[u].size();
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        visited.assign(n, false);
        graph.assign(n, {});

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int vertices = 0;
                int edgesCount = 0;
                dfs(i, vertices, edgesCount);
                edgesCount /= 2;

                if (edgesCount == vertices * (vertices - 1) * 0.5) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
```

# Results

- **Test cases:** 3356/3356 cases passed
- Runtime: 38 ms (beats 73.27 % of C++ submissions)
- Memory usage: 128.1 MB (beats 76.73 % of C++ submissions)

