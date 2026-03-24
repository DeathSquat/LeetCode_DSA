class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        const int MOD = 12345;
        
        int n = grid.size();
        int m = grid[0].size();
        int total = n * m;
        
        vector<int> arr;
        arr.reserve(total);
        
        // Flatten the grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                arr.push_back(grid[i][j] % MOD);
            }
        }
        
        vector<int> prefix(total, 1), suffix(total, 1);
        
        // Build prefix
        for (int i = 1; i < total; i++) {
            prefix[i] = (prefix[i - 1] * arr[i - 1]) % MOD;
        }
        
        // Build suffix
        for (int i = total - 2; i >= 0; i--) {
            suffix[i] = (suffix[i + 1] * arr[i + 1]) % MOD;
        }
        
        // Build result
        vector<vector<int>> result(n, vector<int>(m));
        
        for (int i = 0; i < total; i++) {
            int val = (prefix[i] * suffix[i]) % MOD;
            result[i / m][i % m] = val;
        }
        
        return result;
    }
};
