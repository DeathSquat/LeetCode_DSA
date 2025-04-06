#include <stdlib.h>
#include <string.h>

// Comparison function for qsort
int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* largestDivisibleSubset(int* nums, int numsSize, int* returnSize) {
    if (numsSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    // Sort the array
    qsort(nums, numsSize, sizeof(int), cmp);

    int* dp = (int*)malloc(sizeof(int) * numsSize);       // To store subset sizes
    int* prev = (int*)malloc(sizeof(int) * numsSize);     // To trace back elements
    for (int i = 0; i < numsSize; ++i) {
        dp[i] = 1;
        prev[i] = -1;
    }

    int maxIdx = 0;
    for (int i = 1; i < numsSize; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
        if (dp[i] > dp[maxIdx]) {
            maxIdx = i;
        }
    }

    // Reconstruct the subset
    *returnSize = dp[maxIdx];
    int* result = (int*)malloc(sizeof(int) * (*returnSize));
    int k = *returnSize - 1;
    for (int i = maxIdx; i >= 0; i = prev[i]) {
        result[k--] = nums[i];
        if (prev[i] == -1) break;
    }

    free(dp);
    free(prev);
    return result;
}
