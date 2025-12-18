class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        int half = k / 2;

        long long baseProfit = 0;
        for (int i = 0; i < n; i++) {
            baseProfit += 1LL * strategy[i] * prices[i];
        }

        // A[i] = gain if we turn strategy[i] into 0
        // B[i] = gain if we turn strategy[i] into 1
        vector<long long> A(n), B(n);
        for (int i = 0; i < n; i++) {
            A[i] = -1LL * strategy[i] * prices[i];
            B[i] = 1LL * (1 - strategy[i]) * prices[i];
        }

        // Prefix sums
        vector<long long> preA(n + 1, 0), preB(n + 1, 0);
        for (int i = 0; i < n; i++) {
            preA[i + 1] = preA[i] + A[i];
            preB[i + 1] = preB[i] + B[i];
        }

        long long bestDelta = 0;

        // Sliding window
        for (int l = 0; l + k <= n; l++) {
            long long firstHalf =
                preA[l + half] - preA[l];
            long long secondHalf =
                preB[l + k] - preB[l + half];

            bestDelta = max(bestDelta, firstHalf + secondHalf);
        }

        return baseProfit + bestDelta;
    }
};
