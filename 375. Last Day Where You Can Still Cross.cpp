class Solution {
public:
    vector<int> parent, rank;
    int ROWS, COLS;
    int TOP, BOTTOM;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;
        if (rank[a] < rank[b]) swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b]) rank[a]++;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        ROWS = row;
        COLS = col;

        int total = row * col;
        TOP = total;
        BOTTOM = total + 1;

        parent.resize(total + 2);
        rank.resize(total + 2, 0);

        for (int i = 0; i < total + 2; i++)
            parent[i] = i;

        vector<vector<int>> grid(row, vector<int>(col, 1)); // 1 = water
        vector<int> dir = {0, 1, 0, -1, 0};

        for (int day = cells.size() - 1; day >= 0; day--) {
            int r = cells[day][0] - 1;
            int c = cells[day][1] - 1;
            grid[r][c] = 0; // make land

            int idx = r * col + c;

            if (r == 0) unite(idx, TOP);
            if (r == row - 1) unite(idx, BOTTOM);

            for (int d = 0; d < 4; d++) {
                int nr = r + dir[d];
                int nc = c + dir[d + 1];
                if (nr >= 0 && nr < row && nc >= 0 && nc < col && grid[nr][nc] == 0) {
                    int nidx = nr * col + nc;
                    unite(idx, nidx);
                }
            }

            if (find(TOP) == find(BOTTOM))
                return day;
        }

        return 0;
    }
};
