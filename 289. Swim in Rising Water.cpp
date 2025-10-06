#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        
        // Min-heap: {time, x, y}
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({grid[0][0], 0, 0});
        
        while (!pq.empty()) {
            auto top = pq.top(); pq.pop();
            int t = top[0], x = top[1], y = top[2];
            
            if (x == n-1 && y == n-1) return t;
            if (visited[x][y]) continue;
            visited[x][y] = true;
            
            for (auto& d : dirs) {
                int nx = x + d[0];
                int ny = y + d[1];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny]) {
                    pq.push({max(t, grid[nx][ny]), nx, ny});
                }
            }
        }
        
        return -1; // should never reach here
    }
};
