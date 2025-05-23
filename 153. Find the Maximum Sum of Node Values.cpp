class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long totalSum = 0;
        int beneficialCount = 0;
        int minDiff = INT_MAX;

        for (int num : nums) {
            int xored = num ^ k;
            if (xored > num) {
                totalSum += xored;
                beneficialCount++;
            } else {
                totalSum += num;
            }
            minDiff = min(minDiff, abs(num - xored));
        }

        // If the number of beneficial XORs is even, we are done
        // Else, we need to revert one operation (the least harmful one)
        if (beneficialCount % 2 != 0) {
            totalSum -= minDiff;
        }

        return totalSum;
    }
};
