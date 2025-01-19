#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();
        if (m <= 2 || n <= 2) return 0; // Cannot trap water if the grid is too small

        // Priority queue to store cells (height, row, col)
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

        // Visited matrix to track processed cells
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // Add boundary cells to the priority queue
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    pq.push({heightMap[i][j], {i, j}});
                    visited[i][j] = true;
                }
            }
        }

        // Directions for moving up, down, left, and right
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int waterTrapped = 0;

        while (!pq.empty()) {
            auto [height, cell] = pq.top();
            pq.pop();
            int row = cell.first;
            int col = cell.second;

            // Explore neighbors
            for (auto [dr, dc] : directions) {
                int newRow = row + dr;
                int newCol = col + dc;

                // Skip if the neighbor is out of bounds or already visited
                if (newRow < 0 || newRow >= m || newCol < 0 || newCol >= n || visited[newRow][newCol]) {
                    continue;
                }

                // Calculate the water trapped at the current cell
                waterTrapped += max(0, height - heightMap[newRow][newCol]);

                // Update the neighbor's height to the max of its own height or the current height
                pq.push({max(height, heightMap[newRow][newCol]), {newRow, newCol}});
                visited[newRow][newCol] = true;
            }
        }

        return waterTrapped;
    }
};
