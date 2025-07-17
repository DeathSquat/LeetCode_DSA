class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<unordered_map<int, int>> dp(n);
        int maxLen = 1;

        for (int i = 0; i < n; ++i) {
            // Every single element can start a valid sequence of length 1
            dp[i][0] = 1;
            for (int j = 0; j < i; ++j) {
                int mod = (nums[j] + nums[i]) % k;
                int prevLen = dp[j].count(mod) ? dp[j][mod] : 1;
                dp[i][mod] = max(dp[i][mod], prevLen + 1);
                maxLen = max(maxLen, dp[i][mod]);
            }
        }
        return maxLen;
    }
};
