class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);

        // Build the graph
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }

        // DP array to store frequency of each color per node
        vector<vector<int>> colorCount(n, vector<int>(26, 0));

        // Queue for topological sorting
        queue<int> q;

        // Initialize queue with nodes having 0 indegree
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
                colorCount[i][colors[i] - 'a'] = 1;
            }
        }

        int visited = 0, result = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            visited++;

            for (int neighbor : graph[node]) {
                for (int c = 0; c < 26; ++c) {
                    colorCount[neighbor][c] = max(
                        colorCount[neighbor][c],
                        colorCount[node][c] + (colors[neighbor] - 'a' == c ? 1 : 0)
                    );
                }

                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }

            result = max(result, *max_element(colorCount[node].begin(), colorCount[node].end()));
        }

        return visited == n ? result : -1;
    }
};
