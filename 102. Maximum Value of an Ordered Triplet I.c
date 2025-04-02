long long maximumTripletValue(int* nums, int numsSize) {
    long long maxValue = 0;
    int* maxRight = (int*)malloc(numsSize * sizeof(int)); // Store maximum values from right
    
    // Fill maxRight array with maximum values from right side
    maxRight[numsSize - 1] = nums[numsSize - 1];
    for (int i = numsSize - 2; i >= 0; i--) {
        maxRight[i] = (nums[i] > maxRight[i + 1]) ? nums[i] : maxRight[i + 1];
    }
    
    // For each j, keep track of maximum value on left and use maxRight for right
    int maxLeft = nums[0];
    for (int j = 1; j < numsSize - 1; j++) {
        // Calculate triplet value: (maxLeft - nums[j]) * maxRight[j + 1]
        long long current = (long long)(maxLeft - nums[j]) * maxRight[j + 1];
        if (current > maxValue) {
            maxValue = current;
        }
        // Update maxLeft for next iteration
        if (nums[j] > maxLeft) {
            maxLeft = nums[j];
        }
    }
    
    free(maxRight);
    // Return maxValue if positive, 0 otherwise
    return (maxValue > 0) ? maxValue : 0;
}
