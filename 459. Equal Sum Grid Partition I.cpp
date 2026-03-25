class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        long long total = 0;
        
        // Step 1: Calculate total sum
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                total += grid[i][j];
            }
        }
        
        // Step 2: Try horizontal cuts
        long long curr = 0;
        for (int i = 0; i < m - 1; i++) { // ensure bottom part non-empty
            long long rowSum = 0;
            for (int j = 0; j < n; j++) {
                rowSum += grid[i][j];
            }
            curr += rowSum;
            
            if (curr == total - curr) return true;
        }
        
        // Step 3: Compute column sums
        vector<long long> colSum(n, 0);
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                colSum[j] += grid[i][j];
            }
        }
        
        // Step 4: Try vertical cuts
        curr = 0;
        for (int j = 0; j < n - 1; j++) { // ensure right part non-empty
            curr += colSum[j];
            if (curr == total - curr) return true;
        }
        
        return false;
    }
};
