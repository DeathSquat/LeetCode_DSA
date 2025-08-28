class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<int, vector<int>> diagMap;

        // Collect diagonals
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                diagMap[i - j].push_back(grid[i][j]);
            }
        }

        // Sort diagonals
        for (auto& [key, vec] : diagMap) {
            if (key >= 0) {
                // bottom-left (including main) → non-increasing
                sort(vec.begin(), vec.end(), greater<int>());
            } else {
                // top-right → non-decreasing
                sort(vec.begin(), vec.end());
            }
        }

        // Put back sorted values
        unordered_map<int, int> index;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int key = i - j;
                grid[i][j] = diagMap[key][index[key]++];
            }
        }

        return grid;
    }
};
