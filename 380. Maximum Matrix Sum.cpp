class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long totalSum = 0;
        int negativeCount = 0;
        int minAbs = INT_MAX;

        for (const auto& row : matrix) {
            for (int val : row) {
                if (val < 0) negativeCount++;
                totalSum += llabs(val);
                minAbs = min(minAbs, abs(val));
            }
        }

        // If odd number of negatives, subtract twice the smallest absolute value
        if (negativeCount % 2 == 1) {
            totalSum -= 2LL * minAbs;
        }

        return totalSum;
    }
};
