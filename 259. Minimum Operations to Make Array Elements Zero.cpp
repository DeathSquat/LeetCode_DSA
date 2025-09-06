class Solution {
public:
    // Function to compute prefix sum of steps up to n
    long long prefixSteps(long long n) {
        if (n <= 0) return 0;
        long long total = 0;
        long long base = 1;
        int step = 1;

        while (base <= n) {
            long long next = base * 4 - 1; // range end
            long long high = min(n, next);
            long long count = high - base + 1;
            total += count * step;
            base *= 4;
            step++;
        }
        return total;
    }

    long long minOperations(vector<vector<int>>& queries) {
        long long result = 0;
        for (auto &q : queries) {
            long long l = q[0], r = q[1];
            long long totalSteps = prefixSteps(r) - prefixSteps(l - 1);
            result += (totalSteps + 1) / 2; // ceil(totalSteps / 2)
        }
        return result;
    }
};
