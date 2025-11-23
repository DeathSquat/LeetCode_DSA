class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        // dp[r] = maximum sum with remainder r
        vector<int> dp(3, 0);
        
        for (int x : nums) {
            vector<int> cur = dp;  // snapshot before update
            for (int r = 0; r < 3; r++) {
                int newSum = cur[r] + x;
                dp[newSum % 3] = max(dp[newSum % 3], newSum);
            }
        }
        
        return dp[0];
    }
};
