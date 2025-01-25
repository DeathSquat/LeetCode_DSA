class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> reverseGraph(n);
        vector<int> indegree(n, 0);

        // Build the reverse graph and compute indegrees
        for (int i = 0; i < n; ++i) {
            for (int neighbor : graph[i]) {
                reverseGraph[neighbor].push_back(i);
                indegree[i]++;
            }
        }

        // Queue for nodes with indegree 0 (terminal nodes in the reverse graph)
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // Process nodes with indegree 0
        vector<int> safeNodes;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);

            for (int neighbor : reverseGraph[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // Sort the safe nodes in ascending order
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};
