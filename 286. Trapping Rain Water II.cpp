#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size(), n = heightMap[0].size();
        if (m <= 2 || n <= 2) return 0;  // no space to trap water

        // Min-heap: stores (height, x, y)
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // Push all boundary cells into the priority queue
        for (int i = 0; i < m; i++) {
            pq.push({heightMap[i][0], i, 0});
            pq.push({heightMap[i][n-1], i, n-1});
            visited[i][0] = visited[i][n-1] = true;
        }
        for (int j = 0; j < n; j++) {
            pq.push({heightMap[0][j], 0, j});
            pq.push({heightMap[m-1][j], m-1, j});
            visited[0][j] = visited[m-1][j] = true;
        }

        int water = 0;
        vector<int> dirs = {0,1,0,-1,0};

        while (!pq.empty()) {
            auto cur = pq.top(); pq.pop();
            int h = cur[0], x = cur[1], y = cur[2];

            // Explore 4 directions
            for (int d = 0; d < 4; d++) {
                int nx = x + dirs[d], ny = y + dirs[d+1];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || visited[nx][ny]) 
                    continue;

                visited[nx][ny] = true;
                // If neighbor lower, water trapped = h - heightMap[nx][ny]
                water += max(0, h - heightMap[nx][ny]);
                // Push new cell with effective height (max of its own height or boundary water level)
                pq.push({max(h, heightMap[nx][ny]), nx, ny});
            }
        }

        return water;
    }
};
