class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        // dp[i][j] will store the maximum number of strings we can form with at most i 0's and j 1's
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        for (const string& str : strs) {
            // Count the number of 0's and 1's in the current string
            int count0 = 0, count1 = 0;
            for (char c : str) {
                if (c == '0') count0++;
                else count1++;
            }
            
            // Update the dp table in reverse order to avoid overwriting the results of this round
            for (int i = m; i >= count0; i--) {
                for (int j = n; j >= count1; j--) {
                    dp[i][j] = max(dp[i][j], dp[i - count0][j - count1] + 1);
                }
            }
        }
        
        // The answer is the value in dp[m][n], which represents the largest subset we can form
        return dp[m][n];
    }
};
