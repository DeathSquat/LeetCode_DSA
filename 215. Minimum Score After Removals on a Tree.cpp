class Solution {
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> graph(n);
        for (auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        vector<int> xorSubtree(n, 0);
        vector<int> in(n), out(n);
        int time = 0;

        // DFS to compute subtree XORs and in/out time
        function<void(int, int)> dfs = [&](int node, int parent) {
            xorSubtree[node] = nums[node];
            in[node] = time++;
            for (int child : graph[node]) {
                if (child != parent) {
                    dfs(child, node);
                    xorSubtree[node] ^= xorSubtree[child];
                }
            }
            out[node] = time++;
        };

        dfs(0, -1);  // root the tree at 0
        int totalXor = xorSubtree[0];
        int res = INT_MAX;

        // Helper to check if u is ancestor of v
        auto isAncestor = [&](int u, int v) {
            return in[u] < in[v] && out[v] < out[u];
        };

        // Try all pairs of nodes (each corresponds to edge cuts)
        for (int i = 1; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int x = xorSubtree[i];
                int y = xorSubtree[j];
                int z;

                if (isAncestor(i, j)) {
                    z = totalXor ^ x;
                    x ^= y;
                } else if (isAncestor(j, i)) {
                    z = totalXor ^ y;
                    y ^= x;
                } else {
                    z = totalXor ^ x ^ y;
                }

                int mx = max({x, y, z});
                int mn = min({x, y, z});
                res = min(res, mx - mn);
            }
        }

        return res;
    }
};
