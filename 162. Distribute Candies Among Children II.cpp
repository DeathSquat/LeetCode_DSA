class Solution {
public:
    long long nCk(long long n, long long k) {
        if (k < 0 || k > n) return 0;
        if (k == 0 || k == n) return 1;
        long long res = 1;
        for (long long i = 1; i <= k; ++i) {
            res *= (n - i + 1);
            res /= i;
        }
        return res;
    }

    long long distributeCandies(int n, int limit) {
        // Total solutions without limit
        long long total = nCk(n + 2, 2);

        // Subtract cases where at least one child gets more than limit
        long long sub = 0;
        for (int i = 1; i <= 3; ++i) {
            long long sign = (i % 2 == 1) ? -1 : 1;
            // Choose i variables to exceed limit
            long long waysToChoose = nCk(3, i);
            long long remaining = n - (limit + 1) * i;
            if (remaining >= 0) {
                long long combinations = nCk(remaining + 2, 2);
                sub += sign * waysToChoose * combinations;
            }
        }

        return total + sub;
    }
};
