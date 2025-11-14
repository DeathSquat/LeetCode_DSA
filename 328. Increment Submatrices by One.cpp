class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        // Initialize the matrix with zeroes
        vector<vector<int>> mat(n, vector<int>(n, 0));

        // Process each query
        for (const auto& query : queries) {
            int row1 = query[0], col1 = query[1];
            int row2 = query[2], col2 = query[3];
            
            // Apply the difference array technique
            mat[row1][col1] += 1;  // Start adding 1 at (row1, col1)
            if (col2 + 1 < n) mat[row1][col2 + 1] -= 1;  // Stop adding 1 in the horizontal direction
            if (row2 + 1 < n) mat[row2 + 1][col1] -= 1;  // Stop adding 1 in the vertical direction
            if (row2 + 1 < n && col2 + 1 < n) mat[row2 + 1][col2 + 1] += 1;  // Correct the bottom-right corner
        }
        
        // Accumulate the values to finalize the matrix
        // First, process row-wise prefix sum
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < n; ++j) {
                mat[i][j] += mat[i][j - 1];
            }
        }

        // Then, process column-wise prefix sum
        for (int j = 0; j < n; ++j) {
            for (int i = 1; i < n; ++i) {
                mat[i][j] += mat[i - 1][j];
            }
        }

        return mat;
    }
};
