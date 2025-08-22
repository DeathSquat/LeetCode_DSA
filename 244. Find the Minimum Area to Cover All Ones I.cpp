class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        int minRow = rows, maxRow = -1;
        int minCol = cols, maxCol = -1;
        
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 1) {
                    minRow = min(minRow, r);
                    maxRow = max(maxRow, r);
                    minCol = min(minCol, c);
                    maxCol = max(maxCol, c);
                }
            }
        }
        
        return (maxRow - minRow + 1) * (maxCol - minCol + 1);
    }
};
