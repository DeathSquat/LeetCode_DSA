#include <stdlib.h>

// Custom comparator function for qsort
int compare(const void* a, const void* b) {
    long long diff = *(int*)a - *(int*)b;
    return (diff > 0) - (diff < 0);
}

// Binary search helpers
int lowerBound(int* nums, int start, int end, long long target) {
    int left = start, right = end;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

int upperBound(int* nums, int start, int end, long long target) {
    int left = start, right = end;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] <= target)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

long long countFairPairs(int* nums, int numsSize, int lower, int upper) {
    qsort(nums, numsSize, sizeof(int), compare);  // Sort the array

    long long count = 0;
    for (int i = 0; i < numsSize; ++i) {
        long long minVal = lower - nums[i];
        long long maxVal = upper - nums[i];

        // Find the range in sorted array after index i
        int left = lowerBound(nums, i + 1, numsSize, minVal);
        int right = upperBound(nums, i + 1, numsSize, maxVal);

        count += (right - left);  // Number of valid pairs with i
    }

    return count;
}
