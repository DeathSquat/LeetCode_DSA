class Solution {
public:
    int numOfWays(int n) {
        const int MOD = 1e9 + 7;
        
        long long a = 6; // Type A (ABA)
        long long b = 6; // Type B (ABC)
        
        for (int i = 2; i <= n; i++) {
            long long newA = (a * 3 + b * 2) % MOD;
            long long newB = (a * 2 + b * 2) % MOD;
            a = newA;
            b = newB;
        }
        
        return (a + b) % MOD;
    }
};
