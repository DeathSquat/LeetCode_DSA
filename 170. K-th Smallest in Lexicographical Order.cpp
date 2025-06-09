class Solution {
public:
    // Helper function to count numbers with given prefix in [1, n]
    long long countSteps(long long n, long long curr, long long next) {
        long long steps = 0;
        while (curr <= n) {
            steps += min(n + 1, next) - curr;
            curr *= 10;
            next *= 10;
        }
        return steps;
    }

    int findKthNumber(int n, int k) {
        int curr = 1;
        k = k - 1; // since we start from 1

        while (k > 0) {
            long long steps = countSteps(n, curr, curr + 1);
            if (steps <= k) {
                // Move to next prefix (i.e., skip current subtree)
                curr++;
                k -= steps;
            } else {
                // Go deeper in current subtree
                curr *= 10;
                k -= 1;
            }
        }

        return curr;
    }
};
