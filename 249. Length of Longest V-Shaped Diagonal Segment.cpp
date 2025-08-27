class Solution {
public:
    int n, m;
    vector<vector<int>> grid;
    // Directions: ↘, ↙, ↖, ↗
    int dx[4] = {1, 1, -1, -1};
    int dy[4] = {1, -1, -1, 1};
    // Clockwise next dir
    int clockwise[4] = {1, 2, 3, 0};
    // DP cache: dp[x][y][dir][turn][expected]
    int dp[501][501][4][2][3];

    int dfs(int x, int y, int dir, int turn, int expected) {
        if (x < 0 || y < 0 || x >= n || y >= m) return 0;
        if (grid[x][y] != expected) return 0;

        int &res = dp[x][y][dir][turn][expected];
        if (res != -1) return res;
        res = 1; // count current cell

        int nextVal;
        if (expected == 1) nextVal = 2;
        else if (expected == 2) nextVal = 0;
        else nextVal = 2;

        // Continue straight
        int nx = x + dx[dir], ny = y + dy[dir];
        res = max(res, 1 + dfs(nx, ny, dir, turn, nextVal));

        // Try clockwise turn (if not used)
        if (!turn) {
            int ndir = clockwise[dir];
            nx = x + dx[ndir]; ny = y + dy[ndir];
            res = max(res, 1 + dfs(nx, ny, ndir, 1, nextVal));
        }

        return res;
    }

    int lenOfVDiagonal(vector<vector<int>>& g) {
        grid = g;
        n = grid.size(); 
        m = grid[0].size();

        memset(dp, -1, sizeof(dp));
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    for (int d = 0; d < 4; d++) {
                        ans = max(ans, dfs(i, j, d, 0, 1));
                    }
                }
            }
        }
        return ans;
    }
};
