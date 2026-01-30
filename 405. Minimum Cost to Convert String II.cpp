class Solution {
public:
    long long minimumCost(string source, string target,
                          vector<string>& original,
                          vector<string>& changed,
                          vector<int>& cost) {
        const long long INF = 1e18;
        int n = source.size();
        
        // Collect all unique strings
        unordered_map<string, int> id;
        vector<string> all;
        
        auto getId = [&](const string& s) {
            if (!id.count(s)) {
                id[s] = all.size();
                all.push_back(s);
            }
            return id[s];
        };
        
        for (int i = 0; i < original.size(); i++) {
            getId(original[i]);
            getId(changed[i]);
        }
        
        int m = all.size();
        vector<vector<long long>> dist(m, vector<long long>(m, INF));
        
        for (int i = 0; i < m; i++) dist[i][i] = 0;
        
        for (int i = 0; i < original.size(); i++) {
            int u = getId(original[i]);
            int v = getId(changed[i]);
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }
        
        // Floyd–Warshall
        for (int k = 0; k < m; k++) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < m; j++) {
                    if (dist[i][k] < INF && dist[k][j] < INF) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
        
        vector<long long> dp(n + 1, INF);
        dp[0] = 0;
        
        for (int i = 0; i < n; i++) {
            if (dp[i] == INF) continue;
            
            // Character match
            if (source[i] == target[i]) {
                dp[i + 1] = min(dp[i + 1], dp[i]);
            }
            
            // Substring replacements
            for (int j = 0; j < m; j++) {
                int len = all[j].size();
                if (i + len > n) continue;
                
                if (source.compare(i, len, all[j]) != 0) continue;
                
                for (int k = 0; k < m; k++) {
                    if (dist[j][k] == INF) continue;
                    if (all[k].size() != len) continue;
                    
                    if (target.compare(i, len, all[k]) == 0) {
                        dp[i + len] = min(dp[i + len], dp[i] + dist[j][k]);
                    }
                }
            }
        }
        
        return dp[n] == INF ? -1 : dp[n];
    }
};
