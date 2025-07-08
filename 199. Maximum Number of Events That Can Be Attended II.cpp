#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        // Sort events by start day to make binary search possible
        sort(events.begin(), events.end());

        int n = events.size();
        // dp[i][j]: max value considering events[i...] with j events remaining
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

        // Create an array of just the start days for binary search
        vector<int> startDays(n);
        for (int i = 0; i < n; ++i) {
            startDays[i] = events[i][0];
        }

        // Fill dp from the end towards beginning
        for (int i = n - 1; i >= 0; --i) {
            for (int j = 1; j <= k; ++j) {
                // Binary search to find the next event that starts after events[i][1]
                int nextIdx = lower_bound(startDays.begin(), startDays.end(), events[i][1] + 1) - startDays.begin();

                // Max of skipping the current event or taking it and moving to the next non-overlapping one
                dp[i][j] = max(dp[i + 1][j], events[i][2] + dp[nextIdx][j - 1]);
            }
        }

        return dp[0][k];
    }
};
