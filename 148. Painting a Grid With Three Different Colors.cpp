class Solution {
public:
    const int MOD = 1e9 + 7;
    
    vector<vector<int>> generateValidStates(int m) {
        vector<vector<int>> validStates;
        vector<int> colors(m);
        
        function<void(int)> dfs = [&](int row) {
            if (row == m) {
                validStates.push_back(colors);
                return;
            }
            for (int c = 0; c < 3; ++c) {
                if (row == 0 || colors[row - 1] != c) {
                    colors[row] = c;
                    dfs(row + 1);
                }
            }
        };
        
        dfs(0);
        return validStates;
    }
    
    bool isCompatible(const vector<int>& a, const vector<int>& b) {
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] == b[i]) return false;
        }
        return true;
    }

    int colorTheGrid(int m, int n) {
        auto validStates = generateValidStates(m);
        int stateCount = validStates.size();
        
        // Map state vector to index
        unordered_map<string, int> stateIndex;
        for (int i = 0; i < stateCount; ++i) {
            string key;
            for (int c : validStates[i]) key += to_string(c);
            stateIndex[key] = i;
        }

        // Compatibility map
        vector<vector<int>> compat(stateCount);
        for (int i = 0; i < stateCount; ++i) {
            for (int j = 0; j < stateCount; ++j) {
                if (isCompatible(validStates[i], validStates[j])) {
                    compat[i].push_back(j);
                }
            }
        }

        // DP
        vector<int> dp(stateCount, 1);  // First column
        for (int col = 1; col < n; ++col) {
            vector<int> new_dp(stateCount, 0);
            for (int i = 0; i < stateCount; ++i) {
                for (int j : compat[i]) {
                    new_dp[j] = (new_dp[j] + dp[i]) % MOD;
                }
            }
            dp = new_dp;
        }

        int result = 0;
        for (int count : dp) {
            result = (result + count) % MOD;
        }

        return result;
    }
};
