class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        // Use a 1D dp array to save space
        vector<int> dp(triangle.back()); // Start with the last row

        // Bottom-up DP: reduce from second-last row to the top
        for (int i = n - 2; i >= 0; --i) {
            for (int j = 0; j <= i; ++j) {
                dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
            }
        }

        return dp[0]; // The top element contains the result
    }
};
