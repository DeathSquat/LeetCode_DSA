#include <stdbool.h>
#include <stdlib.h>

bool canPartition(int* nums, int numsSize) {
    int totalSum = 0;
    for (int i = 0; i < numsSize; i++) {
        totalSum += nums[i];
    }

    // If totalSum is odd, can't split into two equal subsets
    if (totalSum % 2 != 0) {
        return false;
    }

    int target = totalSum / 2;
    bool* dp = (bool*)calloc(target + 1, sizeof(bool));
    dp[0] = true;  // Base case: subset with sum 0 is always possible

    for (int i = 0; i < numsSize; i++) {
        int num = nums[i];
        for (int j = target; j >= num; j--) {
            dp[j] = dp[j] || dp[j - num];
        }
    }

    bool result = dp[target];
    free(dp);
    return result;
}
