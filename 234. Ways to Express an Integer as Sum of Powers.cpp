class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<int> powers;
    vector<vector<int>> dp;

    int solve(int idx, int sum, int n) {
        if (sum == n) return 1;
        if (sum > n || idx >= powers.size()) return 0;
        if (dp[idx][sum] != -1) return dp[idx][sum];

        // Option 1: Take current power
        int take = solve(idx + 1, sum + powers[idx], n) % MOD;

        // Option 2: Skip current power
        int skip = solve(idx + 1, sum, n) % MOD;

        return dp[idx][sum] = (take + skip) % MOD;
    }

    int numberOfWays(int n, int x) {
        // Precompute powers i^x <= n
        for (int i = 1; pow(i, x) <= n; i++) {
            powers.push_back((int)pow(i, x));
        }

        dp.assign(powers.size(), vector<int>(n + 1, -1));
        return solve(0, 0, n);
    }
};
