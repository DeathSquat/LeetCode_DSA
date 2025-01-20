class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        // Maps to store the positions of each number in the matrix
        unordered_map<int, pair<int, int>> pos;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                pos[mat[i][j]] = {i, j};
            }
        }

        // Row and column paint counters
        vector<int> rowPaint(m, 0);
        vector<int> colPaint(n, 0);

        // Process arr and track the painting
        for (int i = 0; i < arr.size(); ++i) {
            int num = arr[i];
            auto [r, c] = pos[num];

            // Increment the paint counters for the row and column
            rowPaint[r]++;
            colPaint[c]++;

            // Check if a row or column is fully painted
            if (rowPaint[r] == n || colPaint[c] == m) {
                return i;
            }
        }

        return -1; // This should never be reached
    }
};
