#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<long long> prefixTop(n + 1, 0), prefixBottom(n + 1, 0);

        // Compute prefix sums for both rows
        for (int i = 0; i < n; ++i) {
            prefixTop[i + 1] = prefixTop[i] + grid[0][i];
            prefixBottom[i + 1] = prefixBottom[i] + grid[1][i];
        }

        long long result = LLONG_MAX;

        // Try splitting the grid at each column and calculate the maximum points the second robot can collect
        for (int i = 0; i < n; ++i) {
            // Points above the split
            long long top = prefixTop[n] - prefixTop[i + 1];
            // Points below the split
            long long bottom = prefixBottom[i];

            // The second robot collects the maximum of the two paths
            long long secondRobotPoints = max(top, bottom);
            result = min(result, secondRobotPoints);
        }

        return result;
    }
};
