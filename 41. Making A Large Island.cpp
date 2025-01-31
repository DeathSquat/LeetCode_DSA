class Solution {
public:
    int n;
    vector<int> parent, size;
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }
    
    void unite(int x, int y) {
        int rootX = find(x), rootY = find(y);
        if (rootX != rootY) {
            if (size[rootX] < size[rootY]) {
                swap(rootX, rootY);
            }
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
        }
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        parent.resize(n * n);
        size.resize(n * n, 1);
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        // Initialize union-find structure
        for (int i = 0; i < n * n; i++) {
            parent[i] = i;
        }

        // Step 1: Connect existing islands using union-find
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int index = i * n + j;
                    for (auto dir : directions) {
                        int ni = i + dir[0], nj = j + dir[1];
                        if (ni >= 0 && ni < n && nj >= 0 && nj < n && grid[ni][nj] == 1) {
                            unite(index, ni * n + nj);
                        }
                    }
                }
            }
        }
        
        // Step 2: Calculate the largest island
        int maxIsland = 0;
        unordered_map<int, int> areaMap;
        
        for (int i = 0; i < n * n; i++) {
            if (parent[i] == i) { // Root node
                areaMap[i] = size[i];
                maxIsland = max(maxIsland, size[i]);
            }
        }
        
        // Step 3: Try changing each '0' to '1' and check the potential maximum island size
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> connectedIslands;
                    int newSize = 1; // The new cell itself
                    for (auto dir : directions) {
                        int ni = i + dir[0], nj = j + dir[1];
                        if (ni >= 0 && ni < n && nj >= 0 && nj < n && grid[ni][nj] == 1) {
                            int root = find(ni * n + nj);
                            if (connectedIslands.find(root) == connectedIslands.end()) {
                                newSize += areaMap[root];
                                connectedIslands.insert(root);
                            }
                        }
                    }
                    maxIsland = max(maxIsland, newSize);
                }
            }
        }
        
        return maxIsland;
    }
};
