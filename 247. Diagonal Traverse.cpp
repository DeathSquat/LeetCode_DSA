class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> result;
        result.reserve(m * n);
        
        int row = 0, col = 0;
        bool up = true; // direction flag: true = moving up-right, false = down-left

        while (result.size() < m * n) {
            result.push_back(mat[row][col]);

            if (up) {
                if (col == n - 1) { // right boundary
                    row++;
                    up = false;
                } else if (row == 0) { // top boundary
                    col++;
                    up = false;
                } else {
                    row--;
                    col++;
                }
            } else {
                if (row == m - 1) { // bottom boundary
                    col++;
                    up = true;
                } else if (col == 0) { // left boundary
                    row++;
                    up = true;
                } else {
                    row++;
                    col--;
                }
            }
        }
        return result;
    }
};
