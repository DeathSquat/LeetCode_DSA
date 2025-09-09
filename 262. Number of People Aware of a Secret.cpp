class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MOD = 1e9 + 7;
        
        vector<long long> dp(n + 1, 0); // dp[i] = number of people who learn the secret on day i
        dp[1] = 1; // on day 1, one person knows the secret
        
        long long share = 0; // number of people who can share the secret
        
        for (int day = 2; day <= n; day++) {
            // People who can start sharing today (delay days ago)
            if (day - delay >= 1) {
                share = (share + dp[day - delay]) % MOD;
            }
            
            // People who forget the secret today (forget days ago)
            if (day - forget >= 1) {
                share = (share - dp[day - forget] + MOD) % MOD;
            }
            
            // The number of new people who learn the secret today
            dp[day] = share;
        }
        
        // Sum of people who still remember the secret at day n
        long long ans = 0;
        for (int day = n - forget + 1; day <= n; day++) {
            if (day >= 1) ans = (ans + dp[day]) % MOD;
        }
        
        return (int)ans;
    }
};
