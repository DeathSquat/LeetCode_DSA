class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();       // number of rows
        int n = grid[0].size();    // number of columns
        int count = 0;
        int row = 0;
        int col = n - 1;  // Start from the top-right corner
        
        // Traverse the matrix from top-right corner
        while (row < m && col >= 0) {
            if (grid[row][col] < 0) {
                // If current number is negative, all numbers below it in this column are negative
                count += (m - row);  // Count all elements below in the current column
                col--;  // Move left
            } else {
                row++;  // Move down
            }
        }
        
        return count;
    }
};
